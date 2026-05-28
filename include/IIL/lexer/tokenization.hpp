#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "tokens.hpp"

class tokenizing {
    unsigned int line = 1;
    unsigned int column = 1;

    [[nodiscard]] std::vector<std::string> splitString(
        const std::unique_ptr<std::string>& source);

   public:
    [[nodiscard]] std::vector<Token> tokenize(
        const std::unique_ptr<std::string>& sourceCode);
};