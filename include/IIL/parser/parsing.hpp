#pragma once
#include "lexer/tokens.hpp"
#include "parser/Expr.hpp"
#include "parser/parsing.hpp"
#include <vector>

class Parser {
    class expressionParsing {
        bool isAtEnd();
        bool check(TokenType type);

        template <typename... Types> 
        // Check if the current token has any of the given types. If it does we consume the token and reutrn true. 
        // Else it returns false and leaves the token alone. 
        // The match() method is defined in terms of two ore more fundemental operations
        bool match(Types... types) {
            return (check(types) && (advance(), true)
        }

        std::unique_ptr<Expr> equality();
        std::unique_ptr<Expr> expression(); // Unique_ptr is used because an astNode belongs to
                                            // exactly one parent.
    };
};
