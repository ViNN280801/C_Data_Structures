#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>

// Structure to represent the circular queue
typedef struct CircularQueue CircularQueue;

/**
 * @brief Initialize a new circular queue with a specified capacity
 * @param capacity Maximum capacity of the circular queue
 * @return A pointer to the initialized circular queue
 */
CircularQueue *initCircularQueue(int capacity);

/**
 * @brief Check if the circular queue is empty
 * @param queue Pointer to the circular queue
 * @return True if the circular queue is empty; otherwise, false
 */
bool isEmpty(CircularQueue *queue);

/**
 * @brief Check if the circular queue is full
 * @param queue Pointer to the circular queue
 * @return True if the circular queue is full; otherwise, false
 */
bool isFull(CircularQueue *queue);

/**
 * @brief Enqueue (push) an item into the circular queue
 * @param queue Pointer to the circular queue
 * @param item Item to be enqueued
 */
void enqueue(CircularQueue *queue, int item);

/**
 * @brief Dequeue (pop) an item from the circular queue
 * @param queue Pointer to the circular queue
 * @return The dequeued item or -1 if the circular queue is empty
 */
int dequeue(CircularQueue *queue);

/**
 * @brief Display all the elements in the circular queue
 * @param queue Pointer to the circular queue
 */
void display(CircularQueue *queue);

/**
 * @brief Get the size of the circular queue
 * @param queue Pointer to the circular queue
 * @return Size of the circular queue (count of elements)
 */
int size(CircularQueue *queue);

/**
 * @brief Get the capacity of the circular queue
 * @param queue Pointer to the circular queue
 * @return Capacity of the circular queue (reserved count of elements)
 */
int capacity(CircularQueue *queue);

/**
 * @brief Destroy the circular queue and free allocated memory
 * @param queue Pointer to the circular queue to be destroyed
 */
void destroyCircularQueue(CircularQueue *queue);

#endif // !CIRCULAR_QUEUE_H
