#include "Graph.h"

Graph::Graph(int nodes) {
    adjList.resize(nodes);
    trafficConditions.resize(nodes, vector<int>(nodes, 0));  // Initialize traffic conditions with 0
}

void Graph::addEdge(int src, int dest, int weight) {
    Edge edgeToDest = {dest, weight};        // Create an Edge structure
    adjList[src].push_back(edgeToDest);      // Push the edge to the src node's adjacency list

    Edge edgeToSrc = {src, weight};          // Create reverse edge for an undirected graph
    adjList[dest].push_back(edgeToSrc);      // Push the reverse edge to the dest node's adjacency list
}

void Graph::updateTrafficConditions() {
    for (int i = 0; i < adjList.size(); ++i) {
        for (auto& edge : adjList[i]) {
            int trafficImpact = rand() % 10;  // Random traffic simulation (0 to 9)
            edge.weight += trafficImpact;     // Update edge weight with traffic impact
        }
    }
}
