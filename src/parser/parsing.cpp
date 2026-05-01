#include "../../include/IIL/parser/parsing.hpp"
#include <memory>
#include "../../include/IIL/parser/AST.hpp"
#include "utils/include/helperRoutines.hpp"

static std::unique_ptr<ExprAST> ParseNumberExpr(){
    helperRoutines routines; 
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    routines.getNextToken();
    return std::move(Result);
}