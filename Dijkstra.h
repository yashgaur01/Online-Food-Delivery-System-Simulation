#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include <vector>
#include <queue>
#include <limits>

class Dijkstra {
public:
    static std::vector<double> shortestPath(Graph& graph, int startNode);
};

#endif // DIJKSTRA_H
