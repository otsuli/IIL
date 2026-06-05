#include <iostream>
#include <string>
namespace IILWarnings {

void runTimeWarning(const std::string& warning) {
    std::cerr << "\033[33m" << "[WARNING]" << warning << "\033[0m\n";
}

}  // namespace IILWarnings
