#include <gtest/gtest.h>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

TEST(lexerTests, HandlesGreaterOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesGreaterOperator

    const auto op = std::make_unique<std::string>(">");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::Greater, *op, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles Greater Operators test failed.";
}

TEST(lexerTests, HandlesLessOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesLessOperator

    const auto op = std::make_unique<std::string>("<");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok =
        Token::make_token(TokenType::Less, *op, expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles Less Operators test failed.";
}

TEST(lexerTests, HandlesEqualOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesEqualOperator

    const auto op = std::make_unique<std::string>("=");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::equal, *op, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles Equal Operators test failed.";
}

TEST(lexerTests, HandlesEqualEqualOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesEqualEqualOperator

    const auto op = std::make_unique<std::string>("==");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::EqualEqual, *op, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles EqualEqual Operators test failed.";
}

TEST(lexerTests, HandlesNotEqualOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesNotEqualOperator

    const auto op = std::make_unique<std::string>("!=");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::BangEqual, *op, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles NotEqual Operators test failed.";
}

TEST(lexerTests, HandlesGreaterEqualOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesGreaterEqualOperator

    const auto op = std::make_unique<std::string>(">=");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::GreaterEqual, *op, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles greater equal Operators test failed.";
}

TEST(lexerTests, HandlesLessEqualOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesLessEqualOperator

    const auto op = std::make_unique<std::string>("<=");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::LessEqual, *op, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles less equal Operators test failed.";
}
