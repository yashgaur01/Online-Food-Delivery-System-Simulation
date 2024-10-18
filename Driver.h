#ifndef DRIVER_H
#define DRIVER_H

#include <string>

class Driver {
public:
    int id;
    std::string name;
    Driver(int id, std::string name) : id(id), name(name) {}
};

#endif // DRIVER_H
