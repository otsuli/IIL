#include "parser/expr.hpp"
#include "lexer/tokens.hpp"

BinaryExpr::BinaryExpr(Expr& left, Expr& right, Token& op)
    : left_(&left), right_(&right), op_(&op) {}
BinaryExpr() : left_(nullptr), right_(nullptr), op_(&*null::nullToken) {}

Literal::Literal(Token& value) : value_(&value) {}
Literal::Literal() : value_(&*null::nullToken) {}

Grouping::Grouping() : contained_expression_(nullptr) {}