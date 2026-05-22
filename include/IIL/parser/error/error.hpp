#include <exception>
#include <format>
#include <memory>
#include <set>
#include <span>
#include <string>
#include <vector>
#include "lexer/tokens.hpp"

namespace ParserErrors {

class ParseException : public std::exception {
   private:
    std::string message_;

   public:
    ParseException(const char* msg) : message_(msg) {}

    // Override the what() method.
    const char* what() const noexcept { return message_.c_str(); }
};
void report(std::vector<std::string> errors);

void error(const Token& token, std::string_view message);

}  // namespace ParserErrors