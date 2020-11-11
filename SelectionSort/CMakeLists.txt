cmake_minimum_required(VERSION 3.17)
project(SelectionSort)

set(CMAKE_CXX_STANDARD 14)
include_directories(includes/)
add_executable(SelectionSort main.cpp source/Rectangle.cpp includes/Rectangle.h source/selectionsort.cpp includes/selectionsort.h)
target_link_libraries(SelectionSort SDL2)