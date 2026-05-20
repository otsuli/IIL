#pragma once
#include <iostream>
#include <vector>
#include "errors/lexerError.hpp"
#include "tokens.hpp"
class tokenizing {
   public:
    std::vector<LexerError> errors;

   private:
    std::string source;
    unsigned int line = 1;
    unsigned int column = 1;

    [[nodiscard]] std::vector<std::string> splitString();

   public:
    [[nodiscard]] std::vector<Token> tokenize(std::string& sourceCode);
};