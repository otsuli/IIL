#include "exceptions/exceptions.hpp"
#include "interpreter/interpreter.hpp"

class IIL {
   public:
    static Interpreter* interpreter;
    inline static bool hadRunTimeError = false;
    static void runtimeError(IILException& error);
};