cmake_minimum_required(VERSION 3.25)


project(IIL
    VERSION 1.0
    DESCRIPTION "Interesting Interpreted Language"
    LANGUAGES CXX
)

if(MINGW)
    set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)
    set(CMAKE_C_USE_RESPONSE_FILE_FOR_INCLUDES OFF)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
FetchContent_MakeAvailable(googletest)

# -----------------------------------
# LEXER LIBRARY:
# -----------------------------------

file(GLOB_RECURSE IIL_LEXER_SRC CONFIGURE_DEPENDS
    src/lexer/*.cpp
)

add_library(IIL_lexer STATIC
    ${IIL_LEXER_SRC}
)

target_include_directories(IIL_lexer PUBLIC
    ${CMAKE_SOURCE_DIR}/include/IIL
    ${CMAKE_SOURCE_DIR}/src/
)

# -----------------------------------
# MAIN: 
# -----------------------------------

file(GLOB_RECURSE IIL_SRC CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(IIL 
    ${IIL_SRC}
)

target_link_libraries(IIL PRIVATE IIL_lexer)

target_include_directories(IIL PRIVATE
    ${CMAKE_SOURCE_DIR}/include/IIL
    ${CMAKE_SOURCE_DIR}/src/
)

# -------------------------------------
# REPL: 
# -------------------------------------

file(GLOB_RECURSE IIL_REPL_SRC CONFIGURE_DEPENDS
    stdlib/REPL/*.cpp
)

file(GLOB_RECURSE ASCII_SRC CONFIGURE_DEPENDS
    external/ascii-art/*.cpp
)

add_library(ascii_art 
    ${ASCII_SRC}
)

target_include_directories(ascii_art PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/external/ascii-art
)

add_executable(IIL_REPL 
    ${IIL_REPL_SRC}
)

target_include_directories(IIL_REPL PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/stdlib/REPL/src
)

target_link_libraries(IIL_REPL PRIVATE
    ascii_art
    IIL_lexer
)

# -----------------------------------
# TESTING:
# -----------------------------------

enable_testing()
add_subdirectory(tests)

add_custom_target(all_tests DEPENDS 
    IIL_lexer_arithmetic_operators_test
    IIL_lexer_comparison_operators_test
    IIL_lexer_string_test
    IIL_lexer_number_test
    IIL_lexer_identifier_test
)