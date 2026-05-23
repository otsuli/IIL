#include "interpreter/interpreter.hpp"
#include "lexer/tokens.hpp"
#include "parser/expr.hpp"

using Object = std::variant<double, std::string, bool, std::nullptr_t, Token,
                            Expr*, UnaryExpr*, Grouping*, Literal*>;

Object Interpreter::visitLiteralExpr(Literal expr) {
    return expr.value_;
}
Object Interpreter::visitGroupingExpr(Grouping expr) {
    //! Todo: Fix
    return evaluate(expr);
}
Object Interpreter::evaluate(Expr expr) {
    //! TODO: FIX
    return expr.accept(this);
}
Object Interpreter::visitUnaryExpr(UnaryExpr expr) {
    Object right = evaluate(expr.right_);  //! TBD FIX
    if (expr.op_.type_ == TokenType::Minus) {
        return -(double)right;  //! TBD FIX
    }
    return nullptr;
}