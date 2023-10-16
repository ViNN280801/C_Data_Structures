# String

## Description

The String is a versatile C library for handling strings dynamically. This library allows you to work with dynamic strings in C without the need to manage memory explicitly. It offers functions for various string operations, such as appending characters, appending C-style strings, getting string length, clearing string content, obtaining substrings, erasing characters or substrings, swapping strings, replacing substrings, finding substrings, and converting numbers to strings.
Functionality

The String provides the following functions:

- String \*initString(): Initializes a new dynamic string.
- void appendChar(String \*str, char c): Appends a character to the end of the string.
- void appendString(String *str, const char *source): Appends a C-style string to the end of the dynamic string.
- size_t length(String \*str): Retrieves the length of the string.
- const char *c_str(String *str): Gets a C-style string (char array) from the dynamic string.
- void clearString(String \*str): Clears the content of the dynamic string.
- String \*getSubstring(String \*str, size_t position, size_t length): Retrieves a substring starting at a specified position with the given length.
- void eraseChar(String \*str, size_t position): Erases a character at a specified position.
- void eraseSubstring(String \*str, size_t position, size_t length): Erases a substring starting at a specified position with the given length.
- void swapStrings(String *str1, String *str2): Swaps the contents of two dynamic strings.
- void replaceSubstring(String *str, size_t position, size_t length, const char *replacement): Replaces a specified portion of the string with another string.
- size_t findSubstring(String *str, const char *substring): Finds the first occurrence of a given substring.
- String \*intToString(int value): Converts an integral value to a dynamic string.
- String \*doubleToString(double value): Converts a floating-point value to a dynamic string.
- void destroyString(String \*str): Deallocates memory that string object hold.

## Compiling

You can compile the String implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Vector using the included compile.sh script:

```bash
gcc -c src/mystring.c -Wall -Wpedantic -Wextra -o src/mystring.o
gcc -c src/mystring_test.c -Wall -Wpedantic -Wextra -o src/mystring_test.o
gcc src/mystring.o src/mystring_test.o -Wall -Wpedantic -Wextra -o mystring
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
valgrind --leak-check=full -s ./mystring
```

### Output

```console
<loveit@fedora String>$ valgrind --leak-check=full -s ./mystring
==83771== Memcheck, a memory error detector
==83771== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==83771== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==83771== Command: ./mystring
==83771==
All tests passed!
==83771==
==83771== HEAP SUMMARY:
==83771==     in use at exit: 0 bytes in 0 blocks
==83771==   total heap usage: 16 allocs, 16 frees, 1,304 bytes allocated
==83771==
==83771== All heap blocks were freed -- no leaks are possible
==83771==
==83771== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there is no memory leaks.
