#include <format>
#include <memory>
#include <set>
#include <span>
#include <string>
#include <vector>
#include "lexer/tokens.hpp"

namespace errors {

void report(std::span<const std::string> errors);

void error(const Token& token, std::string_view message);

}  // namespace errors