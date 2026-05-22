#include "parser/error/error.hpp"
#include <format>
#include <memory>
#include <set>
#include <span>
#include <string>
#include <vector>
#include "lexer/tokens.hpp"

void ParserErrors::error(const Token& token, std::string_view message) {
    std::vector<std::string> errors;

    if (token.type_ == TokenType::FileEnd) {
        errors.emplace_back(
            std::format("[line {}] Error at end: {}", token.line_, message));
    } else {
        errors.emplace_back(std::format("[line {}] Error at '{}': {}",
                                        token.line_, token.value_, message));
    }

    report(errors);
}

int ParserErrors::report(std::string message) {
    if (message.size() != 0) {
        throw ParseException(message.c_str());
        return 0;
    } else {
        return 1;
    }
}