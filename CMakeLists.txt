cmake_minimum_required(VERSION 3.29)
project(calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(calculator main.cpp
        calc.cpp
)
add_executable(tests calc.cpp test.cpp)