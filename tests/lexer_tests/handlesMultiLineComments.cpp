#include <gtest/gtest.h>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

TEST(lexerTests, HandlesMultiLineComments) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break lexerTests_HandlesMultiLineComments_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesMultiLineComments

    const auto string = std::make_unique<std::string>(
        "\"This is a string\" ### \n This Comment should be ignored \n ###");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::String, "\"This is a string\"",
                                  expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(string), *expectedOutput)
        << "Handles MultiLineComments test failed.";
}