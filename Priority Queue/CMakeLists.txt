cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(priority_queue
    VERSION 1.0
    DESCRIPTION "Data structure - Priority Queue"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(priority_queue src/priority_queue.c src/priority_queue_test.c)
