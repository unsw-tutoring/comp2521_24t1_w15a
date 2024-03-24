/*
---> Important roads <---

A developer is planning a suburb, and they have represented the roads they
plan to build as edges in a connected, undirected graph.

However, due to budget cuts, they have decided to remove some roads.
A road is important if removing it would disconnect the graph.

Your task is to write a function to identify the important roads, so the
developer knows which roads can't be removed.

Implement the function importantRoads(Graph g), which prints the important
roads, each followed by a newline.

Roads should be printed in the form u-v, where u is the index of the
lower-numbered vertex and v is the index of the higher-numbered vertex.
They should be ordered in increasing order of u then v.

For example, if the graph is

0 --- 1 --- 6
|     |       7
|     |      /
2 --- 3 --- 4 --- 5

then your function should print
1-6
3-4
4-5
4-7
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Graph.h"

void importantRoads(Graph g) {
    // TODO
    return;
}
