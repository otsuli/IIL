#include <exception>
#include <optional>
#include <string>
#include <utility>
#include "exceptions/exceptions.hpp"
#include "lexer/tokens.hpp"

class evalTimeError : public IILException {
   private:
    Token err_instance_token_;
    std::string message_;

   public:
    // Returns the error message
    const char* what() const noexcept { return message_.c_str(); }
    // Returns the error token
    Token get_err_instance() const { return err_instance_token_; }

    // This function returns the line and the column (order is: line, column)
    // You can use a structured binding for unpacking the return. (C++ 17)
    std::pair<const u16, const u16> get_line() const override {
        return {err_instance_token_.line_, err_instance_token_.column_};
    }

    // Returns the value as a pair, (order is: TokenType, Value)
    // You can use a structured binding for unpacking the return. (C++ 17)
    std::pair<const TokenType, const std::variant<std::string, int>> get_value()
        const override {
        return {err_instance_token_.type_, err_instance_token_.value_};
    }

    evalTimeError(const Token& Err_instance_token, const std::string& Message)
        : err_instance_token_(Err_instance_token), message_(Message) {}

    evalTimeError(const std::optional<Token>& Err_instance_token,
                  const std::string& Message, int err_code)
        : err_instance_token_(Err_instance_token),
          message_(Message),
          IILException(err_code) {}

    evalTimeError() = default;
};