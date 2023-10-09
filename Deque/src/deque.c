#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/deque.h"

struct Deque_t
{
    int *array;   // Pointer to the queue's array
    int size;     // Current count of elements
    int capacity; // Maximum capacity of the queue
    int front;    // Index of the front element
    int rear;     // Index of the rear element
};

Deque *initDeque(int capacity)
{
    if (capacity <= 0)
    {
        printf("Invalid capacity. Please provide a positive capacity: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    Deque *deque = (Deque *)calloc(1, sizeof(Deque));
    if (!deque)
    {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    deque->array = (int *)calloc(capacity, sizeof(int));
    if (!deque->array)
    {
        if (deque)
            free(deque);
        deque = NULL;

        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    deque->capacity = capacity;
    deque->front = deque->rear = EMPTY_VALUE;
    deque->size = 0;

    return deque;
}

bool isEmpty(Deque *deque) { return deque->size == 0; }

bool isFull(Deque *deque) { return deque->size == deque->capacity; }

void resize(Deque *deque, int newCapacity)
{
    deque->array = (int *)realloc(deque->array, newCapacity * sizeof(int));
    if (!deque->array)
    {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    deque->capacity = newCapacity;
}

void addRear(Deque *deque, int value)
{
    if (isFull(deque))
        resize(deque, deque->capacity * 2);

    if (isEmpty(deque))
        deque->front = deque->rear = 0;
    else
        deque->rear = (deque->rear + 1) % deque->capacity;

    deque->array[deque->rear] = value;
    deque->size++;
}

void addFront(Deque *deque, int value)
{
    if (isFull(deque))
        resize(deque, deque->capacity * 2);

    if (isEmpty(deque))
        deque->front = deque->rear = 0;
    else
        deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;

    deque->array[deque->front] = value;
    deque->size++;
}

int deleteFront(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty. Returning empty value, that is equal to -1\n");
        return EMPTY_VALUE;
    }

    int value = deque->array[deque->front];
    if (deque->front == deque->rear)
        deque->front = deque->rear = EMPTY_VALUE;
    else
        deque->front = (deque->front + 1) % deque->capacity;

    deque->size--;

    return value;
}

int deleteRear(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty. Returning empty value, that is equal to -1\n");
        return EMPTY_VALUE;
    }

    int value = deque->array[deque->rear];
    if (deque->front == deque->rear)
        deque->front = deque->rear = EMPTY_VALUE;
    else
        deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;

    deque->size--;

    return value;
}

int getFront(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty. Returning empty value, that is equal to -1\n");
        return EMPTY_VALUE;
    }

    return deque->array[deque->front];
}

int getRear(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty. Returning empty value, that is equal to -1\n");
        return EMPTY_VALUE;
    }

    return deque->array[deque->rear];
}

int size(Deque *deque) { return deque->size; }

int capacity(Deque *deque) { return deque->capacity; }

void destroyDeque(Deque *deque)
{
    free(deque->array);
    deque->array = NULL;

    free(deque);
    deque = NULL;
}
