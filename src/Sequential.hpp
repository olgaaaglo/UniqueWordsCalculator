#pragma once
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <algorithm>
#include <iterator>

int sequential(std::string fileName)
{
    std::ifstream file(fileName);
    std::string text;
    std::set<std::string> tokens;
    while (std::getline(file, text)) 
    {
        std::istringstream iss(text);
        std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::inserter(tokens, tokens.begin()));
    }
    file.close();
    return tokens.size();
}
