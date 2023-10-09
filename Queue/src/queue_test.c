#include <stdio.h>
#include <stdbool.h>

#include "../include/queue.h"

int main()
{
    // Initialize a queue with a capacity of 5
    Queue *queue = initQueue(5);

    // Check if the queue is initially empty
    (isEmpty(queue)) ? printf("Queue is empty\n") : printf("Queue is not empty\n");

    // Enqueue (push) elements into the queue
    enqueue(queue, 42);
    enqueue(queue, 10);
    enqueue(queue, 7);
    enqueue(queue, 32);
    enqueue(queue, 55);

    // Attempt to enqueue more elements than the queue capacity
    (isFull(queue)) ? printf("Queue is full\n") : printf("Queue is not full\n");

    // Print the front and rear elements
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    // Dequeue (pop) elements from the queue and print them
    while (!isEmpty(queue))
    {
        int item = dequeue(queue);
        printf("Dequeued element: %d\n", item);
    }

    // Check if the queue is empty after dequeuing all elements
    (isEmpty(queue)) ? printf("Queue is empty after dequeuing all elements\n")
                     : printf("Queue is not empty after dequeuing all elements\n");

    // Attempt to dequeue from an empty queue
    int item = dequeue(queue); // Should result in an error
    printf("Item from empty queue = %d\n", item);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}
