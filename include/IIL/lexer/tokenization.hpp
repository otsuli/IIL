#pragma once
#include <iostream>
#include <vector>
#include "tokens.hpp"
class tokenizing {
    std::string source;
    unsigned int line = 1;
    unsigned int column = 1;

    [[nodiscard]] std::vector<std::string> splitString();

   public:
    [[nodiscard]] std::vector<Token> tokenize(std::string& sourceCode);
};