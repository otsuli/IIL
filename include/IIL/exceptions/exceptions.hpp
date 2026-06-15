#pragma once
#include <charconv>
#include <exception>
#include <string>
#include <utility>
#include "types.hpp"

struct Token;
enum class TokenType;
class IILException : public std::exception {
   private:
    // 11 characters for a 32 bit unsigned int (last one is the null terminator)
    std::array<char, 12> buffer;

   protected:
    unsigned int err_code_ = 1;

   public:
    virtual const char* what() const noexcept override;

    // Returns the value as a pair, (order is: TokenType, Value)
    // You can use a structured binding for unpacking the return. (C++ 17)
    virtual std::pair<ConstTokenType, ConstTokenValue> get_value()
        const noexcept;

    // This function returns the line and the column (order is: line, column)
    // You can use a structured binding for unpacking the return. (C++ 17)
    virtual std::pair<ConstU16, ConstU16> get_line() const;

    virtual ~IILException() = default;
    IILException(int err_code);
    IILException() = delete;
};