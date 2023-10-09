#include <stdio.h>
#include <stdbool.h>

#include "../include/deque.h"

int main()
{
    // Initialize a deque with a capacity of 5
    Deque *deque = initDeque(5);

    // Check if the deque is initially empty
    (isEmpty(deque)) ? printf("Deque is empty\n")
                     : printf("Deque is not empty\n");

    // Add elements to the rear and front of the deque
    addRear(deque, 42);
    addFront(deque, 10);
    addRear(deque, 7);
    addFront(deque, 32);
    addRear(deque, 55);

    // Attempt to add more elements than the deque capacity
    (isFull(deque)) ? printf("Deque is full\n")
                    : printf("Deque is not full\n");

    // Print the front and rear elements
    printf("Front element: %d\n", getFront(deque));
    printf("Rear element: %d\n", getRear(deque));

    // Delete elements from the front and rear of the deque
    while (!isEmpty(deque))
    {
        int itemFront = deleteFront(deque);
        int itemRear = deleteRear(deque);
        printf("Deleted from front: %d, Deleted from rear: %d\n", itemFront, itemRear);
    }

    // Check if the deque is empty after deleting all elements
    (isEmpty(deque)) ? printf("Deque is empty after deleting all elements\n")
                     : printf("Deque is not empty after deleting all elements\n");

    // Attempt to delete from an empty deque
    int itemFront = deleteFront(deque),
        itemRear = deleteRear(deque);

    printf("Item from empty deque (front): %d\n", itemFront);
    printf("Item from empty deque (rear): %d\n", itemRear);

    // Destroy the deque
    destroyDeque(deque);

    return 0;
}
