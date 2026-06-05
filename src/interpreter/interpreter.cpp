#include "interpreter/interpreter.hpp"
#include "exceptions/evalTime.hpp"
#include "exceptions/internalEval.hpp"
#include "lexer/tokens.hpp"
#include "parser/expr.hpp"

void Interpreter::checkNumberOperands(const Token& oper,
                                      const Object& left_operand,
                                      const Object& right_operand) {
    if (std::holds_alternative<double>(left_operand) &&
        std::holds_alternative<double>(right_operand)) {
        return;
    }
    throw evalTimeError(oper, "Operands must be numbers");
}

void Interpreter::checkNumberOperand(const Token& oper, const Object& operand) {
    if (std::holds_alternative<double>(operand)) {
        return;
    }
    throw evalTimeError(oper, "Operand type must be a number");
}

bool Interpreter::isEqual(const Object* a, const Object* b) {
    if (a == nullptr && b == nullptr)
        return true;
    if (a == nullptr || b == nullptr)
        return false;

    return *a == *b;
}

Object Interpreter::visitBinaryExpr(BinaryExpr* expr) {
    Object left = evaluate(expr->left_);
    Object right = evaluate(expr->left_);

    switch (expr->op_.type_) {
        case Plus:
            if (std::holds_alternative<double>(left) &&
                std::holds_alternative<double>(right)) {

                return std::get<double>(left) + std::get<double>(right);

            } else if (std::holds_alternative<std::string>(left) &&
                       std::holds_alternative<std::string>(right)) {

                return std::get<std::string>(left) +
                       std::get<std::string>(right);
            }
            throw evalTimeError(expr->op_,
                                "Operands must be two numbers or two strings");
            break;
        case Minus:
            checkNumberOperands(expr->op_, left, right);
            return std::get<double>(left) - std::get<double>(right);
            break;
        case Slash:
            checkNumberOperands(expr->op_, left, right);
            return std::get<double>(left) / std::get<double>(right);
            break;
        case Star:
            checkNumberOperands(expr->op_, left, right);
            return std::get<double>(left) * std::get<double>(right);
            break;
        case Greater:
            checkNumberOperands(expr->op_, left, right);
            return std::get<double>(left) > std::get<double>(right);
            break;
        case GreaterEqual:
            checkNumberOperands(expr->op_, left, right);
            return std::get<double>(left) >= std::get<double>(right);
            break;
        case Less:
            checkNumberOperands(expr->op_, left, right);
            return std::get<double>(left) < std::get<double>(right);
            break;
        case LessEqual:
            checkNumberOperands(expr->op_, left, right);
            return std::get<double>(left) <= std::get<double>(right);
            break;
        case BangEqual:
            return !isEqual(&left, &right);
            break;
        case EqualEqual:
            return isEqual(&left, &right);
            break;
        default:
            throw evalTimeError(expr->op_, "Unexpected Binary Expr");
            break;
    }
    return nullptr;
}

bool Interpreter::isTruthy(Object* object) {
    if (std::holds_alternative<Token>(*object)) {
        if (std::get<Token>(*object).type_ == TokenType::True) {
            return true;
        } else if (std::get<Token>(*object).type_ == TokenType::False) {
            return false;
        }
    } else if (std::holds_alternative<std::string>(*object)) {
        throw IILInternalEvalError(*object,
                                   "Can not call isTruthy() on a string");
    } else if (std::holds_alternative<double>(*object)) {
        throw IILInternalEvalError(*object,
                                   "Can not call isTruthy() on a double");
    } else if (std::holds_alternative<bool>(*object)) {
        switch (std::get<bool>(*object)) {
            case true:
                return true;
                break;
            case false:
                return false;
            default:
                //! handle
                break;
        }
    } else if (std::holds_alternative<std::nullptr_t>(*object)) {
        throw IILInternalEvalError(*object,
                                   "Can not call isTruthy() on a nullptr");
    } else if (std::holds_alternative<Expr>(*object)) {
        throw IILInternalEvalError(*object,
                                   "Can not call isTruthy() on an Expr");
    } else if (std::holds_alternative<UnaryExpr>(*object)) {
        throw IILInternalEvalError(*object,
                                   "Can not call isTruthy() on a UnaryExpr");
    } else if (std::holds_alternative<Grouping>(*object)) {
        throw IILInternalEvalError(*object,
                                   "Can not call isTruthy() on a Grouping");
    } else if (std::holds_alternative<Literal>(*object)) {
        throw IILInternalEvalError(*object,
                                   "Can not call isTruthy() on a Literal");
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
            checkNumberOperand(expr->op_, right);
            return static_cast<double>(std::get<double>(right));
            break;
        case Bang:
            return !isTruthy(&right);
            break;
        default:
            throw IILInternalEvalError(*expr,
                                       "Unexpected type in visitUnaryExpr()");
            break;
    }
    return nullptr;
}