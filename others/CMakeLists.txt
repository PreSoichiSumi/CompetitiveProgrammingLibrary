cmake_minimum_required(VERSION 3.6)
project(A)
project(B)
project(C)
project(D)
project(E)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")  #cannot assign like: x[i]=5 when -std=c++11

#set(SOURCE_FILES SolveA.cpp)
add_executable(A SolveA.cpp)
add_executable(B SolveB.cpp)
add_executable(C SolveC.cpp)
add_executable(D SolveD.cpp)
add_executable(E SolveE.cpp)