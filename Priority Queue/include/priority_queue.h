#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

/// @brief Structure to represent a node in the priority queue
typedef struct Node_t Node;

/// @brief Structure to represent the priority queue
typedef struct PriorityQueue_t PriorityQueue;

/**
 * Initialize a new priority queue
 * @return A pointer to the initialized priority queue
 */
PriorityQueue *initPriorityQueue();

/**
 * Check if the priority queue is empty
 * @param queue Pointer to the priority queue
 * @return True if the queue is empty; otherwise, false
 */
bool isEmpty(PriorityQueue *queue);

/**
 * Insert a new element with priority into the priority queue
 * @param queue Pointer to the priority queue
 * @param data Data to be inserted
 * @param priority Priority of the data (lower value indicates higher priority)
 */
void insert(PriorityQueue *queue, int data, int priority);

/**
 * Remove and return the element with the highest priority from the priority queue
 * @param queue Pointer to the priority queue
 * @return Data of the element with the highest priority
 */
int extractMax(PriorityQueue *queue);

/**
 * Destroy the priority queue and free allocated memory
 * @param queue Pointer to the priority queue to be destroyed
 */
void destroyPriorityQueue(PriorityQueue *queue);

#endif // !PRIORITY_QUEUE_H
