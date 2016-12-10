cmake_minimum_required(VERSION 3.2)
project(easy)
project(medium)
project(hard)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(easy easy.cpp)
add_executable(medium medium.cpp)
add_executable(hard hard.cpp)