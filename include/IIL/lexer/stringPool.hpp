#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
#include "lexer/tokens.hpp"
class StringPool {
    // Technical info:
    // to analyze split strings IIL uses string poolin gin order to reduce
    // the amount of memory required for tokenization. Another benefit of string
    // pooling is that token classification is very fast, for pointer
    // comparisons are to my understanding 0(1).

   private:
    std::unordered_set<std::string> pool;

   public:
    const std::string* intern(const std::string& str);
};  // class StringPool

class TokenProcessor {
   private:
    StringPool stringPool;
    Token processPooledString(const std::string* str, uint64_t line,
                              uint64_t column);

   public:
    Token processTokenVal(const std::string* command, uint64_t line,
                          uint64_t column)

};  // class CommandProcessor
