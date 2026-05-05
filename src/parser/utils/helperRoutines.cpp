#include "ASTNode.hpp"
#include "helperRoutines.hpp"
#include "parserError.hpp"
#include <exception>

Precedence parserUtils::getPrecedence(ASTnode const opNode) {
    std::string value = opNode.NodeValue.value; 
    //! Add parentheses precedence

    if (value == "**"){
        return LEVEL3; 
    }
    else if (value == "*"){
        return LEVEL2; 
    }
    else if (value == "/"){
        return LEVEL2; 
    }
    else if (value == "%"){
        return LEVEL2; 
    }
    else if (value == "+"){
        return LEVEL1; 
    }
    else if (value == "-"){
        return LEVEL1; 
    }
    else if (value == "="){
        return LEVEL0; 
    }
    else {
        //! Add error handling.
    }
}