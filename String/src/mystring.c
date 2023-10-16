#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/mystring.h"

struct String_t
{
    char *data;      // Ptr to array
    size_t length;   // Current size of the array
    size_t capacity; // Maximum count of elements (reserved space)
};

String *initString()
{
    String *str = (String *)calloc(1, sizeof(String));
    if (!str)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    str->data = (char *)calloc(INITIAL_CAPACITY, sizeof(char));
    if (!str->data)
    {
        free(str);
        str = NULL;

        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    str->data[0] = NIL_TERMINATOR;
    str->length = 0;
    str->capacity = INITIAL_CAPACITY;
    return str;
}

void resize(String *str, size_t newCapacity)
{
    str->data = (char *)realloc(str->data, newCapacity);
    if (!str->data)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    str->capacity = newCapacity;
}

void appendChar(String *str, char c)
{
    if (str->length + 2 > str->capacity)
    {
        size_t newCapacity = (str->capacity == 0) ? INITIAL_CAPACITY : str->capacity * 2;
        resize(str, newCapacity);
    }
    str->data[str->length] = c;
    str->length++;
    str->data[str->length] = NIL_TERMINATOR;
}

void appendString(String *str, char const *source)
{
    if (!source)
    {
        fprintf(stderr, "Can't append null string: %s\n", strerror(errno));
        return;
    }
    size_t sourceLen = strlen(source),
           minCapacity = str->length + sourceLen + 1; // +1 for the null-terminator
    if (minCapacity > str->capacity)
    {
        size_t newCapacity = (str->capacity == 0) ? INITIAL_CAPACITY : str->capacity;
        while (newCapacity < minCapacity)
            newCapacity *= 2;
        resize(str, newCapacity);
    }
    strcpy(str->data + str->length, source);
    str->length += sourceLen;
}

char charAt(String *str, size_t index)
{
    if (index >= str->length)
    {
        fprintf(stderr, "Index out of bounds: %s\n", strerror(errno));
        return NIL_TERMINATOR;
    }
    return str->data[index];
}

size_t length(String *str) { return str->length; }

char const *c_str(String *str) { return str->data; }

void clearString(String *str)
{
    str->length = 0;
    str->data[0] = NIL_TERMINATOR;
}

String *getSubstring(String *str, size_t position, size_t length)
{
    if (position >= str->length)
    {
        fprintf(stderr, "Position out of bounds: %s\n", strerror(errno));
        return NULL;
    }
    if (position + length > str->length)
        length = str->length - position;

    String *subStr = initString();
    subStr->data = (char *)realloc(subStr->data, length + 1);
    if (subStr->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    strncpy(subStr->data, str->data + position, length);
    subStr->length = length;
    subStr->data[subStr->length] = NIL_TERMINATOR;
    return subStr;
}

void eraseChar(String *str, size_t position)
{
    if (position >= str->length)
    {
        fprintf(stderr, "Position out of bounds: %s\n", strerror(errno));
        return;
    }

    for (size_t i = position; i < str->length - 1; i++)
        str->data[i] = str->data[i + 1];

    str->length--;
    str->data[str->length] = NIL_TERMINATOR;
}

void eraseSubstring(String *str, size_t position, size_t length)
{
    if (position >= str->length)
    {
        fprintf(stderr, "Position out of bounds: %s\n", strerror(errno));
        return;
    }
    if (position + length > str->length)
        length = str->length - position;
    memmove(str->data + position, str->data + position + length, str->length - position - length);
    str->length -= length;
    str->data[str->length] = NIL_TERMINATOR; // Null-terminate the string
}

void swapStrings(String *str1, String *str2)
{
    char *tempData = str1->data;
    size_t tempLength = str1->length,
           tempCapacity = str1->capacity;

    str1->data = str2->data;
    str1->length = str2->length;
    str1->capacity = str2->capacity;
    str2->data = tempData;
    str2->length = tempLength;
    str2->capacity = tempCapacity;
}

void replaceSubstring(String *str, size_t position, size_t length, const char *replacement)
{
    if (position >= str->length)
    {
        fprintf(stderr, "Position out of bounds: %s\n", strerror(errno));
        return;
    }
    if (position + length > str->length)
        length = str->length - position;
    size_t replacementLength = strlen(replacement);
    if (length == replacementLength)
        memcpy(str->data + position, replacement, length);
    else if (length > replacementLength)
    {
        memcpy(str->data + position, replacement, replacementLength);
        memmove(str->data + position + replacementLength, str->data + position + length, str->length - position - length);
        str->length -= length - replacementLength;
        str->data[str->length] = NIL_TERMINATOR; // Null-terminate the string
    }
    else
    {
        if (str->length + replacementLength - length + 1 >= str->capacity)
        {
            while (str->length + replacementLength - length + 1 >= str->capacity)
                str->capacity *= 2;
            str->data = (char *)realloc(str->data, str->capacity);
            if (!str->data)
            {
                fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }
        }
        memmove(str->data + position + replacementLength, str->data + position + length, str->length - position - length);
        memcpy(str->data + position, replacement, replacementLength);
        str->length += replacementLength - length;
        str->data[str->length] = NIL_TERMINATOR; // Null-terminate the string
    }
}

size_t findSubstring(String *str, const char *substring)
{
    char *ptr = strstr(str->data, substring);
    if (!ptr)
        return STRING_NPOS; // Substring not found
    return ptr - str->data;
}

String *intToString(int value)
{
    String *str = initString();
    char buffer[20]; // Maximum length for a 32-bit integer
    snprintf(buffer, sizeof(buffer), "%d", value);
    appendString(str, buffer);
    return str;
}

String *doubleToString(double value)
{
    String *str = initString();
    char buffer[40]; // Maximum length for a double (with precision)
    snprintf(buffer, sizeof(buffer), "%lf", value);
    appendString(str, buffer);
    return str;
}

void destroyString(String *str)
{
    clearString(str);
    if (str)
    {
        free(str->data);
        str->data = NULL;

        free(str);
        str = NULL;
    }
}
