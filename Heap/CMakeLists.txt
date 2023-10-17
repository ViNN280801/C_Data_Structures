cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(heap
    VERSION 1.0
    DESCRIPTION "Data structure - Heap"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(heap src/heap.c src/heap_test.c)
