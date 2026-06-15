#pragma once
#include <exception>
#include <string>
#include <utility>
#include "IIL.hpp"
#include "exceptions/exceptions.hpp"
#include "types.hpp"

struct Token;

class lexerTimeError : public IILException {
   private:
    std::optional<Token> err_instance_token_;
    std::string message_;

   public:
    // Returns the error message
    const char* what() const noexcept override;

    // Returns the error token optionally
    // Remember to check if it returned anything.
    std::optional<Token> get_err_instance() const;

    std::pair<ConstTokenType, ConstTokenValue> get_value()
        const noexcept override;

    // This function returns the line and the column (order is: line, column)
    // You can use a structured binding for unpacking the return. (C++ 17)
    std::pair<ConstU16, ConstU16> get_line() const override;

    lexerTimeError(const std::optional<Token>& Err_instance_token,
                   const std::string& Message);

    lexerTimeError(const std::optional<Token>& Err_instance_token,
                   const std::string& Message, int err_code);
    lexerTimeError() = default;
};