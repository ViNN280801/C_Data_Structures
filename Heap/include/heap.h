#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

#define EMPTY_VALUE -1

/// @brief Structure to represent the heap
typedef struct Heap_t Heap;

/**
 * @brief Create a new heap with the specified capacity
 * @param capacity Maximum number of elements the heap can hold
 * @return A pointer to the newly created heap
 */
Heap *createHeap(int capacity);

/**
 * @brief Insert a new element into the heap
 * @param heap Pointer to the heap
 * @param value Value to be inserted
 */
void insert(Heap *heap, int value);

/**
 * @brief Remove and return the maximum element from the heap
 * @param heap Pointer to the heap
 * @return The maximum element
 */
int removeMax(Heap *heap);

/**
 * @brief Check if the heap is empty
 * @param heap Pointer to the heap
 * @return true if the heap is empty, false otherwise
 */
bool isEmpty(Heap *heap);

/**
 * @brief Heapify the heap, starting from the given index
 * @param heap Pointer to the heap
 * @param index The index to start heapify
 */
void heapify(Heap *heap, int index);

/**
 * @brief Sorts a heap in ascending order using Heap Sort
 * @param heap Pointer to the heap to be sorted
 * @return The original heap sorted in ascending order
 */
Heap *heapSort(Heap *heap);

/**
 * @brief Sorts a heap in ascending order using Heap Sort
 * @param heap Pointer to the heap to be sorted
 */
void heapSortWithoutReturnOrig(Heap *heap);

/**
 * @brief Prints heap to the terminal
 * @param heap Pointer to the heap
 */
void printHeap(Heap *heap);

/**
 * @brief Destroy the heap and free the allocated memory
 * @param heap Pointer to the heap
 */
void destroyHeap(Heap *heap);

#endif // !HEAP_H
