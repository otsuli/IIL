#include <vector>
#include "ASTNode.hpp"
#include "tokens.hpp"
#include "helperRoutines.hpp"

class numericalExprAST
{
    std::shared_ptr<ASTnode> numericalExprAST::parseRHS(const Token number, const Token Oper); 

public:
    std::vector<ASTnode> NumExprAST(std::vector<Token> &Tokens);
};

struct OpTok : Token {
    Precedence precedence; 
    Token leftChild; 
    Token rightChild; 

    OpTok(Token left_child, Token right_child, Token value) {
        std::unique_ptr<OpTok> ptrTok; 
        leftChild = left_child; 
        right_child = right_child; 
        OpTok.value = value; 
        Precedence precednece = Precedence::Undefined; 
    }

    OpTok(Token left_child, Token right_child) {
        std::unique_ptr<OpTok> ptrTok; 
        leftChild = left_child; 
        right_child = right_child; 
        Precedence precednece = Precedence::Undefined; 
    }
}; 