#include <cstdint>
#include <iostream>
#include <string_view>

namespace stringHash {

constexpr uint64_t hash(std::string_view str) {
    uint64_t hash = 0;
    for (char c : str) {
        hash = (hash * 131) + c;
    }
    return hash;
}

constexpr uint64_t operator"" _hash(const char* str, size_t len) {
    return hash(std::string_view(str, len));
}

}  // namespace stringHash
