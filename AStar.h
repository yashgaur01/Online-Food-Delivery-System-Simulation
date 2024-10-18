#ifndef ASTAR_H
#define ASTAR_H

#include "Graph.h"
#include <vector>

class AStar {
public:
    static std::vector<double> shortestPath(Graph& graph, int startNode);
};

#endif // ASTAR_H
