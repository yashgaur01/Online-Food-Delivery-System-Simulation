#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>

using namespace std;

class Restaurant {
public:
    int id;
    string name;
    Restaurant(int id, string name) : id(id), name(name) {}
};

#endif // RESTAURANT_H
