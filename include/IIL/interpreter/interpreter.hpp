#include <string>
#include <variant>
#include "parser/expr.hpp"

// Object type is used to store multiple different datatypes
// so we can make returned values objects of any type.
struct Token;
using Object =
    std::variant<double, std::string, bool, std::nullptr_t, Token, Expr>;

class Interpreter {
   private:
    Object evaluate(Expr* expr);
    bool isTruthy(Object* object);
    bool isEqual(const Object* a, const Object* b);

    void checkNumberOperands(const Token& oper, const Object& left_operand,
                             const Object& right_operand);
    void checkNumberOperand(const Token& oper, const Object& operand);

    std::string stringify(Object& object);

   public:
    Object visitLiteralExpr(Literal* expr);
    Object visitGroupingExpr(Grouping* expr);
    Object visitUnaryExpr(UnaryExpr* expr);
    Object visitBinaryExpr(BinaryExpr* expr);

    void interpret(const Expr& expression);
};