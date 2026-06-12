#include "lexer/tokens.hpp"
#include "exceptions/lexTime.hpp"

Token::Token(TokenType type, std::variant<std::string, int> value, u16 line,
             u16 column)
    : type_(type), value_(std::move(value)), line_(line), column_(column) {}

Token::Token(Token* tok)
    : Token(*tok)

          Token::Token(const std::optional<Token>& tok)
    : Token(tok ? *tok
                : throw lexerTimeError(std::nullopt,
                                       "std::optional<Token> value not "
                                       "found in constructor arguments")) {}
Token::Token make_token(TokenType type, std::variant<std::string, int> value,
                        u16 line, u16 column) {
    return Token{type, value, line, column};
}

bool Token::operator!=(const Token& token) const {
    return !(type_ == token.type_ && value_ == token.value_ &&
             line_ == token.line_ && column_ == token.column_);
}
bool Token::operator==(const Token& token) const {
    return (type_ == token.type_ && value_ == token.value_ &&
            line_ == token.line_ && column_ == token.column_);
}

Token::Token& operator=(const Token& t) {
    return *this;
}

Token::Token(std::unique_ptr<Token>& tok) : Token(*tok) {}

Token::Token(const Token& tok) : Token(tok) {}