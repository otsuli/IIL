#include "lexer/stringPool.hpp"
#include <cstdint>
#include "lexer/tokens.hpp"
#include "vector"

const std::string* StringPool::intern(const std::string& str) {
    auto [it, inserted] = pool.insert(str);
    return &(*it);
}

Token TokenProcessor::processPooledString(const std::string* str, uint64_t line,
                                          uint64_t column) {
    if (str == stringPool.intern("ivar")) {
        return Token::make_token(TokenType::ivar, *str, line, column);
    } else if (str == stringPool.intern("iglobal")) {
        return Token::make_token(TokenType::iglobal, *str, line, column);
    } else if (str == stringPool.intern("if")) {
        return Token::make_token(TokenType::ifstatement, *str, line, column);
    } else if (str == stringPool.intern("else")) {
        return Token::make_token(TokenType::elsestatement, *str, line, column);
    } else if (str == stringPool.intern("eif")) {
        return Token::make_token(TokenType::elseifstatement, *str, line,
                                 column);
    } else if (str == stringPool.intern("do")) {
        return Token::make_token(TokenType::dostatement, *str, line, column);
    } else if (str == stringPool.intern("iwhile")) {
        return Token::make_token(TokenType::iwhile, *str, line, column);
    } else if (str == stringPool.intern("iend")) {
        return Token::make_token(TokenType::iend, *str, line, column);
    } else if (str == stringPool.intern("iexit")) {
        return Token::make_token(TokenType::iexit, *str, line, column);
    } else if (str == stringPool.intern("ifor")) {
        return Token::make_token(TokenType::ifor, *str, line, column);
    } else if (str == stringPool.intern("ibreak")) {
        return Token::make_token(TokenType::ibreak, *str, line, column);
    } else if (str == stringPool.intern("itry")) {
        return Token::make_token(TokenType::itry, *str, line, column);
    } else if (str == stringPool.intern("iexcept")) {
        return Token::make_token(TokenType::iexcept, *str, line, column);
    } else if (str == stringPool.intern("iexplode")) {
        return Token::make_token(TokenType::ifinally, *str, line, column);
    } else if (str == stringPool.intern("iexplode")) {
        return Token::make_token(TokenType::iexplode, *str, line, column);
    } else if (str == stringPool.intern("ifunc")) {
        return Token::make_token(TokenType::ifunc, *str, line, column);
    } else if (str == stringPool.intern("ireturn")) {
        return Token::make_token(TokenType::ireturn, *str, line, column);
    } else if (str == stringPool.intern("True")) {
        return Token::make_token(TokenType::True, *str, line, column);
    } else if (str == stringPool.intern("False")) {
        return Token::make_token(TokenType::False, *str, line, column);
    } else if (str == stringPool.intern("(")) {
        return Token::make_token(TokenType::OpenParen, *str, line, column);
    } else if (str == stringPool.intern(")")) {
        return Token::make_token(TokenType::CloseParen, *str, line, column);
    } else if (str == stringPool.intern("\t")) {
        return Token::make_token(TokenType::Indent, *str, line, column);
    } else if (str == stringPool.intern("!=")) {
        return Token::make_token(TokenType::BangEqual, *str, line, column);
    } else if (str == stringPool.intern("==")) {
        return Token::make_token(TokenType::EqualEqual, *str, line, column);
    } else if (str == stringPool.intern(">")) {
        return Token::make_token(TokenType::Greater, *str, line, column);
    } else if (str == stringPool.intern(">=")) {
        return Token::make_token(TokenType::GreaterEqual, *str, line, column);
    } else if (str == stringPool.intern("<=")) {
        return Token::make_token(TokenType::LessEqual, *str, line, column);
    } else if (str == stringPool.intern("<")) {
        return Token::make_token(TokenType::Less, *str, line, column);
    } else if (str == stringPool.intern("-")) {
        return Token::make_token(TokenType::Minus, *str, line, column);
    } else if (str == stringPool.intern("+")) {
        return Token::make_token(TokenType::Plus, *str, line, column);
    } else if (str == stringPool.intern("/")) {
        return Token::make_token(TokenType::Slash, *str, line, column);
    } else if (str == stringPool.intern("*")) {
        return Token::make_token(TokenType::Star, *str, line, column);
    } else if (str == stringPool.intern("!")) {
        return Token::make_token(TokenType::Bang, *str, line, column);
    } else if (str == stringPool.intern("NULL")) {
        return Token::make_token(TokenType::NIL, *str, line, column);
    } else if (str == stringPool.intern("ior")) {
        return Token::make_token(TokenType::ior, *str, line, column);
    } else {
        return nullToken;
    }
}

Token TokenProcessor::processTokenVal(const std::string* command, uint64_t line,
                                      uint64_t column) {
    const std::string* pooledString = stringPool.intern(*command);
    Token token = processPooledString(pooledString, line, column);
}