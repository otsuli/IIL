#pragma once
#include <memory>
#include "parser/parse.hpp"
#include <iostream>
namespace errorRoutines
{
    std::unique_ptr<ExprAST> LogError(const char *Str);
    std::unique_ptr<PrototypeAST> LogErrorP(const char *Str);
}