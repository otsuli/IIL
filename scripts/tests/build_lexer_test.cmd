echo "building REPL"

REM -S . means the source directory is the current folder
REM -B  means put the generated build files the build/ folder

cmake -DCMAKE_BUILD_TYPE=Debug -S .. -B build 
cmake --build build --target IIL_lexer_test 
ctest --test-dir build --output-on-failure