#pragma once
#include <algorithm>
#include <iostream>

namespace REPLUtils {
std::string removeSpaces(std::string& s) {
    auto new_end = std::remove(s.begin(), s.end(), ' ');

    s.erase(new_end, s.end());

    return s;
}
}  // namespace REPLUtils