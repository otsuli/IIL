#include <gtest/gtest.h>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

TEST(lexerTests, HandlesNumber) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break lexerTests_HandlesNumber_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesNumber

    const auto string = std::make_unique<std::string>("1312");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::Number, std::stoi(*string),
                                  expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    Tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(string), *expectedOutput)
        << "Handles Numbers test failed";
}