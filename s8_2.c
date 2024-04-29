#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

// Function to find the minimum distance vertex not yet included in the path
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the path and its distance
void printPath(int parent[], int n, int graph[V][V]) {
    printf("Path: ");
    for (int i = 0; i < n; i++)
        printf("%d -> ", parent[i]);
    printf("0\n");

    printf("Distance: %d\n", graph[parent[n - 1]][0]);
}

// Function to implement the nearest neighbor algorithm for TSP
void nearestNeighbor(int graph[V][V]) {
    int parent[V]; // To store the nearest neighbor path
    int visited[V] = {0}; // Array to keep track of visited vertices
    int dist[V]; // Array to store distances from the current vertex

    // Initialize parent and dist arrays
    for (int i = 0; i < V; i++)
        parent[i] = -1, dist[i] = INT_MAX;

    // Start from the first vertex (0th index)
    visited[0] = 1;
    parent[0] = -1;
    dist[0] = 0;

    // Find the nearest neighbor for each vertex
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited); // Find the nearest neighbor
        visited[u] = 1; // Mark the vertex as visited

        // Update distances of the vertices not yet included in the path
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && graph[u][v] < dist[v])
                parent[v] = u, dist[v] = graph[u][v];
    }

    // Print the path and its distance
    printPath(parent, V, graph);
}

int main() {
    // Graph representation using adjacency matrix
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Find the nearest neighbor path
    nearestNeighbor(graph);

    return 0;
}
