# Priority Queue

## Description

A Priority Queue is a data structure that allows you to store elements with associated priorities. It ensures that elements with higher priorities are processed before elements with lower priorities. This implementation uses a singly linked list to manage the priority queue.

## Functionality

This priority queue provides the following operations:

- `initPriorityQueue()`: Initializes a new priority queue.
- `isEmpty(PriorityQueue *queue)`: Checks if the priority queue is empty and returns true if it is, false otherwise.
- `insert(PriorityQueue *queue, int data, int priority)`: Inserts an element with a specified priority into the priority queue.
- `extractMax(PriorityQueue *queue)`: Removes and returns the element with the highest priority from the priority queue.
- `destroyPriorityQueue(PriorityQueue *queue)`: Destroys the priority queue and frees the allocated memory.

## Compiling

You can compile the Priority Queue implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Priority Queue using the included compile.sh script:

```bash
gcc -c src/priority_queue.c -Wall -Wpedantic -Wextra -o src/priority_queue.o
gcc -c src/priority_queue_test.c -Wall -Wpedantic -Wextra -o src/priority_queue_test.o
gcc src/priority_queue.o src/priority_queue_test.o -Wall -Wpedantic -Wextra -o priority_queue
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

The provided test program in <b>priority_queue_test.c</b> initializes a priority queue, inserts elements into the queue, extracts and displays elements, and checks if the queue is empty. You can run this program to test the priority queue's functionality.

You can use the Valgrind tool to check for any memory leaks or errors in the program. To check for memory leaks, run the following command:

```bash
valgrind --leak-check=full -s ./priority_queue
```

### Output

```console
<loveit@fedora Priority Queue>$ valgrind --leak-check=full -s ./priority_queue
==50978== Memcheck, a memory error detector
==50978== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==50978== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==50978== Command: ./priority_queue
==50978==
Priority Queue Contents:
Data: 13
Data: 60
Data: 12
Data: 14
Data: 10
==50978==
==50978== HEAP SUMMARY:
==50978==     in use at exit: 0 bytes in 0 blocks
==50978==   total heap usage: 7 allocs, 7 frees, 1,112 bytes allocated
==50978==
==50978== All heap blocks were freed -- no leaks are possible
==50978==
==50978== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there are no memory leaks.
