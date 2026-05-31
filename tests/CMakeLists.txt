# Note that IIL uses cmake_format for formatting it's cmake files. Install it
# with: pip install cmakelang

# ------------------------------------
# TESTING:
# ------------------------------------

enable_testing()

# -----------------------------------
# ARITHMETIC:
# -----------------------------------

add_executable(IIL_lexer_arithmetic_operators_test
               lexer_tests/arithmeticOperators.cpp)

target_link_libraries(IIL_lexer_arithmetic_operators_test
                      PRIVATE GTest::gtest_main IIL_lexer)

add_test(NAME lexer_test_arithmetic COMMAND IIL_lexer_arithmetic_operators_test)

# --------------------------------
# COMPARISON:
# --------------------------------

add_executable(IIL_lexer_comparison_operators_test
               lexer_tests/comparisonOperators.cpp)

target_link_libraries(IIL_lexer_comparison_operators_test
                      PRIVATE GTest::gtest_main IIL_lexer)

add_test(NAME lexer_test_comparison COMMAND IIL_lexer_comparison_operators_test)

# -------------------
# STRINGS:
# -------------------

add_executable(IIL_lexer_string_test lexer_tests/stringTest.cpp)

target_link_libraries(IIL_lexer_string_test PRIVATE GTest::gtest_main IIL_lexer)

add_test(NAME lexer_test_string COMMAND IIL_lexer_string_test)

# ----------------
# NUMBERS:
# ----------------

add_executable(IIL_lexer_number_test lexer_tests/numberTest.cpp)

target_link_libraries(IIL_lexer_number_test PRIVATE GTest::gtest_main IIL_lexer)

add_test(NAME lexer_test_number COMMAND IIL_lexer_number_test)

# ----------------
# IDENTIFIERS:
# ----------------

add_executable(IIL_lexer_identifier_test lexer_tests/identifierTest.cpp)

target_link_libraries(IIL_lexer_identifier_test PRIVATE GTest::gtest_main
                                                        IIL_lexer)

add_test(NAME lexer_test_identifier COMMAND IIL_lexer_identifier_test)

# ---------------
# DELIMITERS:
# ---------------

add_executable(IIL_lexer_delimiter_test lexer_tests/delimiterTest.cpp)

target_link_libraries(IIL_lexer_delimiter_test PRIVATE GTest::gtest_main
                                                       IIL_lexer)

add_test(NAME lexer_test_delimiter COMMAND IIL_lexer_delimiter_test)

# --------------
# KEYWORDS:
# --------------

add_executable(IIL_lexer_keyword_test lexer_tests/keywordTest.cpp)

target_link_libraries(IIL_lexer_keyword_test PRIVATE GTest::gtest_main
                                                     IIL_lexer)

add_test(NAME lexer_test_keyword COMMAND IIL_lexer_keyword_test)

# ------------
# WHITESPACE:
# ------------
add_executable(IIL_lexer_whitespace_test lexer_tests/handlesWhiteSpace.cpp)

target_link_libraries(IIL_lexer_whitespace_test PRIVATE GTest::gtest_main
                                                        IIL_lexer)

add_test(NAME lexer_test_whitespace COMMAND IIL_lexer_whitespace_test)
