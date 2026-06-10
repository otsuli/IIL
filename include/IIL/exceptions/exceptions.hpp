#pragma once
#include <charconv>
#include <exception>
#include <string>
#include <utility>
#include "lexer/tokens.hpp"
#include "types.hpp"

struct Token;
enum class TokenType;
class IILException : public std::exception {
   protected:
    unsigned int err_code_ = 1;

   public:
    const char* what() const noexcept override {
        // 11 characters for a 32 bit unsigned int
        std::array<char, 12> buffer;

        auto [ptr, ec] = std::to_chars(
            buffer.data(), buffer.data() + buffer.size(), err_code_);

        if (ec == std::errc{}) {
            *ptr = '\0';

            const char* c_str = buffer.data();

            return c_str;
        } else {
            throw IILException(15);
        }
    }

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