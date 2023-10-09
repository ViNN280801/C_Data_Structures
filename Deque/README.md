# Deque

## Description

A deque (double-ended queue) is a linear data structure that allows elements to be added or removed from both ends. It supports operations to add and delete elements from both the front and rear ends. This implementation of a deque uses an array to store elements.

## Functionality

This deque provides the following operations:

- `initDeque(int capacity)`: Initializes a new deque with the specified capacity.
- `isEmpty(Deque *deque)`: Checks if the deque is empty and returns true if it is, false otherwise.
- `isFull(Deque *deque)`: Checks if the deque is full and returns true if it is, false otherwise.
- `addRear(Deque *deque, int item)`: Adds an element at the rear end of the deque. If the deque is full, it resizes the deque to accommodate more elements.
- `addFront(Deque *deque, int item)`: Adds an element at the front end of the deque. If the deque is full, it resizes the deque to accommodate more elements.
- `deleteFront(Deque *deque)`: Deletes an element from the front end of the deque and returns it. If the deque is empty, it displays a message indicating that the deque is empty.
- `deleteRear(Deque *deque)`: Deletes an element from the rear end of the deque and returns it. If the deque is empty, it displays a message indicating that the deque is empty.
- `getFront(Deque *deque)`: Returns the front item from the deque without removing it. If the deque is empty, it displays a message indicating that the deque is empty.
- `getRear(Deque *deque)`: Returns the rear item from the deque without removing it. If the deque is empty, it displays a message indicating that the deque is empty.
- `dequeSize(Deque *deque)`: Returns the current number of elements in the deque.
- `dequeCapacity(Deque *deque)`: Returns the reserved count of elements in the deque.
- `destroyDeque(Deque *deque)`: Destroys the deque and frees the allocated memory.

## Compiling

You can compile the Deque implementation using the provided scripts or CMake:

### Bash Script

Run the following commands to compile the Deque using the included compile.sh script:

```bash
gcc -c src/deque.c -o src/deque.o
gcc -c src/deque_test.c -o src/deque_test.o
gcc src/deque.o src/deque_test.o -o deque_test
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

The provided test program in deque_test.c initializes a deque, adds, deletes, and displays elements, and checks if the deque is empty or full. You can run this program to test the deque's functionality.

You can use the Valgrind tool to check for any memory leaks or errors in the program. To check for memory leaks, run the following command:

```bash
valgrind --leak-check=full -s ./deque
```

### Output

```console
<loveit@fedora Deque>$ valgrind --leak-check=full -s ./deque
==395839== Memcheck, a memory error detector
==395839== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==395839== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==395839== Command: ./deque
==395839==
Deque is empty
Deque is full
Front element: 32
Rear element: 55
Deleted from front: 32, Deleted from rear: 55
Deleted from front: 10, Deleted from rear: 7
Deque is empty. Returning empty value, that is equal to -1
Deleted from front: 42, Deleted from rear: -1
Deque is empty after deleting all elements
Deque is empty. Returning empty value, that is equal to -1
Deque is empty. Returning empty value, that is equal to -1
Item from empty deque (front): -1
Item from empty deque (rear): -1
==395839==
==395839== HEAP SUMMARY:
==395839==     in use at exit: 0 bytes in 0 blocks
==395839==   total heap usage: 3 allocs, 3 frees, 1,068 bytes allocated
==395839==
==395839== All heap blocks were freed -- no leaks are possible
==395839==
==395839== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there are no memory leaks.
