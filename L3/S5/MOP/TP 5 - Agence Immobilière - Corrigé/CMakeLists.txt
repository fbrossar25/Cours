cmake_minimum_required(VERSION 2.8.9)

project(MOP_TP5_CORRIGE)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -o4 -std=c++11")

add_subdirectory(src)

