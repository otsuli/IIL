#include "include/errorRoutines.hpp"
#include <memory>
#include <iostream>
#include "parser/parse.hpp"

std::unique_ptr<ExprAST> errorRoutines::LogError(const char *Str)
{
    fprintf(stderr, "Error: %s\n", Str);
    return nullptr; 
} 

std::unique_ptr<PrototypeAST> errorRoutines::LogErrorP (const char *Str)
{
    errorRoutines::LogError(Str); 
    return nullptr; 
}