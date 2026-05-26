#include <gtest/gtest.h>
#include <cstdint>
#include <vector>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

TEST(lexerTests, HandlesOperators) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody
    // run --gtest_filter=lexerTests.HandlesOperators

    std::string op = "+";
    u16 expected_line = 1;
    u16 expected_column = 1;
    std::vector<Token> expectedOutput = {
        Token{TokenType::Plus, op, expected_line, expected_column}};

    tokenizing lexer;
    EXPECT_EQ(lexer.tokenize(op), expectedOutput)
        << "Handles Operators test failed.";
}
