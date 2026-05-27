#include <gtest/gtest.h>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

TEST(lexerTests, HandlesOperators) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody
    // run --gtest_filter=lexerTests.HandlesOperators

    auto op = std::make_unique<std::string>("+");
    u16 expected_line = 1;
    u16 expected_column = 1;

    std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>(TokenType::Plus, *op,
                                             expected_line, expected_column);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), expectedOutput)
        << "Handles Operators test failed.";
}
