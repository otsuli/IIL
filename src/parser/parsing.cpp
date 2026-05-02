#include "parsing.hpp"
#include <memory>
#include "AST.hpp"
#include "helperRoutines.hpp"

static std::unique_ptr<ExprAST> ParseNumberExpr(){
    helperRoutines routines; 
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    routines.getNextToken();
    return std::move(Result);
}