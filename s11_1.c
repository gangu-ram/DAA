#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4 // Number of vertices

// Graph representation using adjacency matrix
int graph[V][V] = {
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {1, 0, 0, 1},
    {0, 0, 0, 1}
};

// Array to keep track of visited vertices
bool visited[V];

// Depth First Search (DFS) function
void DFS(int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    // Initialize visited array
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    printf("Depth First Search starting from vertex 0:\n");
    DFS(0); // Start DFS from vertex 0

    return 0;
}
