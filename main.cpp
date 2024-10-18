#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"
#include "AStar.h"
#include "Order.h"         
#include "Customer.h"
#include "Restaurant.h"
#include "Driver.h"

using namespace std;

int main() {
    // Create a graph with 7 nodes (more restaurants and customers)
    Graph cityMap(7);
    
    // Add edges (src, dest, weight)
    cityMap.addEdge(0, 1, 10); // Pizza Place to Burger Joint
    cityMap.addEdge(0, 2, 5);  // Pizza Place to Sushi Spot
    cityMap.addEdge(1, 2, 2);  // Burger Joint to Sushi Spot
    cityMap.addEdge(1, 3, 1);  // Burger Joint to Yash
    cityMap.addEdge(2, 1, 3);  // Sushi Spot to Burger Joint
    cityMap.addEdge(2, 3, 9);  // Sushi Spot to Siddharth
    cityMap.addEdge(3, 4, 4);  // Alice to Delivery Point
    cityMap.addEdge(3, 5, 6);  // Yash to Hardik's place
    cityMap.addEdge(4, 6, 3);  // Delivery Point to Siddharth
    cityMap.addEdge(5, 6, 2);  // Hardik's place to Siddharth

    // More customers and restaurants
    vector<Customer> customers = {
        Customer(0, "Yash"),
        Customer(1, "Hardik"),
        Customer(2, "Siddharth"),
        Customer(3, "Yash"), 
        Customer(4, "Shiven")   
    };
    
    vector<Restaurant> restaurants = {
        Restaurant(0, "Pizza Place"),
        Restaurant(1, "Burger Joint"),
        Restaurant(2, "Sushi Spot"),
        Restaurant(3, "Pasta House"), // New restaurant
        Restaurant(4, "Salad Bar")     // New restaurant
    };

    // Add some orders
    addOrder(0, 0, 1, 1); // Order from Pizza Place to Hardik
    addOrder(1, 1, 2, 3); // Order from Burger Joint to Yash
    addOrder(2, 2, 1, 1); // Order from Sushi Spot to Yash
    addOrder(3, 3, 2, 2); // Order from Pasta House to Hardik
    addOrder(4, 4, 3, 1); // Order from Salad Bar to Siddharth
    addOrder(5, 0, 2, 3); // Order from Pizza Place to Yash
    addOrder(6, 1, 4, 4); // Order from Burger Joint to Shiven

    // Process orders using Dijkstra's algorithm
    cout << "Processing orders using Dijkstra's Algorithm:\n";
    processOrders(cityMap, customers, restaurants, false);
    
    // Process orders using A* algorithm
    cout << "Processing orders using A* Algorithm:\n";
    processOrders(cityMap, customers, restaurants, true);

    return 0;
}
