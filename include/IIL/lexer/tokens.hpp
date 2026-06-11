#pragma once
#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <variant>
#include "types.hpp"

enum class TokenType {
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
    NIL,
    String,
    ior,
    semicolon,
    comma,
    newline,
    colon,
    equal,
    FloorDiv,
    Modulo,
    iexception,
};
struct Token {
    const TokenType type_;
    const std::variant<std::string, int> value_;

    const u16 line_;
    const u16 column_;

    Token() = default;

    Token(TokenType type, std::variant<std::string, int> value, u16 line,
          u16 column);
    Token(Token* tok);

    Token(const std::optional<Token>& tok);

    Token(std::unique_ptr<Token> tok);

    inline static Token make_token(TokenType type,
                                   std::variant<std::string, int> value,
                                   u16 line, u16 column);

    bool operator!=(const Token& token) const;
    bool operator==(const Token& token) const;

    Token& operator=(const Token& t) { return *this; }
    Token operator+(const Token& other) = delete;
    Token operator-(const Token& other) = delete;
    Token operator/(const Token& other) = delete;
    Token operator*(const Token& other) = delete;
};

namespace null {
inline const Token nullToken{Token::make_token(TokenType::NONE, " ", 0, 0)};
}  // namespace null

inline std::unordered_set<char> delimiters{
    ';', ',', '\n', ':', '(', ')',
};