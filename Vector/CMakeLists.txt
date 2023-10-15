cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(vector
    VERSION 1.0
    DESCRIPTION "Data structure - Vector (Dynamically Array)"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(vector src/vector.c src/vector_test.c)
