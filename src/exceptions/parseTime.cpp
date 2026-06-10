#include <cstddef>
#include <memory>
#include <new>
#include <vector>
#include "lexer/tokens.hpp"
#include "parser/expr.hpp"
#include "parser/parsing.hpp"

const char* ParseError::what() const noexcept {
    return message_.c_str();
}

ParseError::ParseError(Token token, std::string message)
    : token_(&token), message_(message) {}

Token* ParseError::get_err_instance() const {
    return token_;
}
