#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h>

/// @brief Structure to represent a node in the singly linked list
typedef struct Node_t Node;

/// @brief Structure to represent the singly linked list
typedef struct SinglyLinkedList_t SinglyLinkedList;

/**
 * @brief Initialize a new singly linked list
 * @return A pointer to the initialized singly linked list
 */
SinglyLinkedList *initSinglyLinkedList();

/**
 * @brief Check if the singly linked list is empty
 * @param list Pointer to the singly linked list
 * @return True if the list is empty; otherwise, false
 */
bool isEmpty(SinglyLinkedList *list);

/**
 * @brief Insert a new element at the beginning of the list
 * @param list Pointer to the singly linked list
 * @param data Data to be inserted
 */
void insertAtBeginning(SinglyLinkedList *list, int data);

/**
 * @brief Insert a new element at the end of the list
 * @param list Pointer to the singly linked list
 * @param data Data to be inserted
 */
void insertAtEnd(SinglyLinkedList *list, int data);

/**
 * @brief Insert a new element after a specific position in the list
 * @param list Pointer to the singly linked list
 * @param data Data to be inserted
 * @param position Position after which the data is inserted (1-based index)
 */
void insertAfterPosition(SinglyLinkedList *list, int data, int position);

/**
 * @brief Delete the first occurrence of a specific element from the list
 * @param list Pointer to the singly linked list
 * @param data Data to be deleted
 */
void deleteElement(SinglyLinkedList *list, int data);

/**
 * @brief Search for a specific element in the list
 * @param list Pointer to the singly linked list
 * @param data Data to be searched
 * @return Position of the data (1-based index) or -1 if not found
 */
int search(SinglyLinkedList *list, int data);

/**
 * @brief Display all elements in the singly linked list
 * @param list Pointer to the singly linked list
 */
void display(SinglyLinkedList *list);

/**
 * @brief Get the number of elements in the list
 * @param list Pointer to the singly linked list
 * @return Number of elements in the list
 */
int size(SinglyLinkedList *list);

/**
 * @brief Destroy the singly linked list and free allocated memory
 * @param list Pointer to the singly linked list to be destroyed
 */
void destroySinglyLinkedList(SinglyLinkedList *list);

#endif // !SINGLY_LINKED_LIST_H
