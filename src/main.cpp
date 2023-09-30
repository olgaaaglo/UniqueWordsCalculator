#include <iostream>
#include <iomanip>
#include "UniqueWordsCalculator.hpp"

int main(int argc, char** argv)
{
    clock_t startTime, endTime;
    startTime = clock();

    if (argc == 2)
    {
        UniqueWordsCalculator uniqueWordsCalculator{argv[1]};
        std::cout << "Number of unique words: " << uniqueWordsCalculator.calculateNumOfUniqueWords() << std::endl;
    }
    else
    {
        std::cout << "Provide the name of the file to read as a programme argument." << std::endl;
    }
    endTime = clock();
    double time_taken = double(endTime - startTime) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by programme: " << std::fixed
         << time_taken << std::setprecision(5) << "sec" << std::endl;
}