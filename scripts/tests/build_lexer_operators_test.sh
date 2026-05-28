echo "building lexer test"

# -S . means source directory
# -B build means build directory

cmake -S .. -B build
cmake --build build --target IIL_lexer_operators_test
ctest --test-dir build --output-on-failure