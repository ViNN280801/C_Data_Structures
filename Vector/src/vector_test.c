#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "../include/vector.h"

int main()
{
    // Create a vector with an initial capacity of 5
    Vector *vector = initVector(5);

    // Check if the vector is initially empty
    assert(isEmpty(vector));

    // Push some elements to the end of the vector
    for (int i = 0; i < 5; i++)
        push_back(vector, i * 10);

    // Check if the vector is not empty after inserting elements
    assert(!isEmpty(vector));

    // Check the size and capacity of the vector
    assert(size(vector) == 5);
    assert(capacity(vector) >= 5);

    // Insert an element at a specific position
    insert(vector, 10, 2);

    // Check the size after inserting an element
    assert(size(vector) == 6);

    // Check if the element at index 2 is 10
    assert(get(vector, 2) == 10);

    // Check the contents of the vector
    int *arr = data(vector);
    assert(arr[0] == 0);
    assert(arr[1] == 10);
    assert(arr[2] == 10);
    assert(arr[3] == 20);
    assert(arr[4] == 30);
    assert(arr[5] == 40);

    // Display the contents of the vector
    printf("Vector elements: ");
    print(vector);

    // Destroy the vector
    destroyVector(vector);

    printf("All tests passed!\n");

    return 0;
}
