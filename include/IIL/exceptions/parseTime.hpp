#pragma once
#include <cstddef>
#include <memory>
#include <new>
#include <vector>
#include "lexer/tokens.hpp"
#include "parser/expr.hpp"
#include "parser/parsing.hpp"
struct Token;
struct ParseError : public std::exception {
    Token token_;
    std::string message_;

    const char* what() const noexcept { return message_.c_str(); }
    Token get_err_instance() const { return token_; }
    ParseError() : token_(null::nullToken), message_(" ") {}

    ParseError(Token token, std::string message)
        : token_(token), message_(message) {}
};