#include "exceptions/lexTime.hpp"
#include <exception>
#include <string>
#include <utility>
#include "IIL.hpp"
#include "exceptions/exceptions.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

std::optional<Token> lexerTimeError::get_err_instance() const {
    return err_instance_token_.has_value() ? err_instance_token_
                                           : null::nullToken;
}
std::pair<ConstTokenType, ConstTokenValue> lexerTimeError::get_value()
    const noexcept {}

const char* lexerTimeError::what() const {
    return message_.c_str();
}

std::pair<ConstU16, ConstU16> lexerTimeError::get_line() const {
    if (err_instance_token_.has_value()) {
        ConstU16 constantline =
            static_cast<const u16&>(err_instance_token_.value().line_);
        ConstU16 constantColumn =
            static_cast<const u16&>(err_instance_token_.value().column_);
        return {constantline, constantColumn};
    }
    throw(lexerTimeError(std::nullopt, "No line and/or column value"));
}

lexerTimeError::lexerTimeError(const std::optional<Token>& Err_instance_token,
                               const std::string& Message)
    : err_instance_token_(Err_instance_token), message_(Message) {}

lexerTimeError::lexerTimeError(const std::optional<Token>& Err_instance_token,
                               const std::string& Message, int err_code)
    : err_instance_token_(Err_instance_token),
      message_(Message),
      IILException(err_code) {}