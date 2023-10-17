# Heap

## Description

A Heap is a specialized tree-based data structure that satisfies the heap property. In a max-heap, for any given node C, if P is a parent node of C, then the key (the value) of P is greater than or equal to the key of C. In a min-heap, the key of P is less than or equal to the key of C. This implementation provides a Max Heap data structure in C.

## Functionality

This Max Heap implementation provides the following operations:

- `createHeap(int capacity)`: Creates a new heap with the specified capacity.
- `insert(Heap *heap, int value)`: Inserts a new element into the heap.
- `removeMax(Heap *heap)`: Removes and returns the maximum element from the heap.
- `isEmpty(Heap *heap)`: Checks if the heap is empty.
- `heapify(Heap *heap, int index)`: Heapifies the heap, starting from the given index.
- `heapSort(Heap *heap)`: Sorts the heap in ascending order using Heap Sort.
- `heapSortWithoutReturnOrig(Heap *heap)`: Sorts the heap in ascending order using Heap Sort without returning the original heap.
- `destroyHeap(Heap *heap)`: Destroys the heap and frees the allocated memory.

## Compiling

You can compile the Heap implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Heap using the included compile.sh script:

```bash
gcc -c src/heap.c -Wall -Wpedantic -Wextra -o src/heap.o
gcc -c src/heap_test.c -Wall -Wpedantic -Wextra -o src/heap_test.o
gcc src/heap.o src/heap_test.o -Wall -Wpedantic -Wextra -o heap
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

## Memory Leaks

A test program is provided in heap_test.c, which initializes a heap, inserts elements, extracts elements, and checks for emptiness. To check for memory leaks, you can use Valgrind. Run the following command:

```bash
valgrind --leak-check=full -s ./heap
```

### Output

```console
<loveit@fedora Heap>$ valgrind --leak-check=full -s ./heap
==108406== Memcheck, a memory error detector
==108406== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==108406== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==108406== Command: ./heap
==108406==
Heap after insertions: 19 15 18 11 14 17 7 9 10 12 13 8 16 0 6 1 5 2 9 1 4 3 12 2 6 5
Heap after sorting: 19 18 17 16 15 14 13 12 12 11 10 9 9 8 7 6 6 5 5 4 3 2 2 1 1 0
Original heap is not empty
==108406==
==108406== HEAP SUMMARY:
==108406==     in use at exit: 0 bytes in 0 blocks
==108406==   total heap usage: 7 allocs, 7 frees, 1,496 bytes allocated
==108406==
==108406== All heap blocks were freed -- no leaks are possible
==108406==
==108406== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there are no memory leaks.
