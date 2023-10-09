#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#include "../include/circular_queue.h"

struct CircularQueue
{
    int *array;   // Pointer to the circular queue's array
    int size;     // Current count of elements
    int capacity; // Maximum capacity of the circular queue
    int front;    // Index of the front element
    int rear;     // Index of the rear element
};

CircularQueue *initCircularQueue(int capacity)
{
    CircularQueue *queue = (CircularQueue *)calloc(1, sizeof(CircularQueue));
    if (!queue)
    {
        fprintf(stderr, "Can't allocate memory for circular queue: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    queue->array = (int *)calloc(capacity, sizeof(int));
    if (!queue->array)
    {
        fprintf(stderr, "Can't allocate memory for circular queue array: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;

    return queue;
}

bool isEmpty(CircularQueue *queue) { return queue->size == 0; }

bool isFull(CircularQueue *queue) { return queue->size == queue->capacity; }

void enqueue(CircularQueue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Circular Queue is full. Cannot enqueue more elements.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Circular Queue is empty. Returning empty value, which is -1.\n");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void display(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Circular Queue is empty. Nothing to display.\n");
        return;
    }

    printf("Circular Queue: ");
    int i = queue->front;
    int count = 0;
    while (count < queue->size)
    {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
        count++;
    }
    printf("\n");
}

int size(CircularQueue *queue) { return queue->size; }

int capacity(CircularQueue *queue) { return queue->capacity; }

void destroyCircularQueue(CircularQueue *queue)
{
    free(queue->array);
    queue->array = NULL;

    free(queue);
    queue = NULL;
}
