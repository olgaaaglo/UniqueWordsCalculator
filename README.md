Files:
A class to calculate number of unique words is defined in UniqueWordsCalculator.hpp and UniqueWordsCalculator.cpp files. Example usage is in main.cpp file.
Sequential.hpp and Sequential.cpp are a simple programme calculating number of unique words to check if results are correct.
TestUniqueWordsCalculator.cpp is a test comparing results for both methods for some example files.

Commands for example UniqueWordsCalculator run:
g++ main.cpp UniqueWordsCalculator.cpp -o main
main.exe [filename] / ./main.out [filename]

Commands for Sequential run:
g++ Sequential.cpp -o sequential
sequential.exe [filename] / ./sequential.out [filename]

Commands for TestUniqueWordsCalculator run:
g++ TestUniqueWordsCalculator.cpp UniqueWordsCalculator.cpp -o TestUniqueWordsCalculator
TestUniqueWordsCalculator.exe / ./TestUniqueWordsCalculator.out