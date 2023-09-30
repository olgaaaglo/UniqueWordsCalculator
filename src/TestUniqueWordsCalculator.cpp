#include <iostream>
#include <iomanip>
#include "UniqueWordsCalculator.hpp"
#include "Sequential.hpp"

void printTime(const clock_t& startTime, const clock_t& endTime)
{
    double time_taken = double(endTime - startTime) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by programme: " << std::fixed
        << time_taken << std::setprecision(5) << "sec" << std::endl;
}

void testUniqueWordsCalculator(std::string fileName)
{
    clock_t startTime, endTime;
    startTime = clock();

    UniqueWordsCalculator uniqueWordsCalculator{fileName};
    int uniqueWords = uniqueWordsCalculator.calculateNumOfUniqueWords();
    std::cout << "Number of unique words: " << uniqueWords << std::endl;

    endTime = clock();
    printTime(startTime, endTime);
    startTime = clock();

    int expectedUniqueWords = sequential(fileName);
    std::cout << "Number of unique words: " << expectedUniqueWords << std::endl;

    endTime = clock();
    printTime(startTime, endTime);

    if (uniqueWords == expectedUniqueWords)
    {
        std::cout << "Test passed" << std::endl << std::endl;
    }
    else
    {
        std::cout << "Test failed" << std::endl << std::endl; 
    }
}

int main()
{
    testUniqueWordsCalculator("../example_files/wordsTest.txt");
    testUniqueWordsCalculator("../example_files/wordsTest2.txt");
    testUniqueWordsCalculator("../example_files/lorem.txt");
    // testUniqueWordsCalculator("../example_files/words1M.txt");
}