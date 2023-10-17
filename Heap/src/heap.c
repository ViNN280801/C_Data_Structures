#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/heap.h"

struct Heap_t
{
    int *data;    // Ptr to an integer array
    int size;     // Current count of elements in array
    int capacity; // Reserved space in the heap
};

Heap *createHeap(int capacity)
{
    Heap *heap = (Heap *)calloc(1, sizeof(Heap));
    if (!heap)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    heap->data = (int *)calloc(capacity, sizeof(int));
    if (!heap->data)
    {
        free(heap);
        heap = NULL;

        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void resizeHeap(Heap *heap, int newCapacity)
{
    int *new_data = (int *)malloc(newCapacity * sizeof(int));
    for (int i = 0; i < heap->size; i++)
        new_data[i] = heap->data[i];

    free(heap->data);
    heap->data = NULL;

    heap->data = new_data;
    heap->capacity = newCapacity;
}

void insert(Heap *heap, int value)
{
    if (heap->size >= heap->capacity)
    {
        int newCapacity = heap->capacity * 2; // Double the capacity
        resizeHeap(heap, newCapacity);
    }

    int index = heap->size;
    heap->data[index] = value;
    heap->size++;

    // Heapify the new element up to its correct position
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if (heap->data[index] > heap->data[parentIndex])
        {
            // Swap the element with its parent
            int temp = heap->data[index];
            heap->data[index] = heap->data[parentIndex];
            heap->data[parentIndex] = temp;
            index = parentIndex;
        }
        else
            break;
    }
}

int removeMax(Heap *heap)
{
    if (isEmpty(heap))
    {
        fprintf(stdout, "Heap is empty. Returning empty value, which is equals to -1\n");
        return EMPTY_VALUE;
    }

    int max = heap->data[0];
    heap->size--;

    if (heap->size > 0)
    {
        heap->data[0] = heap->data[heap->size];
        heapify(heap, 0);
    }

    return max;
}

bool isEmpty(Heap *heap) { return heap->size == 0; }

void heapify(Heap *heap, int index)
{
    int left = 2 * index + 1,
        right = 2 * index + 2,
        largest = index;

    if (left < heap->size && heap->data[left] > heap->data[largest])
        largest = left;

    if (right < heap->size && heap->data[right] > heap->data[largest])
        largest = right;

    if (largest != index)
    {
        int temp = heap->data[index];
        heap->data[index] = heap->data[largest];
        heap->data[largest] = temp;
        heapify(heap, largest);
    }
}

Heap *heapSort(Heap *heap)
{
    // Create a new heap with the same capacity
    Heap *sortedHeap = createHeap(heap->capacity);

    // Copy data from the original heap to the sorted heap
    for (int i = 0; i < heap->size; i++)
        insert(sortedHeap, heap->data[i]);

    // Sort the sorted heap in ascending order
    int sortedArray[heap->size];
    for (int i = 0; i < heap->size; i++)
        sortedArray[i] = removeMax(sortedHeap);

    // Copy the sorted array back to the original heap
    for (int i = 0; i < heap->size; i++)
        heap->data[i] = sortedArray[i];

    destroyHeap(sortedHeap); // Free the memory of the temporary heap

    return heap;
}

void heapSortWithoutReturnOrig(Heap *heap)
{
    // Create a new heap with the same capacity
    Heap *sortedHeap = createHeap(heap->capacity);

    // Copy data from the original heap to the sorted heap
    for (int i = 0; i < heap->size; i++)
        insert(sortedHeap, heap->data[i]);

    // Sort the sorted heap in ascending order
    int sortedArray[heap->size];
    for (int i = 0; i < heap->size; i++)
        sortedArray[i] = removeMax(sortedHeap);

    // Copy the sorted array back to the original heap
    for (int i = 0; i < heap->size; i++)
        heap->data[i] = sortedArray[i];

    destroyHeap(sortedHeap); // Free the memory of the temporary heap
}

void printHeap(Heap *heap)
{
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->data[i]);
    printf("\n");
}

void destroyHeap(Heap *heap)
{
    free(heap->data);
    heap->data = NULL;

    free(heap);
    heap = NULL;
}
