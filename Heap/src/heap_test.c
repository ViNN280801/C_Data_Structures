#include <stdio.h>
#include <stdbool.h>

#include "../include/heap.h"

int main()
{
    // Create a heap with a capacity of 10
    Heap *heap = createHeap(10);

    // Insert elements into the heap
    insert(heap, 5);
    insert(heap, 9);
    insert(heap, 2);
    insert(heap, 12);
    insert(heap, 1);
    insert(heap, 6);

    for (int i = 0; i < 20; i++)
        insert(heap, i);

    printf("Heap after insertions: ");
    printHeap(heap);

    // Sort the heap using heapSort
    heapSortWithoutReturnOrig(heap);
    printf("Heap after sorting: ");
    printHeap(heap);

    // Check if the original heap is empty
    if (isEmpty(heap))
        printf("Original heap is empty\n");
    else
        printf("Original heap is not empty\n");

    // Destroy the heap
    destroyHeap(heap);

    return 0;
}
