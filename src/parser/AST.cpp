#include "parser/AST.hpp"
#include "lexer/tokens.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include "../../include/IIL/parser/AST.hpp"

const std::string &PrototypeAST::getName() const { return Name; }// Getter to get the name of the function