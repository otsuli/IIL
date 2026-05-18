#include "parser/parsing.hpp"
#include "parser/arena.hpp"
#include "parser/expr.hpp"
#include <memory>
#include <vector>

// The rule for comparison is:
// term ( ( ">"| ">=" | "<" | "<=" ) term )* ;
BinaryExpr expressionParsing::comparison() {
    BinaryExpr expr = term();

    while (match(Greater, GreaterEqual, Less, LessEqual)) {
        Token op = previous();
        BinaryExpr right = term();
        expr = arena.make<BinaryExpr>(std::move(expr), op, std::move(right));
    }
    return expr;
}

// Each method for parsing a grammar rule produces an AST for that rule and returns it to the
// caller. When the body of the rule contains a nonterminal (a reference to another rule). We call
// that other rule's method.
Token expressionParsing::previous() const { return tokens[current - 1]; }
Token expressionParsing::peek() const { return tokens[current]; }
auto expressionParsing::isAtEnd() const { return peek().type == TokenType::FileEnd; }

Token expressionParsing::advance() {
    if (!isAtEnd())
        current++;
    return previous();
}

// Check method returns true if the current token is of the given type.
bool expressionParsing::check(TokenType type) {
    if (isAtEnd()) {
        return false;
    }
    return (peek().type == type);
}

// The rule for equalitys is:
// Equality := comparison ( ( "!=" | "==") comparison)* ;
BinaryExpr *expressionParsing::equality() {
    // Call the first comparison as shown in the production rules.
    BinaryExpr *expr = arena.make<BinaryExpr>(comparison());

    // The (...)* loop in the rule is a while loop:
    // The rule states that we must find either a != or == token.
    // So if we don't see one of those, we are done with the sequence of equality
    // operators. We express that check using the match() method.
    while (match(TokenType::BangEqual, TokenType::EqualEqual)) {
        Token op = previous();

        auto right = comparison();
        // construct AST:
        expr = arena.make<BinaryExpr>(std::move(expr), op, std::move(right));
    }

    return expr;
}

// Expression expands to the equality rule.
// Expresson := equality;
BinaryExpr *expressionParsing::expression() { return equality(); }
