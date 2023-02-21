#include "IA.hpp"

IA::IA(int x, int y, int** plateau, int score) {
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
    return this->score;
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
    this->score = score;
}

void IA::setPlateau(int** plateau) {
    this->plateau = plateau;
}

void IA::play() {
    this->algo(0);
}

void IA::algo(int a) {
    switch(a) {
        case 0:
            if(this->x > 0 && this->plateau[this->x - 1][this->y] == 0) {
                this->x--;
            } else if (this->y > 0 && this->plateau[this->x][this->y - 1] == 0) {
                this->y--;
            } else if (this->x < 9 && this->plateau[this->x + 1][this->y] == 0) {
                this->x++;
            } else if (this->y < 9 && this->plateau[this->x][this->y + 1] == 0) {
                this->y++;
            } else {
                this->score = -1;
            }
            break;
        default:
            break;
    }
}