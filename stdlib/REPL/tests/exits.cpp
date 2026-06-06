#include <gtest/gtest.h>
#include <sstream>
#include "IILREPL.hpp"

TEST(IILREPLTest, ExitsImmediately) {
    IILREPL repl;

    std::stringstream input("exit\n");

    EXPECT_NO_THROW(repl.runREPL(input));
}