cmake_minimum_required(VERSION 3.12)
project(Lab6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(Lab6 main.cpp dictionary.cpp)