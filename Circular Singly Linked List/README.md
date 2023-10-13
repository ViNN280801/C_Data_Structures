# Circular Singly Linked List

## Description

A circular singly linked list is a linear data structure in which elements are stored in nodes, and each node points to the next node in the sequence, forming a closed loop. It's a fundamental data structure used for various applications and is particularly useful when you need a continuous loop of elements. This implementation of a circular singly linked list provides basic operations to manipulate the list.

## Functionality

This circular singly linked list provides the following operations:

- `initCircularSinglyLinkedList()`: Initializes a new circular singly linked list.
- `isCircularSinglyLinkedListEmpty(CircularSinglyLinkedList *list)`: Checks if the list is empty and returns `true` if it is, `false` otherwise.
- `insertAtBeginning(CircularSinglyLinkedList *list, int data)`: Inserts a new element at the beginning of the list.
- `insertAtEnd(CircularSinglyLinkedList *list, int data)`: Inserts a new element at the end of the list.
- `insertAfterPosition(CircularSinglyLinkedList *list, int data, int position)`: Inserts a new element after a specific position in the list (1-based index).
- `deleteElement(CircularSinglyLinkedList *list, int data)`: Deletes the first occurrence of a specific element from the list.
- `search(CircularSinglyLinkedList *list, int data)`: Searches for a specific element in the list and returns its position (1-based index) or `-1` if not found.
- `display(CircularSinglyLinkedList *list)`: Displays all elements in the circular singly linked list.
- `size(CircularSinglyLinkedList *list)`: Returns the number of elements in the list.
- `destroyCircularSinglyLinkedList(CircularSinglyLinkedList *list)`: Destroys the circular singly linked list and frees the allocated memory.

## Compiling

You can compile the Singly Linked List implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Stack using the included compile.sh script:

```bash
gcc -c src/circular_singly_linked_list.c -Wall -Wpedantic -Wextra -o src/circular_singly_linked_list.o
gcc -c src/circular_singly_linked_list_test.c -Wall -Wpedantic -Wextra -o src/circular_singly_linked_list_test.o
gcc src/circular_singly_linked_list.o src/circular_singly_linked_list_test.o -Wall -Wpedantic -Wextra -o circular_singly_linked_list
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

You can use the Valgrind tool to check for any memory leaks or errors in the program. To check for memory leaks, run the following command:

```bash
valgrind --leak-check=full -s ./singly_linked_list
```

### Output

```console
<loveit@fedora Circular Singly Linked List>$ valgrind --leak-check=full -s ./circular_singly_linked_list
==468247== Memcheck, a memory error detector
==468247== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==468247== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==468247== Command: ./circular_singly_linked_list
==468247==
Inserting elements at the beginning:
30 -> 20 -> 10 -> ... (circular)

Inserting elements at the end:
30 -> 20 -> 10 -> 40 -> 50 -> 60 -> ... (circular)

Inserting elements at specific positions:
30 -> 99 -> 20 -> 10 -> 77 -> 40 -> 50 -> 60 -> ... (circular)

Searching for elements:
Position of 20: 3
Position of 77: 5

Deleting elements:
99 -> 20 -> 10 -> 40 -> 50 -> 60 -> ... (circular)

List size: 6
==468247==
==468247== HEAP SUMMARY:
==468247==     in use at exit: 0 bytes in 0 blocks
==468247==   total heap usage: 10 allocs, 10 frees, 1,168 bytes allocated
==468247==
==468247== All heap blocks were freed -- no leaks are possible
==468247==
==468247== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there is no memory leaks.
