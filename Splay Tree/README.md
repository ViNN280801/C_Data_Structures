# Splay Tree

## Description

A [splay-tree](https://en.wikipedia.org/wiki/Splay_tree) is a binary search tree with the additional property that recently accessed elements are quick to access again. Like self-balancing binary search trees, a splay tree performs basic operations such as insertion, look-up and removal in O(log n) amortized time.
Implemented with simple OOP concept (ctor/dtor - creating/deleting an object).
For testing was used 200'000 different numeric values from 'test_numbers.txt' and randomly generated values in interval [10'000'000; 100'000'000).

## Compiling

### GNU GCC

You can use './compile.sh' bash script for compile test file for this structure. This script compiles source files separately with GNU GCC compiler with necessary flags and [17 standard](<https://en.wikipedia.org/wiki/C17_(C_standard_revision)>) of C language.

Copy following commands to compile this project manually:

```bash
gcc -c src/generate_keys.c -Wall -Wpedantic -Wextra -o src/generate_keys.o
gcc -c src/splay_tree.c -Wall -Wpedantic -Wextra -o src/splay_tree.o
gcc -c src/splay_tree_test.c -Wall -Wpedantic -Wextra -o src/splay_tree_test.o
gcc src/generate_keys.o src/splay_tree.o src/splay_tree_test.o -Wall -Wpedantic -Wextra -o splay_tree
rm src/*.o
```

### CMake

There is autoassembly file 'CMakelists.txt' that describes how this project compiles. To use it you should write following lines:

```console
cmake .
cmake --build .
```

or

```console
cmake .
make
```

## Memory leaks

Using [valgrind](https://valgrind.org) tool for check of any memory leaks or errors in a program:

```console
<loveit@fedora C Data Structures>$ valgrind --leak-check=full -s ./splay_tree
==353394== Memcheck, a memory error detector
==353394== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==353394== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==353394== Command: ./splay_tree
==353394==
Key 18841565 not found in the splay-tree. Comparisons: 18
Key 96551965 not found in the splay-tree. Comparisons: 12
Key 42882723 found in the splay-tree. Comparisons: 22
Key 84258720 found in the splay-tree. Comparisons: 15
Key 34568631 found in the splay-tree. Comparisons: 15
Key 83246999 found in the splay-tree. Comparisons: 11
Key 95905677 found in the splay-tree. Comparisons: 12
Key 30253930 not found in the splay-tree. Comparisons: 14
Key 14123229 not found in the splay-tree. Comparisons: 14
Key 27691681 found in the splay-tree. Comparisons: 16
Key 73497949 not found in the splay-tree. Comparisons: 13
Key 20138140 found in the splay-tree. Comparisons: 13
Key 84107778 not found in the splay-tree. Comparisons: 18
Key 83835749 not found in the splay-tree. Comparisons: 11
Key 93241597 not found in the splay-tree. Comparisons: 20
Key 87238974 found in the splay-tree. Comparisons: 22
Key 77437768 not found in the splay-tree. Comparisons: 22
Key 46906783 found in the splay-tree. Comparisons: 15
Key 42315857 found in the splay-tree. Comparisons: 11
Key 50250209 not found in the splay-tree. Comparisons: 10
Key 27741464 not found in the splay-tree. Comparisons: 14
Key 86643941 not found in the splay-tree. Comparisons: 18
Key 35350474 not found in the splay-tree. Comparisons: 16
Key 19445301 found in the splay-tree. Comparisons: 16
Key 88278989 found in the splay-tree. Comparisons: 17
Key 62667096 found in the splay-tree. Comparisons: 19
Key 50810975 not found in the splay-tree. Comparisons: 15
Key 55743512 found in the splay-tree. Comparisons: 13
Key 40204329 not found in the splay-tree. Comparisons: 19
Key 87315104 not found in the splay-tree. Comparisons: 15
Key 13487424 not found in the splay-tree. Comparisons: 12
Key 82799653 not found in the splay-tree. Comparisons: 15
Key 90498063 not found in the splay-tree. Comparisons: 14
Key 99301354 not found in the splay-tree. Comparisons: 14
Key 30349033 found in the splay-tree. Comparisons: 19
Key 42071636 not found in the splay-tree. Comparisons: 10
Key 38979497 not found in the splay-tree. Comparisons: 9
Key 44775375 not found in the splay-tree. Comparisons: 12
Key 39082350 not found in the splay-tree. Comparisons: 11
Key 52779136 found in the splay-tree. Comparisons: 14
Key 46884081 not found in the splay-tree. Comparisons: 12
Key 39771580 found in the splay-tree. Comparisons: 10
Key 57695437 not found in the splay-tree. Comparisons: 15
Key 73950880 not found in the splay-tree. Comparisons: 16
Key 99020052 found in the splay-tree. Comparisons: 11
Key 35557396 found in the splay-tree. Comparisons: 15
Key 20634679 not found in the splay-tree. Comparisons: 12
Key 41426313 not found in the splay-tree. Comparisons: 13
Key 56804407 found in the splay-tree. Comparisons: 14
Key 56718265 found in the splay-tree. Comparisons: 13
Key 10893330 not found in the splay-tree. Comparisons: 11
Key 42947553 found in the splay-tree. Comparisons: 15
Key 83673374 found in the splay-tree. Comparisons: 15
Key 94372894 not found in the splay-tree. Comparisons: 20
Key 24892362 found in the splay-tree. Comparisons: 15
Key 66541010 found in the splay-tree. Comparisons: 17
Key 64168564 not found in the splay-tree. Comparisons: 21
Key 62627380 not found in the splay-tree. Comparisons: 17
Key 30617946 found in the splay-tree. Comparisons: 16
Key 21316863 not found in the splay-tree. Comparisons: 11
Key 51935268 found in the splay-tree. Comparisons: 13
Key 36406281 found in the splay-tree. Comparisons: 14
Key 50492010 found in the splay-tree. Comparisons: 10
Key 85068842 found in the splay-tree. Comparisons: 14
Key 50371505 not found in the splay-tree. Comparisons: 13
Key 34308446 not found in the splay-tree. Comparisons: 14
Key 67450556 not found in the splay-tree. Comparisons: 15
Key 17227295 not found in the splay-tree. Comparisons: 19
Key 88165028 not found in the splay-tree. Comparisons: 11
Key 54872754 not found in the splay-tree. Comparisons: 14
Key 48146293 found in the splay-tree. Comparisons: 21
Key 35966130 found in the splay-tree. Comparisons: 9
Key 37460634 not found in the splay-tree. Comparisons: 17
Key 89276762 not found in the splay-tree. Comparisons: 17
Key 44130791 not found in the splay-tree. Comparisons: 10
Key 70258238 found in the splay-tree. Comparisons: 14
Key 28343502 not found in the splay-tree. Comparisons: 19
Key 66912047 found in the splay-tree. Comparisons: 15
Key 26825955 not found in the splay-tree. Comparisons: 16
Key 97192338 found in the splay-tree. Comparisons: 15
Key 84580155 found in the splay-tree. Comparisons: 12
Key 83130037 found in the splay-tree. Comparisons: 13
Key 64275429 found in the splay-tree. Comparisons: 12
Key 32051522 found in the splay-tree. Comparisons: 12
Key 36600568 found in the splay-tree. Comparisons: 18
Key 37801902 found in the splay-tree. Comparisons: 11
Key 55750064 found in the splay-tree. Comparisons: 8
Key 67343291 found in the splay-tree. Comparisons: 15
Key 90229668 found in the splay-tree. Comparisons: 9
Key 97986428 found in the splay-tree. Comparisons: 11
Key 35641139 not found in the splay-tree. Comparisons: 19
Key 52695354 found in the splay-tree. Comparisons: 12
Key 15916697 found in the splay-tree. Comparisons: 14
Key 36648387 not found in the splay-tree. Comparisons: 14
Key 66189617 not found in the splay-tree. Comparisons: 13
Key 27648480 found in the splay-tree. Comparisons: 11
Key 98425454 found in the splay-tree. Comparisons: 17
Key 13441211 not found in the splay-tree. Comparisons: 14
Key 21063022 not found in the splay-tree. Comparisons: 16
Key 46375986 found in the splay-tree. Comparisons: 22
Average comparisons per key: 14.48
Memory used by Splay Tree: 4800000 bytes
==353394==
==353394== HEAP SUMMARY:
==353394==     in use at exit: 0 bytes in 0 blocks
==353394==   total heap usage: 200,004 allocs, 200,004 frees, 4,805,600 bytes allocated
==353394==
==353394== All heap blocks were freed -- no leaks are possible
==353394==
==353394== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

If you want to use valgrind with full check and with lists of errors, run following command:

```bash
valgrind --leak-check=full -s ./splay_tree
```

If you want to redirect valgrind checking to a file, use command below:

```bash
valgrind --leak-check=full -s --log-file="memory.log" ./splay_tree
```
