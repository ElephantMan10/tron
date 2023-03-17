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

IA* Joueur::getIA() {
    return this->ia;
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

void Joueur::setId(int id) {
    this->id = id;
}

void Joueur::setVivant(bool vivant) {
    this->ia->setVivant(vivant);
}

void Joueur::play() {
    this->ia->play();
    this->x = this->ia->getX();
    this->y = this->ia->getY();
    this->score = this->ia->getScore();
}

void Joueur::remove() {
    delete this->ia;
}

bool Joueur::isVivant() {
    return this->ia->isVivant();
}

bool Joueur::operator==(const Joueur &joueur) {
    return this->id == joueur.id;
}