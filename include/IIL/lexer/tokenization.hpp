#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "tokens.hpp"

class tokenizing {
    unsigned int line = 1;
    unsigned int column = 1;

    [[nodiscard]] std::vector<std::string> splitString(std::string& source);

   public:
    [[nodiscard]] std::vector<Token> tokenize(std::string& sourceCode);
};