# Red-Black Tree

## Description

A [Red-Black Tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree) is a self-balancing binary search tree where each node has an extra attribute called "color," which can be either red or black. This implementation of a Red-Black Tree provides various operations for maintaining the tree's balance and efficiently searching for and inserting data.

## Functionality

This Red-Black Tree implementation provides the following operations:

- `initRedBlackTree():` Initializes a new Red-Black Tree.
- `insert(RedBlackTree *tree, int data):` Inserts a new node with the given data into the Red-Black Tree.
- `search(RedBlackTree *tree, int data):` Searches for a specific data element in the Red-Black Tree and returns true if found, false otherwise.
- `deleteNode(RedBlackTree *tree, int data):` Deletes a node with the specified data from the Red-Black Tree.
- `inOrderTraverse(RedBlackTree *tree):` Performs an in-order traversal of the Red-Black Tree, displaying the elements in ascending order.
- `preOrderTraverse(RedBlackTree *tree):` Performs a pre-order traversal of the Red-Black Tree.
- `postOrderTraverse(RedBlackTree *tree):` Performs a post-order traversal of the Red-Black Tree.
- `minVal(RedBlackTree *tree):` Finds and returns the minimal value in the Red-Black Tree.
- `maxVal(RedBlackTree *tree):` Finds and returns the maximal value in the Red-Black Tree.
- `size(RedBlackTree *tree):` Returns the number of nodes in the Red-Black Tree.
- `destroyRedBlackTree(RedBlackTree *tree):` Destroys the Red-Black Tree and frees the allocated memory.

## Compiling

To compile your Red-Black Tree implementation, you can use a C compiler. Here are the basic compilation steps:

```bash
gcc -c src/red_black_tree.c -Wall -Wpedantic -Wextra -o src/red_black_tree.o
gcc -c src/red_black_tree_test.c -Wall -Wpedantic -Wextra -o src/red_black_tree_test.o
gcc src/red_black_tree.o src/red_black_tree_test.o -Wall -Wpedantic -Wextra -o red_black_tree
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
valgrind --leak-check=full -s ./red_black_tree
```

### Output

```console
<loveit@fedora Red Black Tree>$ valgrind --leak-check=full -s ./red_black_tree
==98313== Memcheck, a memory error detector
==98313== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==98313== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==98313== Command: ./red_black_tree
==98313==
In-order traversal:
3 7 8 10 11 18 22 26
Pre-order traversal:
7 3 18 10 8 11 22 26
Post-order traversal:
3 8 11 10 26 22 18 7
10 found in the tree
Count of elements before deletion: 8
After deleting 18:
Count of elements after deletion: 7
3 7 8 10 11 22 26
Min value: 3
Max value: 26
==98313==
==98313== HEAP SUMMARY:
==98313==     in use at exit: 0 bytes in 0 blocks
==98313==   total heap usage: 10 allocs, 10 frees, 1,360 bytes allocated
==98313==
==98313== All heap blocks were freed -- no leaks are possible
==98313==
==98313== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there is no memory leaks.
