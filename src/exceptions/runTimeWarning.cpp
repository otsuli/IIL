#include "exceptions/runTimeWarning.hpp"
#include <iostream>
#include <string>

namespace IILWarnings {
void runTimeWarning(const std::string& warning) noexcept {
    std::cerr << "\033[33m" << "[WARNING]" << warning << "\033[0m\n";
}