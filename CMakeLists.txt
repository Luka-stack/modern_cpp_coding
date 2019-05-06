cmake_minimum_required(VERSION 3.14)
project(modern_cpp_exc)

set(CMAKE_CXX_STANDARD 17)

add_executable(modern_cpp_exc main.cpp math_problems/math_problems.h math_problems/math_problems.cpp language_functions/Ipv4.h language_functions/Ipv4.cpp language_functions/Great2D.h)