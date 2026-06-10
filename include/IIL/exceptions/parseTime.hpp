#pragma once
#include <cstddef>
#include <memory>
#include <new>
#include <vector>
#include "parser/expr.hpp"
#include "parser/parsing.hpp"

struct Token;
struct ParseError : public std::exception {
    Token* token_;
    std::string message_;

    const char* what() const noexcept override;
    Token* get_err_instance() const;
    ParseError() : token_(null::nullToken), message_(" ") {}

    ParseError(Token token, std::string message)
        : token_(&token), message_(message) {}

    ParseError() = delete;
};