#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/priority_queue.h"

struct Node_t
{
    int data;     // Data in node represented as integer value
    int priority; // Priority of the node
    Node *next;   // Ptr to the next node in queue
};

struct PriorityQueue_t
{
    Node *head; // Ptr to the head of the queue
};

// Initialize a new priority queue
PriorityQueue *initPriorityQueue()
{
    PriorityQueue *queue = (PriorityQueue *)calloc(1, sizeof(PriorityQueue));
    if (!queue)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    queue->head = NULL;
    return queue;
}

bool isEmpty(PriorityQueue *queue) { return !queue->head; }

void insert(PriorityQueue *queue, int data, int priority)
{
    Node *node = (Node *)calloc(1, sizeof(Node));
    if (!node)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    node->data = data;
    node->priority = priority;

    if (isEmpty(queue) || priority > queue->head->priority)
    {
        node->next = queue->head;
        queue->head = node;
    }
    else
    {
        Node *current = queue->head;
        while (current->next && priority <= current->next->priority)
            current = current->next;
        node->next = current->next;
        current->next = node;
    }
}

int extractMax(PriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        fprintf(stderr, "The priority queue is empty: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    Node *maxNode = queue->head;
    int maxData = maxNode->data;
    queue->head = maxNode->next;

    free(maxNode);
    maxNode = NULL;

    return maxData;
}

void destroyPriorityQueue(PriorityQueue *queue)
{
    Node *current = queue->head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
        temp = NULL;
    }

    free(queue);
    queue = NULL;
}
