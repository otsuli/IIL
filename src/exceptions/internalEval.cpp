#include "exceptions/internalEval.hpp"
#include "lexer/tokens.hpp"

const char* IILInternalEvalError::what() const noexcept {
    return message_.c_str();
}

Object IILInternalEvalError::get_err_instance() const noexcept {
    return err_instance_object_;
}

IILInternalEvalError::IILInternalEvalError(const Object& Err_instance_Object,
                                           const std::string& Message)
    : err_instance_object_(Err_instance_Object), message_(Message) {}