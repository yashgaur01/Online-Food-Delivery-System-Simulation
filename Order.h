#ifndef ORDER_H
#define ORDER_H

#include "Customer.h"
#include "Restaurant.h"
#include "Graph.h"
#include <queue>
#include <vector>

struct Order {
    int OrderId;
    int restaurantId;
    int customerId;
    int priority;
    int assignedDriverId;
};

struct ComparePriority {
    bool operator()(const Order& a, const Order& b) {
        return a.priority > b.priority; // Lower priority number means higher priority
    }
};

// Declare functions
void addOrder(int orderId, int restaurantId, int customerId, int priority);
void processOrders(Graph& cityMap, std::vector<Customer>& customers, std::vector<Restaurant>& restaurants, bool useAStar);

#endif // ORDER_H
