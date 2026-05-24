#include <gtest/gtest.h>
#include <cstdint>
#include <vector>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"

TEST(lexerTests, HandlesOperators) {
    std::string op = "+";
    uint64_t expected_line = 1;
    uint64_t expected_column = 1;
    std::vector<Token> expectedOutput = {
        Token{TokenType::Plus, op, expected_line, expected_column}};

    tokenizing lexer;
    EXPECT_EQ(lexer.tokenize(op), expectedOutput)
        << "Handles Operators test failed.";
}
