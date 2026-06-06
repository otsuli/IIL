# Note that IIL uses cmake_format for formatting it's cmake files. Install it
# with: pip install cmakelang

cmake_minimum_required(VERSION 3.25)

project(
  IIL
  VERSION 1.0
  DESCRIPTION "Interesting Interpreted Language"
  LANGUAGES CXX)

if(MINGW)
  set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)
  set(CMAKE_C_USE_RESPONSE_FILE_FOR_INCLUDES OFF)
endif()

set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)
set(BUILD_TESTING
    OFF
    CACHE BOOL "" FORCE)
set(INSTALL_GTEST
    OFF
    CACHE BOOL "" FORCE)

set(BENCHMARK_ENABLE_TESTING
    OFF
    CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS
    OFF
    CACHE BOOL "" FORCE)

# Now add the directories safely
add_subdirectory(external/googletest)
add_subdirectory(external/benchmark)

set(BUILD_TESTING
    ON
    CACHE BOOL "" FORCE)
enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------------
# LEXER LIBRARY:
# -----------------------------------

file(GLOB_RECURSE IIL_LEXER_SRC CONFIGURE_DEPENDS src/lexer/*.cpp)

add_library(IIL_lexer STATIC ${IIL_LEXER_SRC})

target_include_directories(IIL_lexer PUBLIC ${CMAKE_SOURCE_DIR}/include/IIL
                                            ${CMAKE_SOURCE_DIR}/src/)

# -----------------------------------
# MAIN:
# -----------------------------------

file(GLOB_RECURSE IIL_SRC CONFIGURE_DEPENDS src/*.cpp)

add_executable(IIL ${IIL_SRC})

target_link_libraries(IIL PRIVATE IIL_lexer)

target_include_directories(IIL PRIVATE ${CMAKE_SOURCE_DIR}/include/IIL
                                       ${CMAKE_SOURCE_DIR}/src/)

# -------------------------------------
# REPL:
# -------------------------------------

file(GLOB_RECURSE ASCII_SRC CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/external/ascii-art/*.cpp)

add_library(ascii_art INTERFACE)
add_subdirectory(stdlib/REPL)
add_custom_target(IIL_STDLIB_REPL DEPENDS IIL_REPL)

# -----------------------------------
# TESTING:
# -----------------------------------

enable_testing()
add_subdirectory(tests)

add_custom_target(
  all_tests
  DEPENDS IIL_lexer_arithmetic_operators_test
          IIL_lexer_comparison_operators_test
          IIL_lexer_string_test
          IIL_lexer_number_test
          IIL_lexer_identifier_test
          IIL_lexer_delimiter_test
          IIL_lexer_keyword_test
          IIL_lexer_whitespace_test
          IIL_lexer_single_line_comments_test
          IIL_lexer_multi_line_comments_test
          IIL_lexer_delimiter_seperation_test)
