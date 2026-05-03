#pragma once
#include <iostream>
#include "tokens.hpp"
#include <vector>
#include <memory>

struct ASTnode
{
    Token parent; 
    Token NodeValue;
    ASTnode *leftChild, *rightChild;
    ASTnode *ext_of_parent;

    ASTnode(Token parent, Token NodeValue, ASTnode *leftChild, ASTnode *rightChild, ASTnode *ext_of_parent) //standard node with more than 2 children
    {
        parent = parent;
        NodeValue = NodeValue;
        leftChild = leftChild;
        rightChild = rightChild;
        ext_of_parent = ext_of_parent;
    }
    ASTnode(Token parent, Token NodeValue, ASTnode *leftChild, ASTnode *rightChild) //standard node
    {
        parent = parent;
        NodeValue = NodeValue;
        leftChild = leftChild;
        rightChild = rightChild;
        ext_of_parent = nullptr;
    }
    ASTnode(Token parent, Token NodeValue) //leaf node constructor
    {
        parent = parent;
        NodeValue = NodeValue;
        rightChild = nullptr;
        leftChild = nullptr;
        ext_of_parent = nullptr;
    }
    ASTnode(Token NodeValue, ASTnode* leftChild, ASTnode* rightChild) // root node constructor
    {
        parent.type = TokenType::NONE; 
        parent.value = "None"; 
        parent.line = NULL; 
        parent.column = NULL; 
        
        NodeValue = NodeValue;
        rightChild = rightChild;
        leftChild = leftChild; 
        ext_of_parent = nullptr;
    }
};