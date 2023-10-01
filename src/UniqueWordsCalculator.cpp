#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <execution>
#include "UniqueWordsCalculator.hpp"

int UniqueWordsCalculator::calculateNumOfUniqueWords()
{
    readFile();
    createThreads();

    return getNumOfUniqueWords();
}

void UniqueWordsCalculator::readFile()
{
    std::ifstream file{fileName};
    std::string text;
    while (std::getline(file, text)) 
    {
        lines.push_back(text);
    }
    file.close();
}

void UniqueWordsCalculator::createThreads()
{
    int numOfLinesForThread = lines.size() / 5;
    if (numOfLinesForThread == 0)
    {
        numOfLinesForThread = 1;
    }

    int i = 0;
    while (numOfLinesForThread * i < lines.size())
    {
        std::promise<std::set<std::string>> tokens;
        futures.push_back(tokens.get_future());

        int start = numOfLinesForThread * i;
        int end = start + numOfLinesForThread;

        threads.push_back(std::thread(&UniqueWordsCalculator::insertUnique, this, lines, start, end, std::move(tokens)));
        ++i;
    }
}

void UniqueWordsCalculator::insertUnique(const std::vector<std::string>& constLines, int start, int end, std::promise<std::set<std::string>> &&tokens)
{
    std::set<std::string> tokensInOneThread;
    for (int i = start; i < end; ++i)
    {
        try 
        {
            std::istringstream stream(constLines[i]);
            std::copy(std::execution::par,
                std::istream_iterator<std::string>(stream),
                std::istream_iterator<std::string>(),
                std::inserter(tokensInOneThread, tokensInOneThread.begin()));
        }
        catch (std::exception e)
        {
            // std::cout << "e: " << e.what() << std::endl;
        }
    }
    tokens.set_value(tokensInOneThread);
}

int UniqueWordsCalculator::getNumOfUniqueWords()
{
    std::set<std::string> tokensFinal;
    for (int j = 0; j < threads.size(); ++j) 
    {
        threads[j].join();
        auto f = futures[j].get();
        std::copy(std::execution::par,
            f.begin(),
            f.end(),
            std::inserter(tokensFinal, tokensFinal.begin()));
    }
    return tokensFinal.size();
}
