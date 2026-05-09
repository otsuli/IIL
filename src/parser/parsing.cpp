#include "parsing.hpp"
#include "ASTNode.hpp"
#include "helperRoutines.hpp"
#include <vector> 
// Example: 1 + 1. Tokens are '1' '+' and '1'

std::vector<ASTnode> numericalExprAST::NumExprAST(std::vector<Token> &Tokens)
{
    parserUtils::clearBuffer();

    OpTok curTok;
    for (int i = 0; i <= Tokens.size(); i++)
    {
        curTok = Tokens[i];
        if (parserUtils::isBinary(curTok.value))
        {

            parserUtils::buffer_Op(curTok);
        }
    }
    Token highest_precedence_op = parserUtils::getHighestPrecedence(parserUtils::opBuffer);
    std::shared_ptr<ASTnode> highest_precedence_node = parserUtils::to_node(highest_precedence_op);

    parserUtils::rem_buffered_op(highest_precedence_op);

    //? IDEA: Create OpTok object that holds number nodes as it's children. That way we can easily convert it to a node and connect thme to each other.
    //? OpTok can be inherited from the Token class. And it could have the property of children. And maybe the constructors could auto assign a precedence to it?.

    
}
