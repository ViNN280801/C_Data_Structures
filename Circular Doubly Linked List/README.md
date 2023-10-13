# Circular Doubly Linked List

## Description

A circular doubly linked list is a linear data structure in which elements are stored in nodes, and each node points to both the next and previous nodes in the sequence, forming a closed loop. It's a versatile data structure used for various applications, offering bidirectional traversal and insertion/deletion at both ends. This implementation of a circular doubly linked list provides basic operations to manipulate the list.

## Functionality

This circular doubly linked list provides the following operations:

- initCircularDoublyLinkedList(): Initializes a new circular doubly linked list.
- isEmpty(CircularDoublyLinkedList \*list): Checks if the list is empty and returns true if it is, false otherwise.
- insertAtBeginning(CircularDoublyLinkedList \*list, int data): Inserts a new element at the beginning of the list.
- insertAtEnd(CircularDoublyLinkedList \*list, int data): Inserts a new element at the end of the list.
- insertAfterPosition(CircularDoublyLinkedList \*list, int data, int position): Inserts a new element after a specific position in the list (1-based index).
- deleteElement(CircularDoublyLinkedList \*list, int data): Deletes the first occurrence of a specific element from the list.
- search(CircularDoublyLinkedList \*list, int data): Searches for a specific element in the list and returns its position (1-based index) or -1 if not found.
- display(CircularDoublyLinkedList \*list): Displays all elements in the circular doubly linked list, both forwards and backward.
- size(CircularDoublyLinkedList \*list): Returns the number of elements in the list.
- destroyCircularDoublyLinkedList(CircularDoublyLinkedList \*list): Destroys the circular doubly linked list and frees the allocated memory.

## Compiling

You can compile the Singly Linked List implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Stack using the included compile.sh script:

```bash
gcc -c src/circular_doubly_linked_list.c -Wall -Wpedantic -Wextra -o src/circular_doubly_linked_list.o
gcc -c src/circular_doubly_linked_list_test.c -Wall -Wpedantic -Wextra -o src/circular_doubly_linked_list_test.o
gcc src/circular_doubly_linked_list.o src/circular_doubly_linked_list_test.o -Wall -Wpedantic -Wextra -o circular_doubly_linked_list
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
valgrind --leak-check=full -s ./circular_doubly_linked_list
```

### Output

```console
<loveit@fedora Circular Doubly Linked List>$ valgrind --leak-check=full -s ./circular_doubly_linked_list
==22628== Memcheck, a memory error detector
==22628== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==22628== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==22628== Command: ./circular_doubly_linked_list
==22628==
Circular Doubly Linked List: 30 <-> 25 <-> 20 <-> 10 <-> 55 <-> 40 <-> 50 <-> 60 <-> ... (circular)
30 found at position 1
Circular Doubly Linked List after deletion: 30 <-> 25 <-> 10 <-> 55 <-> 40 <-> 50 <-> 60 <-> ... (circular)
Size of the list: 7
==22628==
==22628== HEAP SUMMARY:
==22628==     in use at exit: 0 bytes in 0 blocks
==22628==   total heap usage: 10 allocs, 10 frees, 1,232 bytes allocated
==22628==
==22628== All heap blocks were freed -- no leaks are possible
==22628==
==22628== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there is no memory leaks.
