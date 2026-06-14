#include "lexer/tokens.hpp"
#include "exceptions/lexTime.hpp"

Token::Token(TokenType type, std::variant<std::string, int> value, u16 line,
             u16 column)
    : type_(type), value_(std::move(value)), line_(line), column_(column) {}

Token Token::make_token(TokenType type, std::variant<std::string, int> value,
                        u16 line, u16 column) noexcept {
    return Token{type, std::move(value), line, column};
}

bool Token::operator!=(const Token& token) const {
    return !(type_ == token.type_ && value_ == token.value_ &&
             line_ == token.line_ && column_ == token.column_);
}
bool Token::operator==(const Token& token) const {
    return (type_ == token.type_ && value_ == token.value_ &&
            line_ == token.line_ && column_ == token.column_);
}
