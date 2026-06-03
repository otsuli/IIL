#include "interpreter/interpreter.hpp"
#include "lexer/tokens.hpp"
#include "parser/expr.hpp"

bool Interpreter::isTruthy(Object object) {
    if (std::holds_alternative<Token>(object)) {
        if (std::get<Token>(object).type_ == TokenType::True) {
            return true;
        } else if (std::get<Token>(object).type_ == TokenType::False) {
            return false;
        }
    } else if (std::holds_alternative<std::string>(object)) {
        //! Throw
    } else if (std::holds_alternative<double>(object)) {
        //! Throw
    } else if (std::holds_alternative<bool>(object)) {
        switch (std::get<bool>(object)) {
            case true:
                return true;
                break;
            case false:
                return false;
            default:
                //! handle
        }
    } else if (std::holds_alternative<std::nullptr_t>(object)) {
        //! Throw
    } else if (std::holds_alternative<Expr>(object)) {
        //! Throw
    } else if (std::holds_alternative<UnaryExpr>(object)) {
        //! Throw
    } else if (std::holds_alternative<Grouping>(object)) {
        //! Throw
    } else if (std::holds_alternative<Literal>(object)) {
        //! Throw
    }
}

Object Interpreter::visitLiteralExpr(Literal* expr) {
    return expr->value_;
}

Object Interpreter::visitGroupingExpr(Grouping* expr) {
    if (expr->contained_expression_) {
        return evaluate(expr->contained_expression_);
    }
    // Handle error
}

Object Interpreter::evaluate(Expr* expr) {
    return expr->accept(this);
}

Object Interpreter::visitUnaryExpr(UnaryExpr* expr) {
    Object right = evaluate(expr->right_);
    switch (expr->op_.type_) {
        case Minus:
            return static_cast<double>(std::get<double>(right));
            break;
        case Bang:
            return !isTruthy(right);
            break;
        default:
            //! Handle
            break;
    }
    return nullptr;
}