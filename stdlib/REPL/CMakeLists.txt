# Note that IIL uses cmake_format for formatting it's cmake files. Install it
# with: pip install cmakelang

# -------------------------------------
# REPL:
# -------------------------------------

file(GLOB_RECURSE IIL_REPL_SRC CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/stdlib/REPL/*.cpp)

add_executable(IIL_REPL ${IIL_REPL_SRC})

target_include_directories(ascii_art
                           INTERFACE ${CMAKE_SOURCE_DIR}/external/ascii-art)
target_link_libraries(IIL_REPL PRIVATE ascii_art)
