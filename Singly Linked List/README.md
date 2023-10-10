# Singly Linked List

## Description

A singly linked list is a linear data structure in which elements are stored in nodes, and each node points to the next node in the sequence. It's a fundamental data structure used for various applications, such as implementing other data structures like stacks and queues. This implementation of a singly linked list provides basic operations to manipulate the list.

## Functionality

This singly linked list provides the following operations:

- initSinglyLinkedList(): Initializes a new singly linked list.
- isEmpty(SinglyLinkedList \*list): Checks if the list is empty and returns true if it is, false otherwise.
- insertAtBeginning(SinglyLinkedList \*list, int data): Inserts a new element at the beginning of the list.
- insertAtEnd(SinglyLinkedList \*list, int data): Inserts a new element at the end of the list.
- insertAfterPosition(SinglyLinkedList \*list, int data, int position): Inserts a new element after a specific position in the list (1-based index).
- deleteElement(SinglyLinkedList \*list, int data): Deletes the first occurrence of a specific element from the list.
- search(SinglyLinkedList \*list, int data): Searches for a specific element in the list and returns its position (1-based index) or -1 if not found.
- display(SinglyLinkedList \*list): Displays all elements in the singly linked list.
- size(SinglyLinkedList \*list): Returns the number of elements in the list.
- destroySinglyLinkedList(SinglyLinkedList \*list): Destroys the singly linked list and frees the allocated memory.

## Compiling

You can compile the Singly Linked List implementation using the provided scripts:

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

You can use the Valgrind tool to check for any memory leaks or errors in the program. To check for memory leaks, run the following command:

```bash
valgrind --leak-check=full -s ./singly_linked_list
```

### Output

```console
<loveit@fedora Singly Linked List>$ valgrind --leak-check=full -s ./singly_linked_list
==419518== Memcheck, a memory error detector
==419518== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==419518== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==419518== Command: ./singly_linked_list
==419518==
Inserting 10, 20, 30 at the beginning:
30 -> 20 -> 10 -> NULL

Inserting 40, 50, 60 at the end:
30 -> 20 -> 10 -> 40 -> 50 -> 60 -> NULL

Deleting from the beginning:
30 -> 20 -> 10 -> 40 -> 50 -> 60 -> NULL

List size: 6
==419518==
==419518== HEAP SUMMARY:
==419518==     in use at exit: 0 bytes in 0 blocks
==419518==   total heap usage: 8 allocs, 8 frees, 1,136 bytes allocated
==419518==
==419518== All heap blocks were freed -- no leaks are possible
==419518==
==419518== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there is no memory leaks.
