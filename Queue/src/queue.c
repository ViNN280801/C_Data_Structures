#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "../include/queue.h"

// Define the structure for the queue
struct Queue_t
{
    int *array;   // Pointer to the queue's array
    int size;     // Current count of elements
    int capacity; // Maximum capacity of the queue
    int front;    // Index of the front element
    int rear;     // Index of the rear element
};

Queue *initQueue(int capacity)
{
    Queue *queue = (Queue *)calloc(1, sizeof(Queue));
    if (!queue)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    queue->array = (int *)calloc(capacity, sizeof(int));
    if (!queue->array)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    queue->capacity = capacity;
    queue->front = queue->rear = EMPTY_VALUE;
    queue->size = 0;

    return queue;
}

bool isEmpty(Queue *queue) { return queue->size == 0; }

bool isFull(Queue *queue) { return queue->size == queue->capacity; }

void resize(Queue *queue, int newCapacity)
{
    queue->array = (int *)realloc(queue->array, newCapacity * sizeof(int));
    if (!queue->array)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    queue->capacity = newCapacity;
}

void enqueue(Queue *queue, int item)
{
    assert(queue->size <= queue->capacity);

    if (isFull(queue))
        resize(queue, queue->capacity * 2);

    if (isEmpty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear = (queue->rear + 1) % queue->capacity;

    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Returning empty value, that is equal to -1\n");
        return EMPTY_VALUE; // A default value for an empty queue
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    if (isEmpty(queue))
        queue->front = queue->rear = EMPTY_VALUE;

    return item;
}

int front(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Returning empty value, that is equal to -1\n");
        return EMPTY_VALUE;
    }
    return queue->array[queue->front];
}

int rear(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Returning empty value, that is equal to -1\n");
        return EMPTY_VALUE;
    }
    return queue->array[queue->rear];
}

int size(Queue *queue) { return queue->size; }

int capacity(Queue *queue) { return queue->capacity; }

void destroyQueue(Queue *queue)
{
    free(queue->array);
    queue->array = NULL;

    free(queue);
    queue = NULL;
}
