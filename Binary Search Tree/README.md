# Binary Search Tree (BST)

## Description

A Binary Search Tree (BST) is a hierarchical data structure that is used for efficient searching, insertion, and deletion of elements. Each node in the BST has a key, and all the keys in the left subtree are less than the key at the root, and all the keys in the right subtree are greater than the key at the root.

This repository contains an implementation of a Binary Search Tree in C. It provides basic functionality to create, manipulate, and traverse a BST.

## Usage

### Prerequisites

Before using this Binary Search Tree implementation, ensure that you have the following:

- GCC (GNU Compiler Collection) or another C compiler
- A CMake (optional) for building
- A C development environment

## Compiling

You can compile the BST implementation using the provided scripts or CMake:

### Bash Script

Run the following commands to compile the BST using the included compile.sh script:

```bash
gcc -c src/binary_search_tree.c -Wall -Wpedantic -Wextra -o src/binary_search_tree.o
gcc -c src/binary_search_tree_test.c -Wall -Wpedantic -Wextra -o src/binary_search_tree_test.o
gcc src/binary_search_tree.o src/binary_search_tree_test.o -Wall -Wpedantic -Wextra -o binary_search_tree
```

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

## Functionality

The BST provides the following operations:

### Structure

- `struct TreeNode`: Represents a node in the Binary Search Tree.
- `struct BinarySearchTree`: Represents the Binary Search Tree itself.

### Initialization

- `initBinarySearchTree()`: Initializes a new Binary Search Tree.
- `isEmpty(BinarySearchTree *tree)`: Checks if the Binary Search Tree is empty.

### Insertion

- `insert(BinarySearchTree *tree, int data)`: Inserts a new element into the Binary Search Tree.

### Deletion

- `deleteNode(BinarySearchTree *tree, int data)`: Deletes a specific element from the Binary Search Tree.

### Search

- `search(BinarySearchTree *tree, int data)`: Searches for a specific element in the Binary Search Tree.
- `findMin(BinarySearchTree *tree)`: Searches the minimal element in the Binary Search Tree.
- `findMax(BinarySearchTree *tree)`: Searches the maximal element in the Binary Search Tree.

### Traversal

- `displayInOrder(BinarySearchTree *tree)`: Displays all elements in the Binary Search Tree in an in-order traversal.
- `displayPreOrder(BinarySearchTree *tree)`: Displays all elements in the Binary Search Tree in a pre-order traversal.
- `displayPostOrder(BinarySearchTree *tree)`: Displays all elements in the Binary Search Tree in a post-order traversal.

### Destruction

- `destroyBinarySearchTree(BinarySearchTree *tree)`: Destroys the Binary Search Tree and frees allocated memory.

## Memory Leaks

You can use the Valgrind tool to check for any memory leaks or errors in the program. To check for memory leaks, run the following command:

```bash
valgrind --leak-check=full -s ./binary_search_tree
```

### Output

```console
<loveit@fedora Binary Search Tree>$ valgrind --leak-check=full -s ./binary_search_tree
==23108== Memcheck, a memory error detector
==23108== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==23108== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==23108== Command: ./binary_search_tree
==23108==
Binary Search Tree is initially empty
In-order traversal: 3 5 7 10 12 15 18
Pre-order traversal: 10 5 3 7 15 12 18
Post-order traversal: 3 7 5 12 18 15 10
12 found at position 2 in the tree
Deleted 15 from the tree
Min element = 3
Max element = 18
In-order traversal after deletion: 3 5 7 10 12 18
==23108==
==23108== HEAP SUMMARY:
==23108==     in use at exit: 0 bytes in 0 blocks
==23108==   total heap usage: 9 allocs, 9 frees, 1,208 bytes allocated
==23108==
==23108== All heap blocks were freed -- no leaks are possible
==23108==
==23108== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there are no any errors or memory leaks.
