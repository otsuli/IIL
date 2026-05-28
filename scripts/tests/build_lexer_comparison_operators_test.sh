echo "building lexer test"

# -S . means source directory
# -B build means build directory

cmake -DCMAKE_BUILD_TYPE=Debug -S .. -B build 
cmake --build build --target IIL_lexer_comparison_operators_test
ctest --test-dir build --output-on-failure