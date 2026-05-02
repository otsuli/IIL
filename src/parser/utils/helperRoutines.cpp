#include "helperRoutines.hpp"
#include "../../../include/IIL/lexer/tokens.hpp"
#include <iostream>
#include <vector>

Token helperRoutines::getNextToken(std::vector<Token> tokens)
{
    return CurTok = tokens.front();
}