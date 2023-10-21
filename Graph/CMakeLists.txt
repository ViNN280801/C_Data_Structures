cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(graph
    VERSION 1.0
    DESCRIPTION "Data structure - Graph"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(graph src/graph.c src/graph_test.c)
