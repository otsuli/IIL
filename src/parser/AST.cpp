#include "AST.hpp"
#include "ASTNode.hpp"

// Example: 1 + 1. Tokens are '1' '+' and '1'

std::vector<ASTnode> numericalExprAST::NumExprAST(std::vector<Token> Tokens)
{
    std::vector<ASTnode> nodes; 
    for (int i; i <= size(Tokens); i++)
    {
        if (Tokens[i].type == TokenType::Number)
        {
            ASTnode *numNode = new ASTnode(Tokens[i]);
            nodes.emplace_back(numNode); 
        }
        else if (Tokens[i].type == TokenType::Operator)
        {
            ASTnode *opNode = new ASTnode(Tokens[i]);
            nodes.emplace_back(opNode); 
        }
        else
        {
            std::cout << "Syntax Error: " + Tokens[i].line + Tokens[i].column << std::endl;
        }
    }

    
}

