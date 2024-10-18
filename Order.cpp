#include "Order.h"
#include "Dijkstra.h"
#include "AStar.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<Order, vector<Order>, ComparePriority> orderQueue;

void addOrder(int orderId, int restaurantId, int customerId, int priority) {
    Order order = {orderId, restaurantId, customerId, priority, -1};
    orderQueue.push(order);
}

void processOrders(Graph& cityMap, vector<Customer>& customers, vector<Restaurant>& restaurants, bool useAStar) {
    cityMap.updateTrafficConditions(); // Update traffic conditions dynamically

    while (!orderQueue.empty()) {
        Order currentOrder = orderQueue.top();
        orderQueue.pop();

        vector<double> dist = (useAStar) ? AStar::shortestPath(cityMap, currentOrder.restaurantId) 
                                         : Dijkstra::shortestPath(cityMap, currentOrder.restaurantId);
        double shortestPath = dist[currentOrder.customerId]; // Get the distance to the customer

        cout << "Order " << currentOrder.OrderId 
             << " (Restaurant: " << restaurants[currentOrder.restaurantId].name 
             << " to Customer: " << customers[currentOrder.customerId].name << ")"
             << " has a delivery time of " << shortestPath << " units." << endl;
    }
}
