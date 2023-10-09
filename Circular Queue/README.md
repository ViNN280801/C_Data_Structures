# Circular Queue

## Description

A circular queue is a variation of a queue, a linear data structure that follows the First-In-First-Out (FIFO) principle. In a circular queue, the elements are stored in a circular fashion, and when the last location of the queue is full, the next element is inserted at the very first location, creating a circular pattern. This implementation uses an array to store elements in a circular manner.

## Functionality

This circular queue provides the following operations:

- initQueue(int capacity): Initializes a new circular queue with the specified capacity.
- isEmpty(Queue \*queue): Checks if the circular queue is empty and returns true if it is, false otherwise.
- isFull(Queue \*queue): Checks if the circular queue is full and returns true if it is, false otherwise.
- enqueue(Queue \*queue, int item): Enqueues (pushes) an item into the circular queue. If the queue is full, it displays a message indicating that the queue is full.
- dequeue(Queue \*queue): Dequeues (pops) an item from the circular queue and returns it. If the queue is empty, it displays a message indicating that the queue is empty.
- front(Queue \*queue): Returns the front item from the circular queue without removing it. If the queue is empty, it displays a message indicating that the queue is empty.
- rear(Queue \*queue): Returns the rear item from the circular queue without removing it. If the queue is empty, it displays a message indicating that the queue is empty.
- size(Queue \*queue): Returns the current number of elements in the circular queue.
- capacity(Queue \*queue): Returns the reserved count of elements in the circular queue.
- destroyQueue(Queue \*queue): Destroys the circular queue and frees the allocated memory.

## Compiling

You can compile the Circular Queue implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Circular Queue using the included compile.sh script:

```bash
gcc -c src/circular_queue.c -o src/circular_queue.o
gcc -c src/circular_queue_test.c -o src/circular_queue_test.o
gcc src/circular_queue.o src/circular_queue_test.o -o circular_queue_test
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

The provided test program in queue_test.c initializes a queue, enqueues elements into the queue, dequeues and displays elements, and checks if the queue is empty or full. You can run this program to test the queue's functionality.

You can use the Valgrind tool to check for any memory leaks or errors in the program. To check for memory leaks, run the following command:

```bash
valgrind --leak-check=full -s ./circular_queue
```

### Output

```console
<loveit@fedora Circular Queue>$ valgrind --leak-check=full -s ./circular_queue
==394021== Memcheck, a memory error detector
==394021== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==394021== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==394021== Command: ./circular_queue
==394021==
Circular Queue is empty
Circular Queue is full
Circular Queue: 42 10 7 32 55
Dequeued element: 42
Dequeued element: 10
Dequeued element: 7
Dequeued element: 32
Dequeued element: 55
Circular Queue is empty after dequeuing all elements
Circular Queue is empty. Returning empty value, which is -1.
Item from empty circular queue = -1
==394021==
==394021== HEAP SUMMARY:
==394021==     in use at exit: 0 bytes in 0 blocks
==394021==   total heap usage: 3 allocs, 3 frees, 1,068 bytes allocated
==394021==
==394021== All heap blocks were freed -- no leaks are possible
==394021==
==394021== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there are no memory leaks.
