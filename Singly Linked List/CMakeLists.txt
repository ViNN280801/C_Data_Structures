cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(singly_linked_list
    VERSION 1.0
    DESCRIPTION "Data structure - Singly Linked List"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(singly_linked_list src/singly_linked_list.c src/singly_linked_list_test.c)
