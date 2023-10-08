#include <stdio.h>
#include <stdbool.h>

#include "../include/stack.h"

int main()
{
    // Initialize a stack with a capacity of 5
    Stack *stack = initStack(5);

    // Check if the stack is initially empty
    (isEmpty(stack)) ? printf("Stack is empty\n")
                     : printf("Stack is not empty\n");

    // Push elements onto the stack
    push(stack, 42);
    push(stack, 10);
    push(stack, 7);
    push(stack, 32);
    push(stack, 55);

    // Attempt to push more elements than the stack capacity
    (isFull(stack)) ? printf("Stack is full\n")
                    : printf("Stack is not full\n");

    // Print the top element
    printf("Top element: %d\n", peek(stack));

    // Pop elements from the stack and print them
    while (!isEmpty(stack))
    {
        int item = pop(stack);
        printf("Popped element: %d\n", item);
    }

    // Check if the stack is empty after popping all elements
    (isEmpty(stack)) ? printf("Stack is empty after popping all elements\n")
                     : printf("Stack is not empty after popping all elements\n");

    // Attempt to pop from an empty stack
    int item = pop(stack); // Should result in an error
    printf("Item from empty stack = %d\n", item);

    // Destroy the stack
    destroyStack(stack);

    return 0;
}
