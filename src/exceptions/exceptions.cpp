#include "exceptions/exceptions.hpp"
#include <charconv>
#include <exception>
#include <string>
#include <utility>
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