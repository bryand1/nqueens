cmake_minimum_required(VERSION 3.6)
project(nqueens)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES nqueens.cpp)
add_executable(nqueens ${SOURCE_FILES})
