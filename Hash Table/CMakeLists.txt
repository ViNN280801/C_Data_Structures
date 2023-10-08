cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(hash_table
    VERSION 1.0
    DESCRIPTION "Data structure - Hash Table"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(hash_table src/generate_keys.c src/hash_table.c src/hash_table_test.c)
