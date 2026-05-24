#pragma once
#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <variant>
enum TokenType {
    Number,
    Identifier,
    ivar,
    iglobal,
    ifstatement,
    elsestatement,
    elseifstatement,
    dostatement,
    iwhile,
    iend,
    iexit,
    ifor,
    ibreak,
    itry,
    iexcept,
    ifinally,
    iexplode,
    ifunc,
    ireturn,
    True,
    False,
    OpenParen,
    CloseParen,
    Indent,
    FileEnd,
    BangEqual,
    EqualEqual,
    NONE,
    Greater,
    GreaterEqual,
    Less,
    LessEqual,
    Minus,
    Plus,
    Slash,
    Star,
    Bang,
    False,
    True,
    NIL,
    String,
    ior,
    semicolon,
    comma,
    newline,
    colon,
    equal,
    FloorDiv,
};

struct Token {
    TokenType type_;
    std::variant<std::string, int> value_;

    // Just in case some idiot wants to write
    // 9,223,372,036,854,775,807
    // Lines of code in 1 file.
    uint64_t line_;
    uint64_t column_;

    Token(TokenType type, std::variant<std::string, int> value, uint64_t line,
          uint64_t column)
        : type_(type), value_(std::move(value)), line_(line), column_(column) {}

    static Token make_token(TokenType type,
                            std::variant<std::string, int> value, uint64_t line,
                            uint64_t column) {
        return Token(type, std::move(value), line, column);
    }

    bool operator!=(const Token& token) const {
        return !(type_ == token.type_ && value_ == token.value_ &&
                 line_ == token.line_ && column_ == token.column_);
    }
};

Token nullToken{Token::make_token(TokenType::NONE, " ", 0, 0)};