/*
---> Friendliest person <---

In a social network, the 'friendliness' of a user p is given by

(number of friends) + 1/2 (number of friends of friends) 
+ 1/3 (num friends of friends of friends) + 1/4 ...

That is,
                   ∞
friendliness(p) =  Σ  (1/n) * (num users u where length of shortest path p to u = n)
                  n=1

You should use doubles when calculating the friendliness of a user.

Write the function friendliestPerson(Graph g, int p), which takes an undirected Graph
representing a social network and returns the friendliness of the user p.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Graph.h"

double friendliness(Graph g, int p) {
    // TODO
    return 0.0;
}
