#include "lexer/stringPool.hpp"
#include <cstdint>
#include <memory>
#include "lexer/tokens.hpp"
#include "types.hpp"
#include "vector"

const std::string* StringPool::intern(const std::string& str) {
    // Structured binding C++ 17:
    // insert() returns an iterator and a bool.
    auto [it, inserted] = pool.insert(str);
    // dereference the iterator and get the resulting memory address of the
    // string.
    return &*it;
}

void TokenProcessor::initKeywordMap() {
    // Create a LUT
    auto add = [&](const char* kw, TokenType type) {
        // [] operator is used to either give the value at a certain key or
        // create a value if one doesn't exist yet.
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
    add("iexception", TokenType::iexception);
    add("False", TokenType::False);
    add("NULL", TokenType::NIL);
    add("ior", TokenType::ior);
    add("!=", TokenType::BangEqual);
    add("==", TokenType::EqualEqual);
    add(">=", TokenType::GreaterEqual);
    add("<=", TokenType::LessEqual);
    add("//", TokenType::FloorDiv);
}

std::unique_ptr<Token> TokenProcessor::processPooledString(
    const std::string* str, u16 line, u16 column) {
    auto it = keywordMap.find(str);
    if (it != keywordMap.end())
        return std::make_unique<Token>(
            Token::make_token(it->second, *str, line, column));
    return std::make_unique<Token>(null::nullToken);
}

std::unique_ptr<Token> TokenProcessor::processTokenVal(
    const std::string& command, u16 line, u16 column) {
    const std::string* pooledString = stringPool.intern(command);
    auto token = std::make_unique<Token>(
        processPooledString(*&pooledString, line, column));
    return token;
}
