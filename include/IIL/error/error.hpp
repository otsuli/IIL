#include <format>
#include <memory>
#include <set>
#include <span>
#include <string>
#include <vector>
#include "lexer/tokens.hpp"

namespace errors {

void report(std::vector<std::string> errors);

void error(const Token& token, std::string_view message);

}  // namespace errors