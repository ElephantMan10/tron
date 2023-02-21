#include "Joueur.hpp"

Joueur::Joueur(int x, int y, int** plateau, int id, IA *ia) {
    this->x = x;
    this->y = y;
    this->plateau = plateau;
    this->ia = ia;
    this->score = 0;
    this->id = id;
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

int Joueur::getId() {
    return this->id;
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

void Joueur::setIA(IA *ia) {
    this->ia = ia;
}

void Joueur::play() {
    this->ia->play();
    this->x = this->ia->getX();
    this->y = this->ia->getY();
    this->score = this->ia->getScore();
}