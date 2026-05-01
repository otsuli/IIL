cmake_minimum_required(VERSION 3.10)

project(IIL
    VERSION 1.0
    DESCRIPTION "Interesting Interpreted Language"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(IIL
    src/main.cpp
    src/lexer/tokenization.cpp
    src/lexer/utils/isDelimiter.cpp
    src/lexer/utils/isNumber.cpp
    src/lexer/utils/isSkippable.cpp
    src/lexer/utils/shift.cpp
    src/parser/errors/errorRoutines.cpp
    src/parser/errors/parserError.cpp
    src/parser/utils/helperRoutines.cpp
    src/parser/AST.cpp
)

target_include_directories(IIL PRIVATE
    ${CMAKE_SOURCE_DIR}/include/IIL
    ${CMAKE_SOURCE_DIR}/src/lexer/utils/include
    ${CMAKE_SOURCE_DIR}/src/parser/errors/include
    ${CMAKE_SOURCE_DIR}/src/parser/utiles/include
)