#include "Mur.hpp"

Mur::Mur(int x, int y, int*** plateau) : Entity(-1) {
    this->x = x;
    this->y = y;
    this->plateau = plateau;
}

int Mur::getX() {
    return this->x;
}

int Mur::getY() {
    return this->y;
}

int*** Mur::getPlateau() {
    return this->plateau;
}

void Mur::setX(int x) {
    this->x = x;
}

void Mur::setY(int y) {
    this->y = y;
}

void Mur::setPlateau(int*** plateau) {
    this->plateau = plateau;
}
