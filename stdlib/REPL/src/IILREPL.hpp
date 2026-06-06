#pragma once
#include <iostream>
#include <vector>
#include "Ascii.h"
#include "utils.hpp"

class IILREPL {
   public:
    void runREPL(std::istream& in) {
        ascii::Ascii font(ascii::starwar);
        font.print("IIL");
        std::cout << "Interesting Interpreted Programming Language"
                  << std::endl;
        std::vector<std::string> input_cache;

        while (true) {
            std::string input;
            std::cout << "IIL>";
            in >> input;
            if (REPLUtils::removeSpaces(input) == "exit") {
                break;
            }
            input_cache.emplace_back(input);
        }
    }
};