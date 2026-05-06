#pragma once
#include <iostream>
#include "tokens.hpp"
#include <vector>
#include <memory>

struct ASTnode
{
    Token NodeValue, parent;
    std::shared_ptr<ASTnode> leftChild, rightChild, extension_of_parent; 
    ASTnode()
    {
        parent.column = NULL;
        parent.line = NULL;
        parent.value = " ";
        parent.type = TokenType::NONE;
    }

    ASTnode(Token Value) : NodeValue(Value),
                           leftChild(nullptr),
                           rightChild(nullptr),
                           extension_of_parent(nullptr) {}
};

enum Precedence
{
    // Precedence in order of greatest to least
    LEVEL4, // Parentheses 
    LEVEL3, // Exponents 
    LEVEL2, // Multiplication/Division/Modulus
    LEVEL1, // Addition/Subtraction
    LEVEL0, // Equality expression

};

