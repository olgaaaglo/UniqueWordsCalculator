#pragma once

#include <set>
#include <thread>
#include <vector>
#include <future>

class UniqueWordsCalculator
{
public:
    UniqueWordsCalculator(std::string name) : fileName{name} {}
    int calculateNumOfUniqueWords();

private:
    void readFile();
    void createThreads();
    void insertUnique(const std::vector<std::string>& constLines, int start, int end, std::promise<std::set<std::string>> &&tokens);
    int getNumOfUniqueWords();

    std::string fileName;
    std::vector<std::thread> threads;
    std::vector<std::future<std::set<std::string>>> futures;
    std::vector<std::string> lines;
};