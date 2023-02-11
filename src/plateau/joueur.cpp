#include "joueur.hpp"

Joueur::Joueur(int x, int y, Plateau *plateau, bool playable, IA *ia) {
    this->x = x;
    this->y = y;
    this->plateau = plateau;
    this->playable = playable;
    this->ia = ia;
}

int Joueur::getX() {
    return this->x;
}

int Joueur::getY() {
    return this->y;
}

void Joueur::setX(int x) {
    this->x = x;
}

void Joueur::setY(int y) {
    this->y = y;
}

void Joueur::deplacer() {
    this->ia->deplacer();
}