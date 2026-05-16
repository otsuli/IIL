#include "parser/parsing.hpp"
#include "parser/utils/helperRoutines.hpp"
#include <memory>
#include <vector>
// Each method for parsing a grammar rule produces an AST for that rule and returns it to the
// caller. When the body of the rule contains a nonterminal (a reference to another rule). We call
// that other rule's method.

bool Parser::expressionParsing::check(TokenType type) {
    if (isAtEnd()) {
        return false;
    }
    return (peek().type == type)
}

// The rule for equalitys is:
// Equality := comparison ( ( "!=" | "==") comparison)* ;
std::unique_ptr<Expr> Parser::expressionParsing::equality() {
    // Call the first comparison as shown in the production rules.
    std::unique_ptr<Expr> expr = comparison();

    // The (...)* loop in the rule is a while loop:
    // The rule states that we must find either a != or == token.
    // So if we don't see one of those, we are done with the sequence of equality operators.
    // We express that check using the match() method.
    while (match(TokenType::BangEqual, EqualEqual)) {
        Token operator= previous();

        auto right = comparison();
        expr = std::make_unique <
    }
}

// Expression expands to the equality rule.
// Expresson := equality;
std::unique_ptr<Expr> Parser::expressionParsing::expression() { return equality(); }