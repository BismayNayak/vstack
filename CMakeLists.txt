cmake_minimum_required(VERSION 3.20)

project(vstack CXX)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vstack_app src/main.cpp)