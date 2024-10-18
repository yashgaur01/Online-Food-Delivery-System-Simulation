#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <cstdlib> // For rand()

using namespace std;

struct Edge {
    int dest;
    int weight;
};

class Graph {
public:
    vector<vector<Edge>> adjList;           // Stores node connections and weights (distances)
    vector<vector<int>> trafficConditions;   // Stores dynamic traffic conditions

    Graph(int nodes);                        // Constructor to initialize the graph
    void addEdge(int src, int dest, int weight); // Adds an edge between src and dest
    void updateTrafficConditions();          // Updates traffic conditions randomly
};

#endif // GRAPH_H
