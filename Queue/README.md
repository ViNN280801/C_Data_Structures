# Queue

## Description

A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle. It means that the first element added is the first one to be removed. Queues can be implemented using arrays and linked lists. This implementation of a queue uses an array to store elements.

## Functionality

This queue provides the following operations:

- initQueue(int capacity): Initializes a new queue with the specified capacity.
- isEmpty(Queue \*queue): Checks if the queue is empty and returns true if it is, false otherwise.
- isFull(Queue \*queue): Checks if the queue is full and returns true if it is, false otherwise.
- enqueue(Queue \*queue, int item): Enqueues (pushes) an item into the queue. If the queue is full, it displays a message indicating that the queue is full.
- dequeue(Queue \*queue): Dequeues (pops) an item from the queue and returns it. If the queue is empty, it displays a message indicating that the queue is empty.
- front(Queue \*queue): Returns the front item from the queue without removing it. If the queue is empty, it displays a message indicating that the queue is empty.
- rear(Queue \*queue): Returns the rear item from the queue without removing it. If the queue is empty, it displays a message indicating that the queue is empty.
- size(Queue \*queue): Returns the current number of elements in the queue.
- capacity(Queue \*queue): Returns the reserved count of elements in the queue.
- destroyQueue(Queue \*queue): Destroys the queue and frees the allocated memory.

## Compiling

You can compile the Queue implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Queue using the included compile.sh script:

```bash
gcc -c src/queue.c -o src/queue.o
gcc -c src/queue_test.c -o src/queue_test.o
gcc src/queue.o src/queue_test.o -o queue_test
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
valgrind --leak-check=full -s ./queue
```

### Output

```console
<loveit@fedora Queue>$ valgrind --leak-check=full -s ./queue
==392400== Memcheck, a memory error detector
==392400== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==392400== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==392400== Command: ./queue
==392400==
Queue is empty
Queue is full
Front element: 42
Rear element: 55
Dequeued element: 42
Dequeued element: 10
Dequeued element: 7
Dequeued element: 32
Dequeued element: 55
Queue is empty after dequeuing all elements
Queue is empty. Returning empty value, that is equal to -1
Item from empty queue = -1
==392400==
==392400== HEAP SUMMARY:
==392400== in use at exit: 0 bytes in 0 blocks
==392400== total heap usage: 3 allocs, 3 frees, 1,068 bytes allocated
==392400==
==392400== All heap blocks were freed -- no leaks are possible
==392400==
==392400== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there are no memory leaks.
