# Graph

## Description

A [graph](https://en.wikipedia.org/wiki/Graph_theory) is a data structure that consists of a finite set of vertices (nodes) and a set of edges connecting these vertices. Graphs are widely used to represent various relationships and connections between objects. This implementation provides a graph data structure in C using an adjacency list representation.

## Functionality

This Graph implementation provides the following operations:

- `createGraph(int capacity)`: Creates a new graph with the specified capacity.
- `addEdge(Graph *graph, int src, int dest)`: Adds an edge between two vertices.
- `removeNode(Graph *graph, int data)`: Removes a node with the given data from the graph.
- `BFS(Graph *graph, int start)`: Performs Breadth-First Search (BFS) starting from a given vertex.
- `DFS(Graph *graph, int start)`: Performs Depth-First Search (DFS) starting from a given vertex.
- `countOfVertices(Graph *graph)`: Returns the count of vertices in the graph.
- `display(Graph *graph)`: Prints all elements of the graph.
- `destroyGraph(Graph *graph)`: Destroys the graph and frees the allocated memory.

## Compiling

You can compile the Graph implementation using the provided scripts:

### Bash Script

Run the following commands to compile the Graph using the included compile.sh script:

```bash
gcc -c src/graph.c -Wall -Wpedantic -Wextra -o src/graph.o
gcc -c src/graph_test.c -Wall -Wpedantic -Wextra -o src/graph_test.o
gcc src/graph.o src/graph_test.o -Wall -Wpedantic -Wextra -o graph
```

or execute just ./compile.sh

```bash
./compile.sh
```

The script compiles the source files separately with GCC compiler, using necessary flags and the C standard revision.

### CMake

Alternatively, you can use CMake for compilation. Here are the commands:

```bash
cmake .
cmake --build .
```

or

```bash
cmake .
make
```

## Memory Leaks

A test program is provided in **graph_test.c**, which initializes a graph, adds edges, performs BFS, DFS, and checks for emptiness. To check for memory leaks, you can use Valgrind. Run the following command:

```bash
valgrind --leak-check=full -s ./graph
```

### Output

```console
<loveit@fedora Graph>$ valgrind --leak-check=full -s ./graph
==126761== Memcheck, a memory error detector
==126761== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==126761== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==126761== Command: ./graph
==126761==
Graph after adding edges:
Adjacency List:
0: 2 -> 1 -> NULL
1: 3 -> NULL
2: 5 -> 4 -> NULL
3: 7 -> 6 -> NULL
4: 8 -> NULL
5: 9 -> NULL
6: NULL
7: NULL
8: NULL
9: NULL
BFS starting from vertex 0: 0 2 1 5 4 3 9 8 7 6
DFS starting from vertex 0: 0 2 5 2 4 0 1 3 3
Count of the vertices before remove: 9
Node 3 removed
Count of the vertices after remove: 8
Graph after removing node 3:
Adjacency List:
0: 2 -> 1 -> NULL
1: NULL
2: 5 -> 4 -> NULL
3: 7 -> 6 -> NULL
4: 8 -> NULL
5: 9 -> NULL
6: NULL
7: NULL
8: NULL
9: NULL
==126761==
==126761== HEAP SUMMARY:
==126761==     in use at exit: 0 bytes in 0 blocks
==126761==   total heap usage: 15 allocs, 15 frees, 1,324 bytes allocated
==126761==
==126761== All heap blocks were freed -- no leaks are possible
==126761==
==126761== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As you can see, there are no any errors or memory leaks.
