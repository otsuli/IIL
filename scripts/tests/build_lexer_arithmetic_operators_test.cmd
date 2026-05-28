echo "building lexer test"

REM -S . means source directory
REM -B build means build directory

cmake -DCMAKE_BUILD_TYPE=Debug -S .. -B build 
cmake --build build --target IIL_lexer_arithmetic_operators_test
ctest --test-dir build --output-on-failure