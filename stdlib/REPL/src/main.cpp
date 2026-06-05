#include <iostream>
#include "Ascii.h"
#include "utils.hpp"

int main() {
    ascii::Ascii font(ascii::starwar);
    font.print("IIL");
    std::cout << "Interesting Interpreted Programming Language" << std::endl;
    std::vector<std::string> input_cache;

    while (true) {
        std::string input;
        std::cout << "IIL>";
        std::cin >> input;
        if (REPLUtils::removeSpaces(input) == "exit")
            input_cache.emplace_back(input);
    }

    //! for the future: use another thread to listen for arrow presses to to
    //! grab older commands/code.
}