#include <iostream>
#include "IIL.hpp"
#include "interpreter/interpreter.hpp"
#include "lexer/tokenization.hpp"

int main(int argc, char* argv[]) {
    Tokenizing tokenizer;
    std::vector<Token>* tokens = nullptr;
    try {
        tokens = new std::vector<Token>(
            tokenizer.tokenize());  //! add file reading to tokenize a file.
    } catch (IILException& exception) {
        IIL::hadRunTimeError = true;
    }
    IIL::interpreter->interpret(tokens);

    delete IIL::interpreter;
    delete tokens;
    return 0;
}