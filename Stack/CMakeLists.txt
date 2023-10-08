cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(stack
    VERSION 1.0
    DESCRIPTION "Data structure - Stack"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(stack src/stack.c src/stack_test.c)
