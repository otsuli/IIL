#include <exception>
#include <string>
#include <utility>
#include "lexer/tokens.hpp"
#include "types.hpp"

IILException::IILException(int err_code) : err_code_(err_code) {}