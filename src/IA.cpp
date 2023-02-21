#include "IA.hpp"

IA::IA(int x, int y, int** plateau, int* score) {
    this->x = x;
    this->y = y;
    this->plateau = plateau;
    this->score = score;
}

int IA::getX() {
    return this->x;
}

int IA::getY() {
    return this->y;
}

int IA::getScore() {
    return *this->score;
}

int** IA::getPlateau() {
    return this->plateau;
}

void IA::setX(int x) {
    this->x = x;
}

void IA::setY(int y) {
    this->y = y;
}

void IA::setScore(int score) {
    *this->score = score;
}

void IA::setPlateau(int** plateau) {
    this->plateau = plateau;
}
