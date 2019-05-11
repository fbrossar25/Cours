sudo apt-get install g++-4.8
cmake . -DCMAKE_CXX_FLAGS="${CMAKE_CXX_FLAGS} -std=c++98"
make -j 6 CXX=g++-4.8
. install.sh