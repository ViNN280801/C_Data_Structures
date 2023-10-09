#include <stdio.h>
#include <stdbool.h>

#include "../include/circular_queue.h"

int main()
{
    // Initialize a circular queue with a capacity of 5
    CircularQueue *queue = initCircularQueue(5);

    // Check if the circular queue is initially empty
    (isEmpty(queue)) ? printf("Circular Queue is empty\n")
                     : printf("Circular Queue is not empty\n");

    // Enqueue (push) elements into the circular queue
    enqueue(queue, 42);
    enqueue(queue, 10);
    enqueue(queue, 7);
    enqueue(queue, 32);
    enqueue(queue, 55);

    // Attempt to enqueue more elements than the circular queue capacity
    (isFull(queue)) ? printf("Circular Queue is full\n")
                    : printf("Circular Queue is not full\n");

    // Display all elements in the circular queue
    display(queue);

    // Dequeue (pop) elements from the circular queue and print them
    while (!isEmpty(queue))
    {
        int item = dequeue(queue);
        printf("Dequeued element: %d\n", item);
    }

    // Check if the circular queue is empty after dequeuing all elements
    (isEmpty(queue)) ? printf("Circular Queue is empty after dequeuing all elements\n")
                     : printf("Circular Queue is not empty after dequeuing all elements\n");

    // Attempt to dequeue from an empty circular queue
    int item = dequeue(queue); // Should result in an error
    printf("Item from empty circular queue = %d\n", item);

    // Destroy the circular queue
    destroyCircularQueue(queue);

    return 0;
}
