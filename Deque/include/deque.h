#ifndef DEQUE_H
#define DEQUE_H

#define EMPTY_VALUE -1

#include <stdbool.h>

/// @brief Structure to represent the deque
typedef struct Deque_t Deque;

/**
 * @brief Initialize a new deque with a specified capacity
 * @param capacity Maximum capacity of the deque
 * @return A pointer to the initialized deque
 */
Deque *initDeque(int capacity);

/**
 * @brief Check if the deque is empty
 * @param deque Pointer to the deque
 * @return True if the deque is empty; otherwise, false
 */
bool isEmpty(Deque *deque);

/**
 * @brief Check if the deque is full
 * @param deque Pointer to the deque
 * @return True if the deque is full; otherwise, false
 */
bool isFull(Deque *deque);

/**
 * @brief Add an element at the rear end of the deque
 * @param deque Pointer to the deque
 * @param item Item to be added at the rear end
 */
void addRear(Deque *deque, int item);

/**
 * @brief Add an element at the front end of the deque
 * @param deque Pointer to the deque
 * @param item Item to be added at the front end
 */
void addFront(Deque *deque, int item);

/**
 * @brief Delete an element from the front end of the deque
 * @param deque Pointer to the deque
 * @return The deleted item or -1 if the deque is empty
 */
int deleteFront(Deque *deque);

/**
 * @brief Delete an element from the rear end of the deque
 * @param deque Pointer to the deque
 * @return The deleted item or -1 if the deque is empty
 */
int deleteRear(Deque *deque);

/**
 * @brief Get the front item without removing it from the deque
 * @param deque Pointer to the deque
 * @return The front item or -1 if the deque is empty
 */
int getFront(Deque *deque);

/**
 * @brief Get the rear item without removing it from the deque
 * @param deque Pointer to the deque
 * @return The rear item or -1 if the deque is empty
 */
int getRear(Deque *deque);

/**
 * @brief Get the size of the deque
 * @param deque Pointer to the deque
 * @return Size of the deque (count of elements)
 */
int size(Deque *deque);

/**
 * @brief Get the capacity of the deque
 * @param deque Pointer to the deque
 * @return Capacity of the deque (reserved count of elements)
 */
int capacity(Deque *deque);

/**
 * @brief Destroy the deque and free allocated memory
 * @param deque Pointer to the deque to be destroyed
 */
void destroyDeque(Deque *deque);

#endif // !DEQUE_H
