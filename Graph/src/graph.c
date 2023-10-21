#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/graph.h"

/// @brief Structure to represent a node in the graph
struct Node
{
    int data;          // Data that node contains
    struct Node *next; // Ptr to the next nod
};

struct Graph_t
{
    int capacity;                // Reserved space in the graph
    int vertices;                // Count of vertices
    struct Node **adjacencyList; // List representation of a graph
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)calloc(1, sizeof(struct Node));
    if (!newNode)
    {
        fprintf(stderr, "Bad alloc: %s\nExiting with \"FAILURE\" status\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int capacity)
{
    if (capacity == 0)
    {
        fprintf(stderr, "Invalid value of \'capacity\' = %d: %s\n", capacity, strerror(errno));
        exit(EXIT_FAILURE);
    }

    Graph *graph = (Graph *)calloc(1, sizeof(Graph));
    if (!graph)
    {
        fprintf(stderr, "Bad alloc: %s\nExiting with \"FAILURE\" status\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    graph->vertices = 0;
    graph->capacity = capacity;
    graph->adjacencyList = (struct Node **)calloc(capacity, sizeof(struct Node *));
    if (!graph->adjacencyList)
    {
        if (graph)
            free(graph);
        graph = NULL;

        fprintf(stderr, "Bad alloc: %s\nExiting with \"FAILURE\" status\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < capacity; i++)
        graph->adjacencyList[i] = NULL;

    return graph;
}

void resizeGraph(Graph *graph, int newCapacity)
{
    struct Node **newList = (struct Node **)calloc(newCapacity, sizeof(struct Node *));
    if (!newList)
    {
        fprintf(stderr, "Bad alloc: %s\nExiting with \"FAILURE\" status\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *current = graph->adjacencyList[i];
        while (current)
        {
            int data = current->data;
            struct Node *next = current->next;
            int newIndex = data % newCapacity;

            current->next = newList[newIndex];
            newList[newIndex] = current;

            current = next;
        }
    }

    if (graph->adjacencyList)
        free(graph->adjacencyList);
    graph->adjacencyList = newList;
    graph->capacity = newCapacity;
}

void addEdge(Graph *graph, int src, int dest)
{
    if (src >= graph->capacity || dest >= graph->capacity)
    {
        fprintf(stderr, "Invalid vertex index\n");
        return;
    }

    // Check if the graph is full and resize if needed
    if (graph->vertices >= graph->capacity - 1)
    {
        int newCapacity = graph->capacity * 2; // Double the capacity
        resizeGraph(graph, newCapacity);
    }

    struct Node *newNode = createNode(dest);
    int index = src % graph->capacity;
    newNode->next = graph->adjacencyList[index];
    graph->adjacencyList[index] = newNode;
    graph->vertices++;
}

bool removeNode(Graph *graph, int data)
{
    for (int i = 0; i < graph->capacity; i++)
    {
        struct Node *current = graph->adjacencyList[i],
                    *prev = NULL;

        while (current)
        {
            if (current->data == data)
            {
                if (prev)
                    prev->next = current->next;
                else
                    // The node to be removed is the first in the list
                    graph->adjacencyList[i] = current->next;

                if (current)
                    free(current);
                current = NULL;

                graph->vertices--;
                return true;
            }

            prev = current;
            current = current->next;
        }
    }

    return false;
}

void BFS(Graph *graph, int start)
{
    if (start < 0 || start > graph->vertices)
    {
        fprintf(stderr, "Invalid starting vertex\n");
        return;
    }

    // Create a boolean array to keep track of visited vertices
    bool *visited = (bool *)calloc(graph->capacity, sizeof(bool));
    if (!visited)
    {
        fprintf(stderr, "Bad alloc: %s\n", strerror(errno));
        return;
    }

    // Create a queue to store vertices to be visited
    int *queue = (int *)calloc(graph->capacity, sizeof(int));
    if (!queue)
    {
        fprintf(stderr, "Bad alloc: %s\n", strerror(errno));
        if (visited)
            free(visited);
        visited = NULL;
        return;
    }

    int front = 0, // Front of the queue
        rear = 0;  // Rear of the queue

    // Mark the start vertex as visited and enqueue it
    visited[start] = true;
    queue[rear++] = start;

    // Perform BFS
    while (front < rear)
    {
        // Dequeue a vertex from the queue and display it
        int vertex = queue[front++];
        printf("%d ", vertex);

        // Traverse the adjacency list of the current vertex
        struct Node *current = graph->adjacencyList[vertex];
        while (current)
        {
            int neighbor = current->data;
            if (!visited[neighbor])
            {
                // Mark the neighbor as visited and enqueue it
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
            current = current->next;
        }
    }

    if (visited)
        free(visited);
    visited = NULL;

    if (queue)
        free(queue);
    queue = NULL;
}

void DFSHelper(Graph *graph, int vertex, bool visited[])
{
    visited[vertex] = true;

    struct Node *current = graph->adjacencyList[vertex];
    while (current)
    {
        int neighbor = current->data;

        printf("%d ", vertex);

        if (!visited[neighbor])
            DFSHelper(graph, neighbor, visited);
        current = current->next;
    }
}

void DFS(Graph *graph, int start)
{
    bool *visited = (bool *)calloc(graph->capacity, sizeof(bool));
    if (!visited)
    {
        fprintf(stderr, "Bad alloc: %s\n", strerror(errno));
        return;
    }

    for (int i = 0; i < graph->capacity; i++)
        visited[i] = false;
    DFSHelper(graph, start, visited);

    if (visited)
        free(visited);
    visited = NULL;
}

int countOfVertices(Graph *graph) { return graph->vertices; }

void display(Graph *graph)
{
    if (!graph)
    {
        fprintf(stderr, "Graph is empty\n");
        return;
    }

    printf("Adjacency List:\n");
    for (int i = 0; i < graph->capacity; i++)
    {
        printf("%d: ", i);
        struct Node *current = graph->adjacencyList[i];
        while (current)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void destroyGraph(Graph *graph)
{
    if (graph)
    {
        for (int i = 0; i < graph->vertices; i++)
        {
            struct Node *current = graph->adjacencyList[i];
            while (current)
            {
                struct Node *temp = current;
                current = current->next;
                if (temp)
                    free(temp);
                temp = NULL;
            }
        }

        if (graph->adjacencyList)
            free(graph->adjacencyList);
        graph->adjacencyList = NULL;

        if (graph)
            free(graph);
        graph = NULL;
    }
}
