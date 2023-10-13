#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <stdbool.h>

#define EMPTY_VALUE -1

/// Structure to represent a node in the circular doubly linked list
typedef struct Node_t Node;

/// Structure to represent the circular doubly linked list
typedef struct CircularDoublyLinkedList_t CircularDoublyLinkedList;

/**
 * Initialize a new circular doubly linked list
 * @return A pointer to the initialized circular doubly linked list
 */
CircularDoublyLinkedList *initCircularDoublyLinkedList();

/**
 * Check if the circular doubly linked list is empty
 * @param list Pointer to the circular doubly linked list
 * @return True if the list is empty; otherwise, false
 */
bool isEmpty(CircularDoublyLinkedList *list);

/**
 * Insert a new element at the beginning of the list
 * @param list Pointer to the circular doubly linked list
 * @param data Data to be inserted
 */
void insertAtBeginning(CircularDoublyLinkedList *list, int data);

/**
 * Insert a new element at the end of the list
 * @param list Pointer to the circular doubly linked list
 * @param data Data to be inserted
 */
void insertAtEnd(CircularDoublyLinkedList *list, int data);

/**
 * Insert a new element after a specific position in the list
 * @param list Pointer to the circular doubly linked list
 * @param data Data to be inserted
 * @param position Position after which the data is inserted (1-based index)
 */
void insertAfterPosition(CircularDoublyLinkedList *list, int data, int position);

/**
 * Delete the first occurrence of a specific element from the list
 * @param list Pointer to the circular doubly linked list
 * @param data Data to be deleted
 */
void deleteElement(CircularDoublyLinkedList *list, int data);

/**
 * Search for a specific element in the list
 * @param list Pointer to the circular doubly linked list
 * @param data Data to be searched
 * @return Position of the data (1-based index) or -1 if not found
 */
int search(CircularDoublyLinkedList *list, int data);

/**
 * Display all elements in the circular doubly linked list
 * @param list Pointer to the circular doubly linked list
 */
void display(CircularDoublyLinkedList *list);

/**
 * Get the number of elements in the list
 * @param list Pointer to the circular doubly linked list
 * @return Number of elements in the list
 */
int size(CircularDoublyLinkedList *list);

/**
 * Destroy the circular doubly linked list and free allocated memory
 * @param list Pointer to the circular doubly linked list to be destroyed
 */
void destroyCircularDoublyLinkedList(CircularDoublyLinkedList *list);

#endif // !CIRCULAR_DOUBLY_LINKED_LIST_H
