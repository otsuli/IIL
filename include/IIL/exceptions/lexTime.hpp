#pragma once
#include <exception>
#include <string>
#include <utility>
#include "IIL.hpp"
#include "exceptions/exceptions.hpp"
#include "lexer/tokens.hpp"

class lexerTimeError : public IILException {
   private:
    std::optional<Token> err_instance_token_;
    std::string message_;

   public:
    // Returns the error message
    const char* what() const noexcept { return message_.c_str(); }

    // Returns the error token optionally
    // Remember to check if it returned anything.
    std::optional<Token> get_err_instance() const {
        return err_instance_token_;
    }

    // This function returns the line and the column (order is: line, column)
    // You can use a structured binding for unpacking the return. (C++ 17)
    std::pair<const u16, const u16> get_line() const override {
        if (err_instance_token_.has_value()) {
            return {err_instance_token_.value().line_,
                    err_instance_token_.value().line_};
        }
        throw(lexerTimeError(std::nullopt, "No line and/or column value"));
    }

    lexerTimeError(const std::optional<Token>& Err_instance_token,
                   const std::string& Message)
        : err_instance_token_(Err_instance_token), message_(Message) {}

    lexerTimeError(const std::optional<Token>& Err_instance_token,
                   const std::string& Message, int err_code)
        : err_instance_token_(Err_instance_token),
          message_(Message),
          IILException(err_code) {}
    lexerTimeError() = default;
};