cmake_minimum_required(VERSION 3.20)

project(vstack CXX)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Main coordinator program
add_executable(main src/main.cpp)

# 2. Individual standalone learning executables
add_executable(numtheory src/numtheory.cpp)