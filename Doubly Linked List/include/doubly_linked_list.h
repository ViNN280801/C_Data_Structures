#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>

/// @brief Structure to represent a node in the doubly linked list
typedef struct Node_t Node;

/// @brief Structure to represent the doubly linked list
typedef struct DoublyLinkedList_t DoublyLinkedList;

/**
 * @brief Initialize a new doubly linked list
 * @return A pointer to the initialized doubly linked list
 */
DoublyLinkedList *initDoublyLinkedList();

/**
 * @brief Check if the doubly linked list is empty
 * @param list Pointer to the doubly linked list
 * @return True if the list is empty; otherwise, false
 */
bool isEmpty(DoublyLinkedList *list);

/**
 * @brief Insert a new element at the beginning of the list
 * @param list Pointer to the doubly linked list
 * @param data Data to be inserted
 */
void insertAtBeginning(DoublyLinkedList *list, int data);

/**
 * @brief Insert a new element at the end of the list
 * @param list Pointer to the doubly linked list
 * @param data Data to be inserted
 */
void insertAtEnd(DoublyLinkedList *list, int data);

/**
 * @brief Delete the first occurrence of a specific element from the list
 * @param list Pointer to the doubly linked list
 * @param data Data to be deleted
 */
void deleteElement(DoublyLinkedList *list, int data);

/**
 * @brief Display all elements in the doubly linked list
 * @param list Pointer to the doubly linked list
 */
void display(DoublyLinkedList *list);

/**
 * @brief Get the number of elements in the list
 * @param list Pointer to the doubly linked list
 * @return Number of elements in the list
 */
int size(DoublyLinkedList *list);

/**
 * @brief Destroy the doubly linked list and free allocated memory
 * @param list Pointer to the doubly linked list to be destroyed
 */
void destroyDoublyLinkedList(DoublyLinkedList *list);

#endif // !DOUBLY_LINKED_LIST_H
