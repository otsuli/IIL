#include <gtest/gtest.h>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"
#include "types.hpp"

TEST(lexerTests, HandlesKeywordIvar) {
    // GDB COMMANDS :/ (for when you need to debug *cry* )
    // break LexerTest_BasicTokens_Test::TestBody()
    // run --gtest_filter=lexerTests.HandlesKeywordIvar

    const auto keyword = std::make_unique<std::string>("ivar");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::ivar, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);
    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);
    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles ivar test failed.";
}

TEST(lexerTests, HandlesKeywordIglobal) {
    const auto keyword = std::make_unique<std::string>("iglobal");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::iglobal, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles iglobal test failed.";
}

TEST(lexerTests, HandlesKeywordIfStatement) {
    const auto keyword = std::make_unique<std::string>("if");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::ifstatement, *keyword,
                                  expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles if statement test failed.";
}

TEST(lexerTests, HandlesKeywordElseStatement) {
    const auto keyword = std::make_unique<std::string>("else");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::elsestatement, *keyword,
                                  expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles else statement test failed.";
}

TEST(lexerTests, HandlesKeywordElseIfStatement) {
    const auto keyword = std::make_unique<std::string>("eif");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::elseifstatement, *keyword,
                                  expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles elseif statement test failed.";
}

TEST(lexerTests, HandlesKeywordDoStatement) {
    const auto keyword = std::make_unique<std::string>("do");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::dostatement, *keyword,
                                  expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles do statement test failed.";
}

TEST(lexerTests, HandlesKeywordIwhile) {
    const auto keyword = std::make_unique<std::string>("iwhile");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::iwhile, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles iwhile test failed.";
}

TEST(lexerTests, HandlesKeywordIend) {
    const auto keyword = std::make_unique<std::string>("iend");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::iend, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles iend test failed.";
}

TEST(lexerTests, HandlesKeywordIexit) {
    const auto keyword = std::make_unique<std::string>("iexit");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::iexit, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles iexit test failed.";
}

TEST(lexerTests, HandlesKeywordIfor) {
    const auto keyword = std::make_unique<std::string>("ifor");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::ifor, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles ifor test failed.";
}

TEST(lexerTests, HandlesKeywordIBreak) {
    const auto keyword = std::make_unique<std::string>("ibreak");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::ibreak, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles ibreak test failed.";
}

TEST(lexerTests, HandlesKeywordITry) {
    const auto keyword = std::make_unique<std::string>("itry");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::itry, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles itry test failed.";
}

TEST(lexerTests, HandlesKeywordIExcept) {
    const auto keyword = std::make_unique<std::string>("iexcept");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::iexcept, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles iexcept test failed.";
}

TEST(lexerTests, HandlesKeywordIFinally) {
    const auto keyword = std::make_unique<std::string>("ifinally");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::ifinally, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles ifinally test failed.";
}

TEST(lexerTests, HandlesKeywordIExplode) {
    const auto keyword = std::make_unique<std::string>("iexplode");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::iexplode, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles iexplode test failed.";
}

TEST(lexerTests, HandlesKeywordIFunc) {
    const auto keyword = std::make_unique<std::string>("ifunc");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::ifunc, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles ifunc test failed.";
}

TEST(lexerTests, HandlesKeywordIReturn) {
    const auto keyword = std::make_unique<std::string>("ireturn");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::ireturn, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles ireturn test failed.";
}

TEST(lexerTests, HandlesKeywordTrue) {
    const auto keyword = std::make_unique<std::string>("True");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::True, *keyword, expected_line,
                                  expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles True test failed.";
}

TEST(lexerTests, HandlesKeywordIException) {
    const auto keyword = std::make_unique<std::string>("iexception");
    const u16 expected_line = 1;
    const u16 expected_column = 1;

    Token tok = Token::make_token(TokenType::iexception, *keyword,
                                  expected_line, expected_column);
    Token EOFTok = Token::make_token(TokenType::FileEnd, "fileEnd",
                                     expected_line + 1, expected_column);

    const std::unique_ptr<std::vector<Token>> expectedOutput =
        std::make_unique<std::vector<Token>>();
    expectedOutput->push_back(tok);
    expectedOutput->push_back(EOFTok);

    tokenizing lexer;

    EXPECT_EQ(lexer.tokenize(keyword), *expectedOutput)
        << "Handles iexception test failed.";
}