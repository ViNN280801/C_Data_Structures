#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

/// @brief Structure to represent Graph data structure in list representation
typedef struct Graph_t Graph;

/**
 * @brief Create a new graph with a given number of vertices
 * @param capacity Number of vertices in the graph
 * @return A pointer to the newly created graph
 */
Graph *createGraph(int capacity);

/**
 * @brief Add an edge between two vertices
 * @param graph Pointer to the graph
 * @param src Source vertex
 * @param dest Destination vertex
 */
void addEdge(Graph *graph, int src, int dest);

/**
 * @brief Remove a node with the given data from the graph
 * @param graph Pointer to the graph
 * @param data Data to be removed
 * @return true if the node is removed, false if not found
 */
bool removeNode(Graph *graph, int data);

/**
 * @brief Perform a Breadth-First Search (BFS) starting from a given vertex
 * @param graph Pointer to the graph
 * @param start Vertex to start BFS from
 */
void BFS(Graph *graph, int start);

/**
 * @brief Perform a Depth-First Search (DFS) starting from a given vertex
 * @param graph Pointer to the graph
 * @param start Vertex to start DFS from
 */
void DFS(Graph *graph, int start);

/**
 * @brief Getter for vertices
 * @param graph Pointer to the graph
 * @return Count of vertices in the graph
 */
int countOfVertices(Graph *graph);

/**
 * @brief Prints all elements of `graph` in terminal
 * @param graph Pointer to the graph
 */
void display(Graph *graph);

/**
 * @brief Destroy the graph and free the allocated memory
 * @param graph Pointer to the graph
 */
void destroyGraph(Graph *graph);

#endif // !GRAPH_H
