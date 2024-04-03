#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Graph.h"

void doNumReachable(Graph g, int v, bool *visited) {
    visited[v] = true;

    for (int i = 0; i < GraphNumVertices(g); i++) {
        if (GraphIsAdjacent(g, v, i) && !visited[i]) {
            doNumReachable(g, i, visited);
        }
    }
}

// returns the number of vertices that are reachable from src
int numReachable(Graph g, int src) {
    bool *visited = calloc(GraphNumVertices(g), sizeof(bool));

    doNumReachable(g, src, visited);

    int count = 0;
    for (int i = 0; i < GraphNumVertices(g); i++) {
        if (visited[i]) count++;
    }

    free(visited);
    return count;
}
