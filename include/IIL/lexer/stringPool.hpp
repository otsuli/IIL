#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "types.hpp"

struct Token;
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
    std::unordered_map<const std::string*, TokenType> keywordMap;
    void initKeywordMap();
    StringPool stringPool;
    std::unique_ptr<Token> processPooledString(const std::string* str, u16 line,
                                               u16 column);

   public:
    std::unique_ptr<Token> processTokenVal(const std::string& command, u16 line,
                                           u16 column);
    TokenProcessor() { initKeywordMap(); }
};  // class CommandProcessor
