#include "exceptions/exceptions.hpp"
#include <charconv>
#include <exception>
#include <string>
#include <utility>
#include "exceptions/internalEval.hpp"
#include "exceptions/runTimeWarning.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

IILException::IILException(int err_code) : err_code_(err_code) {}

const char* IILException::what() const noexcept {
    auto [ptr, ec] =
        std::to_chars(buffer.data(), buffer.data() + buffer.size(), err_code_);

    if (ec == std::errc{}) {
        *ptr = '\0';

        const char* c_str = buffer.data();

        return c_str;
    } else {
        throw IILException(15);
    }
}

virtual std::pair<ConstTokenType, ConstTokenValue> IILException::get_value()
    const noexcept {
    IILWarnings::runTimeWarning(
        "Can't Call get_value() on a IILException Bass class");
    return {TokenType::NONE, ""}
}

virtual std::pair<ConstU16, ConstU16> get_line() const {
    IILWarnings::runTimeWarning(
        "Can't Call get_line() on a IILException Bass class");
    return {0, 0}
}