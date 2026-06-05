#include "IIL.hpp"
#include <iostream>

Interpreter* IIL::interpreter = new Interpreter();

void IIL::runtimeError(IILException& error) {
    auto [line, column] = error.get_line();
    std::cerr << error.what() << "\n"
              << "[Line: " << line << "]" << "[Column: " << column << "]";
    hadRunTimeError = true;
}