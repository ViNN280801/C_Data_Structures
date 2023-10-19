cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(magnetic_tape
    VERSION 1.0
    DESCRIPTION "Data structure - Magnetic Tape"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wpedantic -Wextra -O2")

add_executable(magnetic_tape src/magnetic_tape.c src/magnetic_tape_test.c)
