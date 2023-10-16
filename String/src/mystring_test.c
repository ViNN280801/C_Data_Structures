#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../include/mystring.h"

int main()
{
    // Initialize a new string
    String *str = initString();

    // Test empty string
    assert(length(str) == 0);
    clearString(str);
    assert(length(str) == 0);

    // Test appending characters
    appendChar(str, 'H');
    appendChar(str, 'e');
    appendChar(str, 'l');
    appendChar(str, 'l');
    appendChar(str, 'o');
    appendChar(str, ',');
    appendChar(str, ' ');
    appendChar(str, 'W');
    appendChar(str, 'o');
    appendChar(str, 'r');
    appendChar(str, 'l');
    appendChar(str, 'd');
    assert(length(str) == 12);

    // Test appending C-style string
    appendString(str, " This is a dynamic string.");
    assert(length(str) == 38);
    assert(strcmp(c_str(str), "Hello, World This is a dynamic string.") == 0);

    // Test erasing a character
    eraseChar(str, 6); // Erasing first whitespace
    assert(length(str) == 37);
    assert(strcmp(c_str(str), "Hello,World This is a dynamic string.") == 0);

    // Test erasing a substring
    eraseSubstring(str, 6, 5); // Erasing "World"
    assert(length(str) == 32);
    assert(strcmp(c_str(str), "Hello, This is a dynamic string.") == 0);

    // Test swap
    String *str2 = initString();
    appendString(str2, "Another string");
    swapStrings(str, str2);
    assert(length(str) == 14);
    assert(length(str2) == 32);
    assert(strcmp(c_str(str), "Another string") == 0);
    assert(strcmp(c_str(str2), "Hello, This is a dynamic string.") == 0);
    destroyString(str2);

    // Test replace
    replaceSubstring(str, 0, 7, "Welcome");
    assert(length(str) == 14);
    assert(strcmp(c_str(str), "Welcome string") == 0);

    // Test find substring
    assert(findSubstring(str, "string") == 8);
    assert(findSubstring(str, "nonexistent") == (size_t)STRING_NPOS);

    // Test integer to string conversion
    String *intStr = intToString(12345);
    assert(length(intStr) == 5);
    assert(strcmp(c_str(intStr), "12345") == 0);
    destroyString(intStr);

    // Test double to string conversion
    String *doubleStr = doubleToString(3.14159);
    assert(length(doubleStr) == 8);
    assert(strcmp(c_str(doubleStr), "3.141590") == 0);
    destroyString(doubleStr);

    // Test get substring
    String *subStr = getSubstring(str, 0, 7);
    assert(length(subStr) == 7);
    assert(strcmp(c_str(subStr), "Welcome") == 0);
    destroyString(subStr);

    // Destroy the main string
    destroyString(str);

    printf("All tests passed!\n");

    return 0;
}
