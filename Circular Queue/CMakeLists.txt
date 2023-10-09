cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(circular_queue
    VERSION 1.0
    DESCRIPTION "Data structure - Circular Queue"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(circular_queue src/circular_queue.c src/circular_queue_test.c)
