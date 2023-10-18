cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(binary_search_tree
    VERSION 1.0
    DESCRIPTION "Data structure - Binary Search Tree"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(binary_search_tree src/binary_search_tree.c src/binary_search_tree_test.c)
