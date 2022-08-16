cmake_minimum_required(VERSION 3.22)
project(ordenamiento)

set(CMAKE_CXX_STANDARD 17)

add_executable(ordenamiento main.cpp)

add_executable(generate generate.cpp counting_sort.h)

add_executable(test test.cpp counting_sort.h)
