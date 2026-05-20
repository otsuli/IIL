#include "error/error.hpp"
#include <format>
#include <memory>
#include <set>
#include <span>
#include <string>
#include <vector>
#include "lexer/tokens.hpp"

void errors::error(const Token& token, std::string_view message) {
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
