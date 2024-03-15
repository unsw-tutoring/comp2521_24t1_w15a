#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph *Graph;

Graph GraphNew(int nV);

void GraphAddEdge(Graph g, int v, int u);

void GraphRemoveEdge(Graph g, int v, int u);

#endif
