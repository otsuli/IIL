#include <string>
#include <variant>
#include "parser/expr.hpp"

// Object type is used to store multiple different datatypes
// so we can make returned values objects of any type.

using Object = std::variant<double, std::string, bool, std::nullptr_t, Token,
                            Expr, UnaryExpr, Grouping, Literal>;

class Interpreter {
    Object evaluate(Expr* expr);
    bool isTruthy(Object object);

   public:
    Object visitLiteralExpr(Literal* expr);
    Object visitGroupingExpr(Grouping* expr);
    Object visitUnaryExpr(UnaryExpr* expr);
};