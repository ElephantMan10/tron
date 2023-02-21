#include "Joueur.hpp"

Joueur::Joueur(int x, int y, int** plateau, int id, IA *ia) : Entity(id) {
    this->x = x;
    this->y = y;
    this->plateau = plateau;
    this->ia = ia;
    this->score = 0;
}

int Joueur::getX() {
    return this->x;
}

int Joueur::getY() {
    return this->y;
}

int Joueur::getScore() {
    return this->score;
}

int** Joueur::getPlateau() {
    return this->plateau;
}

void Joueur::setX(int x) {
    this->x = x;
}

void Joueur::setY(int y) {
    this->y = y;
}

void Joueur::setScore(int score) {
    this->score = score;
}

void Joueur::setPlateau(int** plateau) {
    this->plateau = plateau;
}