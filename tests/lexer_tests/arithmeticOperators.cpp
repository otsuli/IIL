#include <gtest/gtest.h>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

TEST(lexerTests, HandlesPlusOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody
    // run --gtest_filter=lexerTests.HandlesPlusOperator

    const auto op = std::make_unique<std::string>("+");
    const u16 expected_line = 1;
    const u16 expected_column = 1;
    Token tok =
        Token::make_token(TokenType::Plus, *op, expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();

    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles Operators test failed.";
}

TEST(lexerTests, HandlesSubtractionOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody
    // run --gtest_filter=lexerTests.HandlesSubtractionOperator

    const auto op = std::make_unique<std::string>("-");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::Minus, *op, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles Subtraction Operators test failed.";
}

TEST(lexerTests, HandlesDivisionOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody
    // run --gtest_filter=lexerTests.HandlesDivisionOperator

    const auto op = std::make_unique<std::string>("/");
    const u16 expected_line = 1;
    const u16 expected_column = 1;
    Token tok = Token::make_token(TokenType::Slash, *op, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles Division Operators test failed.";
}

TEST(lexerTests, HandlesMultiplicationOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody
    // run --gtest_filter=lexerTests.HandlesMultiplicationOperator

    const auto op = std::make_unique<std::string>("*");
    const u16 expected_line = 1;
    const u16 expected_column = 1;
    Token tok =
        Token::make_token(TokenType::Star, *op, expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();

    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles Mutliplication Operators test failed.";
}

TEST(lexerTests, HandlesModuloOperator) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody
    // run --gtest_filter=lexerTests.HandlesModuloOperator

    const auto op = std::make_unique<std::string>("%");
    const u16 expected_line = 1;
    const u16 expected_column = 1;
    Token tok = Token::make_token(TokenType::Modulo, *op, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();

    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(op), *expectedOutput)
        << "Handles Mutliplication Operators test failed.";
}

//! Add floor division operator.