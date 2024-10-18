#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
public:
    int id;
    string name;
    Customer(int id, string name) : id(id), name(name) {}
};

#endif // CUSTOMER_H
