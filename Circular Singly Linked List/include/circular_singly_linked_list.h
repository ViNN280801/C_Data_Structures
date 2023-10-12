#ifndef CIRCULAR_SINGLY_LINKED_LIST_H
#define CIRCULAR_SINGLY_LINKED_LIST_H

#include <stdbool.h>

#define EMPTY_VALUE -1

/// Structure to represent a node in the circular singly linked list
typedef struct Node_t Node;

/// Structure to represent the circular singly linked list
typedef struct CircularSinglyLinkedList_t CircularSinglyLinkedList;

/**
 * Initialize a new circular singly linked list
 * @return A pointer to the initialized circular singly linked list
 */
CircularSinglyLinkedList *initCircularSinglyLinkedList();

/**
 * Check if the circular singly linked list is empty
 * @param list Pointer to the circular singly linked list
 * @return True if the list is empty; otherwise, false
 */
bool isCircularSinglyLinkedListEmpty(CircularSinglyLinkedList *list);

/**
 * Insert a new element at the beginning of the list
 * @param list Pointer to the circular singly linked list
 * @param data Data to be inserted
 */
void insertAtBeginning(CircularSinglyLinkedList *list, int data);

/**
 * Insert a new element at the end of the list
 * @param list Pointer to the circular singly linked list
 * @param data Data to be inserted
 */
void insertAtEnd(CircularSinglyLinkedList *list, int data);

/**
 * Insert a new element after a specific position in the list
 * @param list Pointer to the circular singly linked list
 * @param data Data to be inserted
 * @param position Position after which the data is inserted (1-based index)
 */
void insertAfterPosition(CircularSinglyLinkedList *list, int data, int position);

/**
 * Delete the first occurrence of a specific element from the list
 * @param list Pointer to the circular singly linked list
 * @param data Data to be deleted
 */
void deleteElement(CircularSinglyLinkedList *list, int data);

/**
 * Search for a specific element in the list
 * @param list Pointer to the circular singly linked list
 * @param data Data to be searched
 * @return Position of the data (1-based index) or -1 if not found
 */
int search(CircularSinglyLinkedList *list, int data);

/**
 * Display all elements in the circular singly linked list
 * @param list Pointer to the circular singly linked list
 */
void display(CircularSinglyLinkedList *list);

/**
 * Get the number of elements in the list
 * @param list Pointer to the circular singly linked list
 * @return Number of elements in the list
 */
int size(CircularSinglyLinkedList *list);

/**
 * Destroy the circular singly linked list and free allocated memory
 * @param list Pointer to the circular singly linked list to be destroyed
 */
void destroyCircularSinglyLinkedList(CircularSinglyLinkedList *list);

#endif // !CIRCULAR_SINGLY_LINKED_LIST_H
