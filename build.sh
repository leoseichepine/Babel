mkdir -p build
cd build
conan install .. --build=opus --build=missing
cmake .. -G "Unix Makefiles"
cmake –build .
make
mv ./bin/babel_server ../
mv ./bin/babel_client ../