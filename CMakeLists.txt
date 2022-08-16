cmake_minimum_required(VERSION 3.22)
project(ordenamiento)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp counting_sort.h selection_sort.h)

add_executable(generate generate.cpp counting_sort.h)

add_executable(test_counting_sort test_counting_sort.cpp counting_sort.h test.h)

add_executable(test_selection_sort.cpp test_selection_sort.cpp selection_sort.h test.h)

add_executable(test_intro_sort.cpp test_intro_sort.cpp intro_sort.h test.h)
