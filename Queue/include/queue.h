#ifndef QUEUE_H
#define QUEUE_H

#define EMPTY_VALUE -1

#include <stdbool.h>

/// @brief Structure to represent the queue
typedef struct Queue_t Queue;

/**
 * @brief Initialize a new queue with a specified capacity
 * @param capacity Maximum capacity of the queue
 * @return A pointer to the initialized queue
 */
Queue *initQueue(int capacity);

/**
 * @brief Check if the queue is empty
 * @param queue Pointer to the queue
 * @return True if the queue is empty; otherwise, false
 */
bool isEmpty(Queue *queue);

/**
 * @brief Check if the queue is full
 * @param queue Pointer to the queue
 * @return True if the queue is full; otherwise, false
 */
bool isFull(Queue *queue);

/**
 * @brief Enqueue (push) an item into the queue
 * @param queue Pointer to the queue
 * @param item Item to be enqueued into the queue
 */
void enqueue(Queue *queue, int item);

/**
 * @brief Dequeue (pop) an item from the queue
 * @param queue Pointer to the queue
 * @return The dequeued item or -1 if the queue is empty
 */
int dequeue(Queue *queue);

/**
 * @brief Get the front item without removing it from the queue
 * @param queue Pointer to the queue
 * @return The front item or -1 if the queue is empty
 */
int front(Queue *queue);

/**
 * @brief Get the rear item without removing it from the queue
 * @param queue Pointer to the queue
 * @return The rear item or -1 if the queue is empty
 */
int rear(Queue *queue);

/**
 * @brief Get the size of the queue
 * @param queue Pointer to the queue
 * @return Size of the queue (count of elements)
 */
int size(Queue *queue);

/**
 * @brief Get the capacity of the queue
 * @param queue Pointer to the queue
 * @return Capacity of the queue (reserved count of elements)
 */
int capacity(Queue *queue);

/**
 * @brief Destroy the queue and free allocated memory
 * @param queue Pointer to the queue to be destroyed
 */
void destroyQueue(Queue *queue);

#endif // !QUEUE_H
