cmake_minimum_required(VERSION 2.8.9)
project(MOP_TP3_LIB)
message(System Name : ${CMAKE_SYSTEM_NAME})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -o4")

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
	add_library(DisplayMessage_d SHARED DisplayMessage.cpp)
elseif(${CMAKE_BUILD_TYPE} STREQUAL Release)
	add_library(DisplayMessage_r SHARED DisplayMessage.cpp)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
	add_definitions(\D_SYSTEM_WINDOWS)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
	add_definitions(-D_SYSTEM_LINUX)
endif()