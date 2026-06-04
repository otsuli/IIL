#include <exception>
#include <string>
#include "lexer/tokens.hpp"

class evalTimeError : public std::exception {
   private:
    Token err_instance_token_;
    std::string message_;

   public:
    const char* what() const noexcept { return message_.c_str(); }
    Token get_err_instance() const { return err_instance_token_; }

    // This function returns the line and the column (order is: line, column)
    // You can use a structured binding for unpacking the return. (C++ 17)
    std::pair<const u16, const u16> get_line() const {
        return {err_instance_token_.line_, err_instance_token_.column_};
    }
    std::pair<const TokenType, const std::variant<std::string, int>> get_value()
        const {
        return {err_instance_token_.type_, err_instance_token_.value_};
    }
    evalTimeError() = delete;
    evalTimeError(const Token& Err_instance_token, const std::string& Message)
        : err_instance_token_(Err_instance_token), message_(Message) {}
}