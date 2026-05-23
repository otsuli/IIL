#include "lexer/tokenization.hpp"
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include "lexer/stringPool.hpp"
#include "lexer/tokens.hpp"
#include "lexer/utils/isDelimiter.hpp"
#include "lexer/utils/isNumber.hpp"
#include "lexer/utils/isSkippable.hpp"
#include "lexer/utils/shift.hpp"

// TODO: Tokenizing need to be rewritten completely:

std::vector<std::string> tokenizing::splitString() {
    std::vector<std::string> chunks;
    std::string buffer;
    std::string val;

    for (int i = 0; i < source.size(); i++) {
        char ch = source[i];
        if (ch == '"') {
            std::string buf;
            buf = buf + source[i];
            for (int k = i; i < source.size(); ++k) {
                if (source[k] == '"') {
                    buf = buf + source[k];
                    chunks.push_back(buf);
                    break;
                }
                buf = buf + '"';
            }
        }

        else if (utils::isDelimiter(
                     ch)) {  // split the strings based off some parameters.
            if (!buffer.empty()) {
                chunks.push_back(buffer);  // push the buffer
                buffer.clear();
            }
            chunks.push_back(std::string(1, ch));  // push the actual delimiter
        }

        else if (ch == ' ') {
            if (!buffer.empty()) {
                chunks.push_back(buffer);
                buffer.clear();
            }
        }

        else if (ch == '#' && i + 1 < source.size() && source[i + 1] == '#' &&
                 i + 2 < source.size() && source[i + 2] == '#') {
            if (!buffer.empty()) {
                chunks.push_back(buffer);
                buffer.clear();
            }
            i += 3;  // skip first 3 hashtags
            while (i + 2 < source.size() &&
                   !(source[i] == '#' && source[i + 1] == '#' &&
                     source[i + 2] == '#')) {
                i++;
            }
            if (i + 2 >= source.size()) {
                //! Implement error handling
            }
            i += 3;  // skip last 3 hashtags
        }

        else if (ch == '#' && i + 1 < source.size() && source[i + 1] == '#') {

            if (!buffer.empty()) {
                chunks.push_back(buffer);
                buffer.clear();
            }
            while (i < source.size() && source[i] != '\n') {
                i++;
            }
            continue;
        }

        else {
            buffer += ch;
        }
    }

    if (!buffer.empty()) {
        chunks.push_back(buffer);
    }

    return chunks;
}

std::vector<Token> tokenizing::tokenize(std::string& sourceCode) {
    source = sourceCode;
    std::vector<Token> tokens;
    std::vector<std::string> src = splitString();
    line = 1;  // Reset each function call
    column = 1;

    while (!src.empty()) {
        switch (src.front()[0] && src.front().length() < 1) {
            case ';':
                tokens.emplace_back(TokenType::semicolon, src.front()[0], line,
                                    column);
                break;
            case ',':
                tokens.emplace_back(TokenType::comma, src.front()[0], line,
                                    column);
                break;
            case '\n':
                tokens.emplace_back(TokenType::newline, src.front()[0], line,
                                    column);
                break;
            case ':':
                tokens.emplace_back(TokenType::colon, src.front()[0], line,
                                    column);
                break;
            default:
                break;
        }

        TokenProcessor process;
        Token tempTok = process.processTokenVal(&src.front(), line, column);

        if (tempTok != nullToken) {
            tokens.emplace_back(tempTok);
            column++;
        } else if (src.front() == "\n") {
            line++;
            column = 1;
            utils::shift(src);
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
