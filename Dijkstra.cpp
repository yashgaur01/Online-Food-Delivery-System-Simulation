#include "Dijkstra.h"

using namespace std;

vector<double> Dijkstra::shortestPath(Graph& graph, int startNode) {
    int numNodes = graph.adjList.size();
    vector<double> dist(numNodes, numeric_limits<double>::max());
    dist[startNode] = 0.0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, startNode});

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        double currentDist = pq.top().first;
        pq.pop();

        for (const Edge& edge : graph.adjList[currentNode]) {
            int neighbor = edge.dest;
            double newDist = dist[currentNode] + edge.weight;

            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }
    return dist;
}
