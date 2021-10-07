cmake_minimum_required(VERSION 3.20)
project(Tic_Tac_Toe)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(SOURCE_FILES main.cpp)
add_executable(Tic_Tac_Toe main.cpp)
