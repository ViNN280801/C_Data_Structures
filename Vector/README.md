# Vector

## Description

A vector, also known as a dynamic array, is a linear data structure that can grow or shrink in size as needed. It allows you to store a collection of elements, similar to an array, but with the ability to resize dynamically when more elements are added. This implementation of a vector uses an array to store elements and provides essential operations for managing the vector.

## Functionality

This vector implementation provides the following operations:

- `initVector(int capacity)`: Initializes a new vector with the specified initial capacity.
- `isEmpty(Vector *vector)`: Checks if the vector is empty and returns true if it is, false otherwise.
- `push_back(Vector *vector, int value)`: Inserts an element into the end of the vector. If the vector is full, it dynamically resizes to accommodate more elements.
- `insert(Vector *vector, int value, int index)`: Inserts an element into the vector at a specified position. If the vector is full, it dynamically resizes to accommodate more elements.
- `get(Vector *vector, int index)`: Retrieves an element from the vector at a specified index.
- `size(Vector *vector)`: Returns the current count of elements in the vector.
- `capacity(Vector *vector)`: Returns the reserved space in the vector.
- `data(Vector *vector)`: Returns a pointer to the underlying array.
- `destroyVector(Vector *vector)`: Destroys the vector and frees the allocated memory.

## Compiling

You can compile the Vector implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Vector using the included compile.sh script:

```bash
gcc -c src/vector.c -Wall -Wpedantic -Wextra -o src/vector.o
gcc -c src/vector_test.c -Wall -Wpedantic -Wextra -o src/vector_test.o
gcc src/vector.o src/vector_test.o -Wall -Wpedantic -Wextra -o vector
```

or execute just ./compile.sh

```bash
./compile.sh
```

The script compiles the source files separately with GCC compiler, using necessary flags and the C standard revision.

### CMake

Alternatively, you can use CMake for compilation. Here are the commands:

```bash
cmake .
cmake --build .
```

or

```bash
cmake .
make
```

## Memory leaks

The provided test program in main.c initializes a vector, inserts elements, retrieves elements, and checks the vector's size, capacity, and the underlying array. You can run this program to test the vector's functionality.

You can use the Valgrind tool to check for any memory leaks or errors in the program. To check for memory leaks, run the following command:

```bash
valgrind --leak-check=full -s ./vector
```

### Output

```console
<loveit@fedora Vector>$ valgrind --leak-check=full -s ./vector
==66369== Memcheck, a memory error detector
==66369== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==66369== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==66369== Command: ./vector
==66369==
Vector elements: 0 10 10 20 30 40
All tests passed!
==66369==
==66369== HEAP SUMMARY:
==66369==     in use at exit: 0 bytes in 0 blocks
==66369==   total heap usage: 4 allocs, 4 frees, 1,100 bytes allocated
==66369==
==66369== All heap blocks were freed -- no leaks are possible
==66369==
==66369== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there is no memory leaks.
