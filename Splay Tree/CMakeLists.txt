cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(splay_tree
    VERSION 1.0
    DESCRIPTION "Data structure - Splay Tree"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(splay_tree src/generate_keys.c src/splay_tree.c src/splay_tree_test.c)
