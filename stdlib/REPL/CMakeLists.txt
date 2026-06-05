# Note that IIL uses cmake_format for formatting it's cmake files. Install it
# with: pip install cmakelang

# -------------------------------------
# REPL:
# -------------------------------------

file(GLOB_RECURSE IIL_REPL_SRC CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/stdlib/REPL/*.cpp)

file(GLOB_RECURSE ASCII_SRC CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/external/ascii-art/*.cpp)

add_library(ascii_art ${ASCII_SRC})

target_include_directories(
  ascii_art PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/ascii-art)

add_executable(IIL_REPL ${IIL_REPL_SRC})

target_include_directories(IIL_REPL
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/stdlib/REPL/src)

target_link_libraries(IIL_REPL PRIVATE ascii_art IIL_lexer)
