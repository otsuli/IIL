#pragma once
#include <cstdint>
#include <iostream>
#include <unordered_set>

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
    Operator,
    Delimiter,
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
    Minus,
    False,
    True,
    NIL,
    String,
    end,
    ior,
};

struct Token {
    TokenType type_;
    std::string value_;
    // Just in case some idiot wants to write
    // 9,223,372,036,854,775,807
    // Lines of code in 1 file.
    uint64_t line_;
    uint64_t column_;

    Token(TokenType type, std::string value, unsigned int line,
          unsigned int column)
        : type_(type), value_(std::move(value)), line_(line), column_(column) {}
    virtual ~Token() = default;

    static Token make_token(TokenType type, std::string value,
                            unsigned int line, unsigned int column) {
        Token token(type, value, line, column);
        return token;
    }
};

Token nullToken{Token::make_token(TokenType::NONE, " ", 0, 0)};

inline const std::unordered_set<std::string> operators = {"+", "-", "*", "/",
                                                          "%", "<", ">", "="};

inline const std::unordered_set<std::string> delimiters = {";", ",",
                                                           "\""
                                                           ":"};

inline const std::unordered_set<std::string> keywords = {
    "ivar",     "iglobal", "NULL",    "if",   "else",   "eif",     "do",
    "iwhile",   "iend",    "iexit",   "ifor", "ibreak", "itry",    "iexcept",
    "ifinally", "ifunc",   "ireturn", "True", "False",  "iexplode"};
