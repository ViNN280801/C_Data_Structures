# Hash Table

## Description

A [hash table](https://en.wikipedia.org/wiki/Hash_table) is a data structure that is used to store keys/value pairs. It uses a hash function to compute an index into an array in which an element will be inserted or searched. By using a good hash function, hashing can work well.
Hash table implemented with open addressing.
Hash function implemented with division method.
Implemented with simple OOP concept (ctor/dtor - creating/deleting an object).
For testing was used 200'000 different numeric values from 'test_numbers.txt' and randomly generated values in interval [10'000'000; 100'000'000).

## Compiling

### GNU GCC

You can use './compile.sh' bash script for compile test file for this structure. This script compiles source files separately with GNU GCC compiler with necessary flags and [17 standard](<https://en.wikipedia.org/wiki/C17_(C_standard_revision)>) of C language.

Copy following commands to compile this project manually:

```bash
gcc -c src/generate_keys.c -Wall -Wpedantic -Wextra -o src/generate_keys.o
gcc -c src/hash_table.c -Wall -Wpedantic -Wextra -o src/hash_table.o
gcc -c src/hash_table_test.c -Wall -Wpedantic -Wextra -o src/hash_table_test.o
gcc src/generate_keys.o src/hash_table.o src/hash_table_test.o -Wall -Wpedantic -Wextra -o hash_table
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
<loveit@fedora Hash Table>$ valgrind --leak-check=full -s ./hash_table
==353430== Memcheck, a memory error detector
==353430== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==353430== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==353430== Command: ./hash_table
==353430==
Key 62667096 found in the hash table. Comparisons: 0
Key 88278989 found in the hash table. Comparisons: 0
Key 97986428 found in the hash table. Comparisons: 0
Key 56718265 found in the hash table. Comparisons: 0
Key 35966130 found in the hash table. Comparisons: 0
Key 99258153 not found in the hash table. Comparisons: 409600
Key 67737293 not found in the hash table. Comparisons: 409600
Key 10820813 not found in the hash table. Comparisons: 409600
Key 70111719 not found in the hash table. Comparisons: 409600
Key 39771580 found in the hash table. Comparisons: 0
Key 83246999 found in the hash table. Comparisons: 0
Key 46906783 found in the hash table. Comparisons: 0
Key 36600568 found in the hash table. Comparisons: 0
Key 37051599 not found in the hash table. Comparisons: 409600
Key 42315857 found in the hash table. Comparisons: 0
Key 87238974 found in the hash table. Comparisons: 0
Key 97592007 not found in the hash table. Comparisons: 409600
Key 64275429 found in the hash table. Comparisons: 0
Key 51649286 not found in the hash table. Comparisons: 409600
Key 56804407 found in the hash table. Comparisons: 0
Key 52779136 found in the hash table. Comparisons: 0
Key 77983247 not found in the hash table. Comparisons: 409600
Key 15916697 found in the hash table. Comparisons: 0
Key 70258238 found in the hash table. Comparisons: 0
Key 35557396 found in the hash table. Comparisons: 0
Key 56909625 not found in the hash table. Comparisons: 409600
Key 82348840 not found in the hash table. Comparisons: 409600
Key 21875289 not found in the hash table. Comparisons: 409600
Key 37969699 not found in the hash table. Comparisons: 409600
Key 83906259 not found in the hash table. Comparisons: 409600
Key 55743512 found in the hash table. Comparisons: 0
Key 34568631 found in the hash table. Comparisons: 0
Key 24892362 found in the hash table. Comparisons: 0
Key 73784304 not found in the hash table. Comparisons: 409600
Key 43937720 not found in the hash table. Comparisons: 409600
Key 50492010 found in the hash table. Comparisons: 0
Key 21075263 not found in the hash table. Comparisons: 409600
Key 11302238 not found in the hash table. Comparisons: 409600
Key 42882723 found in the hash table. Comparisons: 0
Key 20138140 found in the hash table. Comparisons: 0
Key 85068842 found in the hash table. Comparisons: 0
Key 48146293 found in the hash table. Comparisons: 0
Key 99869711 not found in the hash table. Comparisons: 409600
Key 46375986 found in the hash table. Comparisons: 0
Key 52695354 found in the hash table. Comparisons: 0
Key 27648480 found in the hash table. Comparisons: 0
Key 83262307 not found in the hash table. Comparisons: 409600
Key 98425454 found in the hash table. Comparisons: 0
Key 41388137 not found in the hash table. Comparisons: 409600
Key 21921408 not found in the hash table. Comparisons: 409600
Key 45282650 not found in the hash table. Comparisons: 409600
Key 97263188 not found in the hash table. Comparisons: 409600
Key 64758153 not found in the hash table. Comparisons: 409600
Key 59778376 not found in the hash table. Comparisons: 409600
Key 43637786 not found in the hash table. Comparisons: 409600
Key 84258720 found in the hash table. Comparisons: 0
Key 70053772 not found in the hash table. Comparisons: 409600
Key 22971905 not found in the hash table. Comparisons: 409600
Key 27691681 found in the hash table. Comparisons: 0
Key 64798973 not found in the hash table. Comparisons: 409600
Key 32051522 found in the hash table. Comparisons: 0
Key 84580155 found in the hash table. Comparisons: 0
Key 23079588 not found in the hash table. Comparisons: 409600
Key 19445301 found in the hash table. Comparisons: 0
Key 39032336 not found in the hash table. Comparisons: 409600
Key 85233999 not found in the hash table. Comparisons: 409600
Key 36406281 found in the hash table. Comparisons: 0
Key 99020052 found in the hash table. Comparisons: 0
Key 42947553 found in the hash table. Comparisons: 0
Key 99346327 not found in the hash table. Comparisons: 409600
Key 83673374 found in the hash table. Comparisons: 0
Key 67343291 found in the hash table. Comparisons: 0
Key 68978564 not found in the hash table. Comparisons: 409600
Key 33807703 not found in the hash table. Comparisons: 409600
Key 66541010 found in the hash table. Comparisons: 0
Key 66912047 found in the hash table. Comparisons: 0
Key 37801902 found in the hash table. Comparisons: 0
Key 93929255 not found in the hash table. Comparisons: 409600
Key 90094446 not found in the hash table. Comparisons: 409600
Key 72015588 not found in the hash table. Comparisons: 409600
Key 49980957 not found in the hash table. Comparisons: 409600
Key 69278776 not found in the hash table. Comparisons: 409600
Key 30349033 found in the hash table. Comparisons: 0
Key 80123356 not found in the hash table. Comparisons: 409600
Key 18041846 not found in the hash table. Comparisons: 409600
Key 27520871 not found in the hash table. Comparisons: 409600
Key 30617946 found in the hash table. Comparisons: 0
Key 55750064 found in the hash table. Comparisons: 0
Key 83130037 found in the hash table. Comparisons: 0
Key 10648565 not found in the hash table. Comparisons: 409600
Key 25035840 not found in the hash table. Comparisons: 409600
Key 81440411 not found in the hash table. Comparisons: 409600
Key 74866512 not found in the hash table. Comparisons: 409600
Key 95905677 found in the hash table. Comparisons: 0
Key 97192338 found in the hash table. Comparisons: 0
Key 44540804 not found in the hash table. Comparisons: 409600
Key 18651775 not found in the hash table. Comparisons: 409600
Key 90229668 found in the hash table. Comparisons: 0
Key 94876929 not found in the hash table. Comparisons: 409600
Key 51935268 found in the hash table. Comparisons: 0
Average comparisons per key: 204800.00
Memory used by hash table: 3276816 bytes
==353430==
==353430== HEAP SUMMARY:
==353430==     in use at exit: 0 bytes in 0 blocks
==353430==   total heap usage: 29 allocs, 29 frees, 6,558,600 bytes allocated
==353430==
==353430== All heap blocks were freed -- no leaks are possible
==353430==
==353430== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

If you want to use valgrind with full check and with lists of errors, run following command:

```bash
valgrind --leak-check=full -s ./hash_table
```

If you want to redirect valgrind checking to a file, use command below:

```bash
valgrind --leak-check=full -s --log-file="memory.log" ./hash_table
```
