cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(circular_singly_linked_list
    VERSION 1.0
    DESCRIPTION "Data structure - Circular Singly Linked List"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(circular_singly_linked_list src/circular_singly_linked_list.c src/circular_singly_linked_list_test.c)
