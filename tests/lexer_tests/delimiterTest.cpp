#include <gtest/gtest.h>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

TEST(lexerTests, HandlesDelimiterSemiColon) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break lexerTests_HandlesDelimiterSemiColon_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesDelimiterSemiColon

    const auto delimiter = std::make_unique<std::string>(";");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::semicolon, *delimiter,
                                  expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(delimiter), *expectedOutput)
        << "Handles SemiColon test failed";
}

TEST(lexerTests, HandlesDelimiterComma) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break lexerTests_HandlesDelimiterComma_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesDelimiterComma

    const auto delimiter = std::make_unique<std::string>(",");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::comma, *delimiter, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(delimiter), *expectedOutput)
        << "Handles Comma test failed";
}

TEST(lexerTests, HandlesDelimiterNewLine) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break lexerTests_HandlesDelimiterNewLine_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesDelimiterNewLine

    const auto delimiter = std::make_unique<std::string>("\n");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::newline, *delimiter, expected_line,
                                  expected_column);
    Token EOFTok =
        Token::make_token(TokenType::FileEnd, "fileEnd", expected_line + 2,
                          expected_column);  // expected_line + 2 because it's a
                                             // newline character.
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(delimiter), *expectedOutput)
        << "Handles NewLine test failed";
}

TEST(lexerTests, HandlesDelimiterColon) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break lexerTests_HandlesDelimiterColon_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesDelimiterColon

    const auto delimiter = std::make_unique<std::string>(":");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::colon, *delimiter, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(delimiter), *expectedOutput)
        << "Handles Colon test failed";
}

TEST(lexerTests, HandlesDelimiterOpenParen) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break lexerTests_HandlesDelimiterOpenParen_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesDelimiterOpenParen

    const auto delimiter = std::make_unique<std::string>("(");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::OpenParen, *delimiter,
                                  expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(delimiter), *expectedOutput)
        << "Handles OpenParen test failed";
}

TEST(lexerTests, HandlesDelimiterCloseParen) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break lexerTests_HandlesDelimiterCloseParen_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesDelimiterOpenParen

    const auto delimiter = std::make_unique<std::string>(")");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::CloseParen, *delimiter,
                                  expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(delimiter), *expectedOutput)
        << "Handles CloseParen test failed";
}

TEST(lexerTests, HandlesDelimiterIndent) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break lexerTests_HandlesDelimiterIndent_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesDelimiterIndent

    const auto delimiter = std::make_unique<std::string>("\t");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::Indent, *delimiter, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(delimiter), *expectedOutput)
        << "Handles Indent test failed";
}