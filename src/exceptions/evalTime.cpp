#include "exceptions/evalTime.hpp"
#include <exception>
#include <optional>
#include <string>
#include <utility>
#include "lexer/tokens.hpp"
#include "types.hpp"

const char* evalTimeError::what() const noexcept {
    return message_.c_str();
}

std::unique_ptr<Token*> evalTimeError::get_err_instance() const {
    return std::make_unique<Token*>(err_instance_token_);
}

std::pair<ConstU16, ConstU16> evalTimeError::get_line() const {
    return {err_instance_token_->line_, err_instance_token_->column_};
}

evalTimeError::evalTimeError(const Token& Err_instance_token,
                             const std::string& Message)
    : err_instance_token_(&Err_instance_token), message_(Message) {}

evalTimeError::evalTimeError(const std::optional<Token>& Err_instance_token,
                             const std::string& Message, int err_code)
    : err_instance_token_(Err_instance_token.has_value() ? &*Err_instance_token
                                                         : null::nullToken),
      message_(Message),
      IILException(err_code) {}