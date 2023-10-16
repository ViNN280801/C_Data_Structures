#ifndef MYSTRING_H
#define MYSTRING_H

#include <stddef.h>
#include <limits.h>

#define INITIAL_CAPACITY 8
#define NIL_TERMINATOR 0x00
#define STRING_NPOS -1

/// @brief Structure to represent a dynamic string
typedef struct String_t String;

/**
 * @brief Initialize a new dynamic string
 * @return A pointer to the initialized string
 */
String *initString();

/**
 * @brief Append a character to the end of the string
 * @param str Pointer to the string
 * @param c The character to append
 */
void appendChar(String *str, char c);

/**
 * @brief Append a C-style string to the end of the string
 * @param str Pointer to the string
 * @param source The source string to append
 */
void appendString(String *str, char const *source);

/**
 * @brief Get the length of the string
 * @param str Pointer to the string
 * @return The length of the string
 */
size_t length(String *str);

/**
 * @brief Get a C-style string (char array) from the string
 * @param str Pointer to the string
 * @return A pointer to the C-style string
 */
char const *c_str(String *str);
/**
 * @brief Clears the content of the string and resets its length to 0
 * @param str Pointer to the string
 */
void clearString(String *str);

/**
 * @brief Get a substring starting at the specified position with the given length
 * @param str Pointer to the string
 * @param position Position where the substring begins
 * @param length Length of the substring
 * @return A pointer to the substring
 */
String *getSubstring(String *str, size_t position, size_t length);

/**
 * @brief Erase one character at the specified position
 * @param str Pointer to the string
 * @param position Position of the character to erase
 */
void eraseChar(String *str, size_t position);

/**
 * @brief Erase a substring starting at the specified position with the given length
 * @param str Pointer to the string
 * @param position Position where the erasure begins
 * @param length Length of the substring to erase
 */
void eraseSubstring(String *str, size_t position, size_t length);

/**
 * @brief Swap the contents of two strings
 * @param str1 Pointer to the first string
 * @param str2 Pointer to the second string
 */
void swapStrings(String *str1, String *str2);

/**
 * @brief Replace specified portion of a string with another string
 * @param str Pointer to the string
 * @param position Position where the replacement begins
 * @param length Length of the portion to replace
 * @param replacement The string to replace with
 */
void replaceSubstring(String *str, size_t position, size_t length, const char *replacement);

/**
 * @brief Find the first occurrence of the given substring
 * @param str Pointer to the string
 * @param substring The substring to search for
 * @return The position of the first occurrence or STRING_NPOS if not found
 */
size_t findSubstring(String *str, const char *substring);

/**
 * @brief Convert an integral value to a string
 * @param value The integer to convert
 * @return A pointer to the string representation of the integer
 */
String *intToString(int value);

/**
 * @brief Convert a double value to a string
 * @param value The double to convert
 * @return A pointer to the string representation of the double
 */
String *doubleToString(double value);

/**
 * @brief Destroy the string and free the allocated memory
 * @param str Pointer to the string to be destroyed
 */
void destroyString(String *str);

#endif // !MYSTRING_H
