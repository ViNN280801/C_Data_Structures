#ifndef VECTOR_H
#define VECTOR_H

#define EMPTY_VALUE -1

/// @brief Structure to represent a vector
typedef struct Vector_t Vector;

/**
 * @brief Initialize a new vector with a specified size
 * @param capacity Maximum size of the vector
 * @return A pointer to the initialized vector
 */
Vector *initVector(int capacity);

/**
 * @brief Check if the vector is empty
 * @param vector Pointer to the vector
 * @return True if the vector is empty; otherwise, false
 */
bool isEmpty(Vector *vector);

/**
 * @brief Insert an element into the end of the vector
 * @param vector Pointer to the vector
 * @param value Value to be inserted into the vector
 * @return "true" if the insertion is successful; otherwise, "false"
 */
bool push_back(Vector *vector, int value);

/**
 * @brief Insert an element into the vector at a specified position
 * @param vector Pointer to the vector
 * @param value Value to be inserted into the vector
 * @param index Index at which to insert the value
 * @return "true" if the insertion is successful; otherwise, "false"
 */
bool insert(Vector *vector, int value, int index);

/**
 * @brief Retrieve an element from the vector at a specified index
 * @param vector Pointer to the vector
 * @param index Index of the element to retrieve
 * @return The element at the specified index
 */
int get(Vector *vector, int index);

/**
 * @brief Getter for size
 * @param vector Pointer to the vector
 * @return Current count of elements in the vector
 */
int size(Vector *vector);

/**
 * @brief Getter for capacity
 * @param vector Pointer to the vector
 * @return Reserved space in vector
 */
int capacity(Vector *vector);

/**
 * @brief Getter for underlying array
 * @param vector Pointer to the vector
 * @return Reserved space in vector
 */
int *data(Vector *vector);

/**
 * @brief Displays all elements in vector
 * @param vector Pointer to the vector
 */
void print(Vector *vector);

/**
 * @brief Destroy the vector and free the allocated memory
 * @param vector Pointer to the vector to be destroyed
 */
void destroyVector(Vector *vector);

#endif // !VECTOR_H
