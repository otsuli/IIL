#include <vector>
#include "AST/ASTNode.hpp"
#include "tokens.hpp"
class numericalExprAST {
    public: 
    std::vector<ASTnode> NumExprAST(std::vector<Token> &Tokens);
}; 