#include "AStar.h"
#include <queue>
#include <unordered_map>
#include <cmath>
#include <limits>

using namespace std;

// Heuristic function for A* (Manhattan distance)
double heuristic(int a, int b) {
    return abs(a - b); 
}

vector<double> AStar::shortestPath(Graph& graph, int startNode) {
    int nodes = graph.adjList.size();
    vector<double> gScore(nodes, numeric_limits<double>::infinity());
    vector<double> fScore(nodes, numeric_limits<double>::infinity());
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> openSet;

    gScore[startNode] = 0.0;
    fScore[startNode] = heuristic(startNode, startNode); // Start node heuristic
    openSet.emplace(fScore[startNode], startNode);

    unordered_map<int, int> cameFrom; // To reconstruct the path

    while (!openSet.empty()) {
        int current = openSet.top().second;
        openSet.pop();

        for (const auto& edge : graph.adjList[current]) {
            int neighbor = edge.dest;
            double tentative_gScore = gScore[current] + edge.weight;

            if (tentative_gScore < gScore[neighbor]) {
                cameFrom[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                fScore[neighbor] = gScore[neighbor] + heuristic(neighbor, neighbor); // Goal heuristic

                openSet.push(make_pair(fScore[neighbor], neighbor)); 
            }
        }
    }

    return gScore;
}
