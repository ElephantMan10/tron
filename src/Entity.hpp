#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <string>

using namespace std;

class Entity {
    private:
        int id;
    public:
        Entity(int id);
        int getId();
        void setId(int id);
};

#endif