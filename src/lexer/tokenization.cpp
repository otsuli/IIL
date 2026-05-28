#include "lexer/tokenization.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <variant>
#include <vector>
#include "lexer/stringPool.hpp"
#include "lexer/tokens.hpp"
#include "lexer/utils/isDelimiter.hpp"
#include "lexer/utils/isNumber.hpp"
#include "lexer/utils/isSkippable.hpp"
#include "lexer/utils/shift.hpp"

std::vector<std::string> tokenizing::splitString(
    const std::unique_ptr<std::string>& source) {

    std::vector<std::string> chunks;
    std::string buffer;
    std::string val;

    for (int i = 0; i < source->size(); i++) {
        char ch = (*source)[i];
        if (ch == '"') {
            std::string buf;
            buf = buf + (*source)[i];
            for (int k = i; i < source->size(); ++k) {
                if ((*source)[k] == '"') {
                    buf = buf + (*source)[k];
                    chunks.emplace_back(buf);
                    break;
                } else if ((*source)[k + 1] > source->size()) {
                    //! Log error
                }
                buf = buf + '"';
            }
        }

        else if (utils::isDelimiter(
                     ch)) {  // split the strings based off some parameters.
            if (!buffer.empty()) {
                chunks.emplace_back(std::move(buffer));  // push the buffer
            }
            chunks.emplace_back(
                std::string(1, ch));  // push the actual delimiter
        }

        else if (ch == ' ') {
            if (!buffer.empty()) {
                chunks.emplace_back(std::move(buffer));
            }
        }

        else if (ch == '#' && i + 1 < source->size() &&
                 (*source)[i + 1] == '#' && i + 2 < source->size() &&
                 (*source)[i + 2] == '#') {
            if (!buffer.empty()) {
                chunks.emplace_back(std::move(buffer));
            }
            i += 3;  // skip first 3 hashtags
            while (i + 2 < source->size() &&
                   !((*source)[i] == '#' && (*source)[i + 1] == '#' &&
                     (*source)[i + 2] == '#')) {
                i++;
            }
            if (i + 2 >= source->size()) {
                //! Implement error handling
            }
            i += 3;  // skip last 3 hashtags
        }

        else if (ch == '#' && i + 1 < source->size() &&
                 (*source)[i + 1] == '#') {

            if (!buffer.empty()) {
                chunks.emplace_back(std::move(buffer));
            }
            while (i < source->size() && (*source)[i] != '\n') {
                i++;
            }
            continue;
        }

        else {
            buffer += ch;
        }
    }

    if (!buffer.empty()) {
        chunks.emplace_back(std::move(buffer));
    }

    return chunks;
}

std::vector<Token> tokenizing::tokenize(
    const std::unique_ptr<std::string>& sourceCode) {

    std::vector<Token> tokens;
    std::vector<std::string> src = splitString(sourceCode);
    line = 1;  // Reset each function call
    column = 1;
    TokenProcessor process;

    while (!src.empty()) {

        Token tempTok = process.processTokenVal(&src.front(), line, column);
        auto* str_ptr = std::get_if<std::string>(&tempTok.value_);

        if (src.front().length() < 1) {
            switch (src.front()[0]) {
                // ----------------------
                // DELIMITERS:
                // ----------------------
                case ';':
                    tokens.emplace_back(TokenType::semicolon, src.front()[0],
                                        line, column);
                    utils::shift(src);
                    column++;
                    break;
                case ',':
                    tokens.emplace_back(TokenType::comma, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;
                case '\n':
                    tokens.emplace_back(TokenType::newline, src.front()[0],
                                        line, column);
                    line++;
                    column = 1;
                    utils::shift(src);
                    break;
                case ':':
                    tokens.emplace_back(TokenType::colon, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;
                case '(':
                    tokens.emplace_back(TokenType::OpenParen, src.front()[0],
                                        line, column);
                    utils::shift(src);
                    column++;
                    break;
                case ')':
                    tokens.emplace_back(TokenType::CloseParen, src.front()[0],
                                        line, column);
                    utils::shift(src);
                    column++;
                    break;
                // ---------------------------
                // INDENTS:
                // ---------------------------
                case '\t':
                    tokens.emplace_back(TokenType::Indent, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;
                // ----------------------------
                // COMPARISONS:
                // Note other comparisons are found in stringpooling.
                // ----------------------------
                case '>':
                    tokens.emplace_back(TokenType::Greater, src.front()[0],
                                        line, column);
                    utils::shift(src);
                    column++;
                    break;
                case '<':
                    tokens.emplace_back(TokenType::Less, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;

                // ---------------------------
                // ASSIGNMENT:
                // ---------------------------
                case '=':
                    tokens.emplace_back(TokenType::equal, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;
                // ---------------------------
                // OTHER OPERATORS:
                // ---------------------------
                case '-':
                    tokens.emplace_back(TokenType::Minus, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;
                case '+':
                    tokens.emplace_back(TokenType::Plus, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;
                case '*':
                    tokens.emplace_back(TokenType::Star, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;
                case '!':
                    tokens.emplace_back(TokenType::Bang, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;
                case '/':
                    tokens.emplace_back(TokenType::Slash, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;
                case '%':
                    tokens.emplace_back(TokenType::Modulo, src.front()[0], line,
                                        column);
                    utils::shift(src);
                    column++;
                    break;
                default:
                    break;
            }
        }

        else if (src.front()[0] = '"') {
            tokens.emplace_back(TokenType::String, src.front(), line, column);
            column++;
            utils::shift(src);
        }

        else if (str_ptr) {
            if (!str_ptr->empty()) {
                if (tempTok != null::nullToken) {
                    tokens.emplace_back(tempTok);
                    column++;
                    utils::shift(src);
                }
            }
        } else if (utils::isSkippable(src.front()[0])) {
            utils::shift(src);
        } else if (utils::isNumber(src.front())) {
            int number;

            while (!src.empty() && utils::isNumber(src.front())) {
                number += std::stoi(utils::shift(src));
            }
            tokens.emplace_back(TokenType::Number, number, line, column);
        } else {
            tokens.emplace_back(TokenType::Identifier, utils::shift(src), line,
                                column);
            column++;
            utils::shift(src);
        }
    }
    tokens.emplace_back(TokenType::FileEnd, "fileEnd", line, column);
    return tokens;
}
