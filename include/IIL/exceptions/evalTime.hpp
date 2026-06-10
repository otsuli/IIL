#pragma once
#include <exception>
#include <memory>
#include <optional>
#include <string>
#include <utility>
#include "exceptions/exceptions.hpp"
#include "types.hpp"

struct Token;
class evalTimeError : public IILException {
   private:
    const Token* err_instance_token_;
    const std::string message_;

   public:
    // Returns the error message
    const char* what() const noexcept;
    // Returns the error token
    std::unique_ptr<Token*> get_err_instance() const;

    // This function returns the line and the column (order is: line, column)
    // You can use a structured binding for unpacking the return. (C++ 17)
    std::pair<ConstU16, ConstU16> get_line() const override;
    // Returns the value as a pair, (order is: TokenType, Value)
    // You can use a structured binding for unpacking the return. (C++ 17)
    std::pair<ConstTokenType, ConstTokenValue> get_value() const override;

    evalTimeError(const Token& Err_instance_token, const std::string& Message);

    evalTimeError(const std::optional<Token>& Err_instance_token,
                  const std::string& Message, int err_code);

    evalTimeError() = default;
}