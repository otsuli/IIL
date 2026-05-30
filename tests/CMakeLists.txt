# ------------------------------------
# TESTING:
# ------------------------------------


enable_testing()

# -----------------------------------
# ARITHMETIC:
# -----------------------------------

add_executable(IIL_lexer_arithmetic_operators_test
    lexer_tests/arithmeticOperators.cpp
)

target_link_libraries(IIL_lexer_arithmetic_operators_test PRIVATE
    GTest::gtest_main
    IIL_lexer
)

add_test(NAME lexer_test_arithmetic COMMAND IIL_lexer_arithmetic_operators_test)

# --------------------------------
# COMPARISON:
# --------------------------------

add_executable(IIL_lexer_comparison_operators_test
    lexer_tests/comparisonOperators.cpp
)

target_link_libraries(IIL_lexer_comparison_operators_test PRIVATE
    GTest::gtest_main
    IIL_lexer
)

add_test(NAME lexer_test_comparison COMMAND IIL_lexer_comparison_operators_test)

# -------------------
# STRINGS:
# -------------------

add_executable(IIL_lexer_string_test
    lexer_tests/stringTest.cpp
)

target_link_libraries(IIL_lexer_string_test PRIVATE
    GTest::gtest_main
    IIL_lexer
)

add_test(NAME lexer_test_string COMMAND IIL_lexer_string_test)

# ----------------
# NUMBERS: 
# ----------------

add_executable(IIL_lexer_number_test
    lexer_tests/numberTest.cpp
)

target_link_libraries(IIL_lexer_number_test PRIVATE
    GTest::gtest_main
    IIL_lexer
)

add_test(NAME lexer_test_number COMMAND IIL_lexer_number_test)

# ----------------
# IDENTIFIERS: 
# ----------------

add_executable(IIL_lexer_identifier_test
    lexer_tests/identifierTest.cpp
)

target_link_libraries(IIL_lexer_identifier_test PRIVATE
    GTest::gtest_main
    IIL_lexer
)

add_test(NAME lexer_test_identifier COMMAND IIL_lexer_identifier_test)

