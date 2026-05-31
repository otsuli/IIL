#include <gtest/gtest.h>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

TEST(lexerTests, HandlesWhitespace) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break lexerTests_HandlesWhitespace_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesWhitespace

    const auto keywords = std::make_unique<std::string>("ivar iexplode");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok1 = Token::make_token(TokenType::ivar, "ivar", expected_line,
                                   expected_column);
    Token tok2 = Token::make_token(TokenType::iexplode, "iexplode",
                                   expected_line, expected_column + 1);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok1);
    expectedOutput->push_back(tok2);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keywords), *expectedOutput)
        << "Handles whitespace test failed.";
}