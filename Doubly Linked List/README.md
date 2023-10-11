# Doubly Linked List

## Description

A doubly linked list is a linear data structure in which each element is stored in a node that contains references to both the next and previous elements. This structure allows for efficient traversal in both directions and is used in various applications, such as implementing dynamic data structures and caches. This implementation provides basic operations to manipulate a doubly linked list.

## Functionality

This doubly linked list provides the following operations:

- initDoublyLinkedList(): Initializes a new doubly linked list.
- isEmpty(DoublyLinkedList \*list): Checks if the list is empty and returns true if it is, false otherwise.
- insertAtBeginning(DoublyLinkedList \*list, int data): Inserts a new element at the beginning of the list.
- insertAtEnd(DoublyLinkedList \*list, int data): Inserts a new element at the end of the list.
- insertAfterPosition(DoublyLinkedList \*list, int data, int position): Inserts a new element after a specific position in the list (1-based index).
- deleteElement(DoublyLinkedList \*list, int data): Deletes the first occurrence of a specific element from the list.
- search(DoublyLinkedList \*list, int data): Searches for a specific element in the list and returns its position (1-based index) or -1 if not found.
- display(DoublyLinkedList \*list): Displays all elements in the doubly linked list.
- size(DoublyLinkedList \*list): Returns the number of elements in the list.
- destroyDoublyLinkedList(DoublyLinkedList \*list): Destroys the doubly linked list and frees the allocated memory.

## Compiling

You can compile the Doubly Linked List implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Doubly Linked List using the included compile.sh script:

```bash
gcc -c src/doubly_linked_list.c -o src/doubly_linked_list.o
gcc -c src/main.c -o src/main.o
gcc src/doubly_linked_list.o src/main.o -o doubly_linked_list
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
valgrind --leak-check=full -s ./doubly_linked_list
```

### Output

```console
<loveit@fedora Doubly Linked List>$ valgrind --leak-check=full -s ./doubly_linked_list
==438451== Memcheck, a memory error detector
==438451== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==438451== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==438451== Command: ./doubly_linked_list
==438451==
Inserting 10, 20, 30 at the beginning:
30 <-> 20 <-> 10 <-> NULL

Inserting 40, 50, 60 at the end:
30 <-> 20 <-> 10 <-> 40 <-> 50 <-> 60 <-> NULL

Deleting element 20:
30 <-> 10 <-> 40 <-> 50 <-> 60 <-> NULL

List size: 5
==438451==
==438451== HEAP SUMMARY:
==438451==     in use at exit: 0 bytes in 0 blocks
==438451==   total heap usage: 8 allocs, 8 frees, 1,184 bytes allocated
==438451==
==438451== All heap blocks were freed -- no leaks are possible
==438451==
==438451== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there is no memory leaks.
