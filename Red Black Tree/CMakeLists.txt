cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(red_black_tree
    VERSION 1.0
    DESCRIPTION "Data structure - Red Black Tree"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(red_black_tree src/red_black_tree.c src/red_black_tree_test.c)
