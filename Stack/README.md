# Stack

## Description

A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. It means the most recently added element is the first one to be removed. Stacks can be implemented using arrays and linked lists. This implementation of a stack uses an array to store elements.

## Functionality

This stack provides the following operations:

- initStack(int capacity): Initializes a new stack with the specified capacity.
- isEmpty(Stack \*stack): Checks if the stack is empty and returns true if it is, false otherwise.
- isFull(Stack \*stack): Checks if the stack is full and returns true if it is, false otherwise.
- push(Stack \*stack, int item): Pushes an item onto the stack. If the stack is full, it displays a message indicating that the stack is full.
- pop(Stack \*stack): Pops the top item from the stack and returns it. If the stack is empty, it displays a message indicating that the stack is empty.
- peek(Stack \*stack): Returns the top item from the stack without removing it. If the stack is empty, it displays a message indicating that the stack is empty.
- destroyStack(Stack \*stack): Destroys the stack and frees the allocated memory.

## Compiling

You can compile the Stack implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Stack using the included compile.sh script:

```bash
gcc -c src/stack.c -o src/stack.o
gcc -c src/main.c -o src/main.o
gcc src/stack.o src/main.o -o stack
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

The provided test program in main.c initializes a stack, pushes elements onto the stack, pops and displays elements, and checks if the stack is empty or full. You can run this program to test the stack's functionality.
Memory Leaks

You can use the Valgrind tool to check for any memory leaks or errors in the program. To check for memory leaks, run the following command:

```bash
valgrind --leak-check=full -s ./stack
```

### Output

```console
<loveit@fedora Stack>$ valgrind --leak-check=full -s ./stack
==361241== Memcheck, a memory error detector
==361241== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==361241== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==361241== Command: ./stack
==361241==
Stack is empty
Stack is full
Top element: 55
Popped element: 55
Popped element: 32
Popped element: 7
Popped element: 10
Popped element: 42
Stack is empty after popping all elements
Stack is empty. Returning empty value, that is equals -1
Item from empty stack = -1
==361241==
==361241== HEAP SUMMARY:
==361241== in use at exit: 0 bytes in 0 blocks
==361241== total heap usage: 3 allocs, 3 frees, 1,068 bytes allocated
==361241==
==361241== All heap blocks were freed -- no leaks are possible
==361241==
==361241== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there is no memory leaks.
