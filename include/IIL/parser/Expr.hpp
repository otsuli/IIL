#pragma once
#include <memory>

// Forward declarations:
struct Token;
namespace null {
inline const Token* nullToken;

// These are AST nodes:
struct Expr {
    virtual ~Expr() = default;
};

struct BinaryExpr : public Expr {
    Expr* left_;
    Expr* right_;
    const Token* op_;

    BinaryExpr(Expr& left, Expr& right, Token& op);
};

struct UnaryExpr : public Expr {
    const Token* op_;
    Expr* right_;
};
struct PrimaryExpr : public Expr {
    const Token* op_;
    Expr* right_;
};

struct Literal : public Expr {
    const Token* value_;
    Literal(Token& value);
    Literal();
};
struct Grouping : public Expr {
    // Contained expression is the inner node for the exprtession contained
    // inside the parentheses
    Expr* contained_expression_;
    Grouping();
};
