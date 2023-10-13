cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(circular_doubly_linked_list
    VERSION 1.0
    DESCRIPTION "Data structure - Circular Doubly Linked List"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(circular_doubly_linked_list src/circular_doubly_linked_list.c src/circular_doubly_linked_list_test.c)
