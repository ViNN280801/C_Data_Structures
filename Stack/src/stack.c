#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "../include/stack.h"

struct Stack_t
{
    int *array;   // Pointer to the stack's array
    int size;     // Current count of elements
    int capacity; // Maximum capacity of the stack
    int top;      // Index of the top element
};

Stack *initStack(int capacity)
{
    Stack *stack = (Stack *)calloc(1, sizeof(Stack));
    if (!stack)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    stack->array = (int *)calloc(capacity, sizeof(int));
    if (!stack->array)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    stack->capacity = capacity;
    stack->top = EMPTY_VALUE;
    stack->size = 0;

    return stack;
}

bool isEmpty(Stack *stack) { return stack->size == 0; }

bool isFull(Stack *stack) { return stack->size == stack->capacity; }

void resize(Stack *stack, int newCapacity)
{
    stack->array = (int *)realloc(stack->array, newCapacity * sizeof(int));
    if (!stack->array)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    stack->capacity = newCapacity;
}

void push(Stack *stack, int item)
{
    assert(stack->size <= stack->capacity);

    if (isFull(stack))
        resize(stack, stack->capacity * 2);

    stack->array[++stack->top] = item;
    stack->size++;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Returning empty value, that is equals %d\n", EMPTY_VALUE);
        return EMPTY_VALUE; // A default value for an empty stack
    }
    stack->size--;
    return stack->array[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Returning empty value, that is equals %d\n", EMPTY_VALUE);
        return EMPTY_VALUE;
    }
    return stack->array[stack->top];
}

int size(Stack *stack) { return stack->size; }

int capacity(Stack *stack) { return stack->capacity; }

void destroyStack(Stack *stack)
{
    free(stack->array);
    stack->array = NULL;

    free(stack);
    stack = NULL;
}
