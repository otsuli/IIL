#include "interpreter/interpreter.hpp"
#include "lexer/tokens.hpp"
#include "parser/expr.hpp"

Object Interpreter::visitLiteralExpr(Literal* expr) {
    return expr->value_;
}
Object Interpreter::visitGroupingExpr(Grouping* expr) {
    //! Todo: Fix
    return evaluate(expr);
}
Object Interpreter::evaluate(Expr* expr) {
    //! TODO: FIX
    return expr->accept(this);
}
Object Interpreter::visitUnaryExpr(UnaryExpr* expr) {
    Object right = evaluate(expr->right_);
    if (expr->op_.type_ == TokenType::Minus) {
        return static_cast<double>(std::get<double>(right));
    }
    return nullptr;
}
