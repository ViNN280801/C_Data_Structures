#include <stdio.h>

#include "../include/graph.h"

int main()
{
    int capacity = 10;
    Graph *graph = createGraph(capacity);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 8);
    addEdge(graph, 5, 9);

    // Display the graph
    printf("Graph after adding edges:\n");
    display(graph);

    // Perform BFS starting from vertex 0
    printf("BFS starting from vertex 0: ");
    BFS(graph, 0);
    printf("\n");

    // Perform DFS starting from vertex 0
    printf("DFS starting from vertex 0: ");
    DFS(graph, 0);
    printf("\n");

    printf("Count of the vertices before remove: %d\n", countOfVertices(graph));

    // Remove a node (e.g., node 3)
    int nodeToRemove = 3;
    if (removeNode(graph, nodeToRemove))
        printf("Node %d removed\n", nodeToRemove);
    else
        printf("Node %d not found\n", nodeToRemove);

    printf("Count of the vertices after remove: %d\n", countOfVertices(graph));

    // Display the graph after node removal
    printf("Graph after removing node %d:\n", nodeToRemove);
    display(graph);

    // Clean up and destroy the graph
    destroyGraph(graph);

    return 0;
}
