#pragma once
#include <exception>
#include <variant>
#include "lexer/tokens.hpp"
#include "parser/expr.hpp"

struct Token;
class IILInternalEvalError : public std::exception {
    using Object =
        std::variant<double, std::string, bool, std::nullptr_t, Token, Expr>;

   private:
    Object err_instance_object_;
    std::string message_;

   public:
    // Returns the error message
    const char* what() const noexcept { return message_.c_str(); }

    // Returns the error token
    Object get_err_instance() const { return err_instance_object_; }

    IILInternalEvalError(const Object& Err_instance_Object,
                         const std::string& Message)
        : err_instance_object_(Err_instance_Object), message_(Message) {}
};