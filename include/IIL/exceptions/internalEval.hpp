#pragma once
#include <exception>
#include <variant>
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
    const char* what() const noexcept override;

    // Returns the error token
    Object get_err_instance() const noexcept;

    IILInternalEvalError(const Object& Err_instance_Object,
                         const std::string& Message);
};