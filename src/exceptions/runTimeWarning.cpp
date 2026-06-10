namespace IILWarnings {
#include <iostream>
#include <string>
void runTimeWarning(const std::string& warning) noexcept {
    std::cerr << "\033[33m" << "[WARNING]" << warning << "\033[0m\n";
}

}  // namespace IILWarnings