#include "Entity.hpp"

Entity::Entity(int id) {
    this->id = id;
}

int Entity::getId() {
    return this->id;
}

void Entity::setId(int id) {
    this->id = id;
}