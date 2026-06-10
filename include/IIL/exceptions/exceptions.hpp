#pragma once
#include <exception>
#include <string>
#include <utility>
#include "lexer/tokens.hpp"
#include "types.hpp"
struct Token;
enum class TokenType;
class IILException : public std::exception {
   protected:
    int err_code_ = 1;

   public:
    // Returns the value as a pair, (order is: TokenType, Value)
    // You can use a structured binding for unpacking the return. (C++ 17)
    virtual std::pair<ConstTokenType, ConstTokenValue> get_value() const;

    // This function returns the line and the column (order is: line, column)
    // You can use a structured binding for unpacking the return. (C++ 17)
    virtual std::pair<ConstU16, ConstU16> get_line() const;

    virtual ~IILException() = default;
    IILException(int err_code) : err_code_(err_code) {}
    IILException() = default;
};