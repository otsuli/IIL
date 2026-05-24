#include "lexer/stringPool.hpp"
#include <cstdint>
#include "lexer/tokens.hpp"
#include "vector"

const std::string* StringPool::intern(const std::string& str) {
    auto [it, inserted] = pool.insert(str);
    return &(*it);
}

void TokenProcessor::initKeywordMap() {
    auto add = [&](const char* kw, TokenType type) {
        keywordMap[stringPool.intern(kw)] = type;
    };

    add("ivar", TokenType::ivar);
    add("iglobal", TokenType::iglobal);
    add("if", TokenType::ifstatement);
    add("else", TokenType::elsestatement);
    add("eif", TokenType::elseifstatement);
    add("do", TokenType::dostatement);
    add("iwhile", TokenType::iwhile);
    add("iend", TokenType::iend);
    add("iexit", TokenType::iexit);
    add("ifor", TokenType::ifor);
    add("ibreak", TokenType::ibreak);
    add("itry", TokenType::itry);
    add("iexcept", TokenType::iexcept);
    add("ifinally", TokenType::ifinally);
    add("iexplode", TokenType::iexplode);
    add("ifunc", TokenType::ifunc);
    add("ireturn", TokenType::ireturn);
    add("True", TokenType::True);
    add("False", TokenType::False);
    add("NULL", TokenType::NIL);
    add("ior", TokenType::ior);
    add("!=", TokenType::BangEqual);
    add("==", TokenType::EqualEqual);
}

Token TokenProcessor::processPooledString(const std::string* str, uint64_t line,
                                          uint64_t column) {
    auto it = keywordMap.find(str);
    if (it != keywordMap.end())
        return Token::make_token(it->second, *str, line, column);
    return nullToken;
}

Token TokenProcessor::processTokenVal(const std::string* command, uint64_t line,
                                      uint64_t column) {
    const std::string* pooledString = stringPool.intern(*command);
    Token token = processPooledString(pooledString, line, column);
    return token;
}