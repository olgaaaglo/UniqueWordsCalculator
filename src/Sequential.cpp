#include <iostream>
#include <iomanip>
#include "Sequential.hpp"

int main(int argc, char** argv)
{
    clock_t start, end;
    start = clock();
    if (argc == 2)
    {
        std::cout << "Number of unique words: " << sequential(argv[1]) << std::endl;
    }
    else
    {
        std::cout << "Provide the name of the file to read as programme argument." << std::endl;
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by programme: " << std::fixed
         << time_taken << std::setprecision(5) << "sec" << std::endl;
}