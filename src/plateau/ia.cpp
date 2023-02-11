#include "ia.hpp"

IA::IA(int x, int y, Joueur *joueur, Plateau *plateau) {
    this->x = x;
    this->y = y;
    this->joueur = joueur;
    this->plateau = plateau;
}

void IA::deplacer() {
    int i = rand() % 4;
    switch (i) {
        case 0:
            this->deplacerHaut();
            break;
        case 1:
            this->deplacerBas();
            break;
        case 2:
            this->deplacerGauche();
            break;
        case 3:
            this->deplacerDroite();
            break;
    }
}

void IA::deplacerHaut() {
    if (this->y > 0) {
        this->y--;
    } else {
        this->deplacerBas();
    }
}

void IA::deplacerBas() {
    if (this->y < this->plateau->getTaille() - 1) {
        this->y++;
    } else {
        this->deplacerHaut();
    }
}

void IA::deplacerGauche() {
    if (this->x > 0) {
        this->x--;
    } else {
        this->deplacerDroite();
    }
}

void IA::deplacerDroite() {
    if (this->x < this->plateau->getTaille() - 1) {
        this->x++;
    } else {
        this->deplacerGauche();
    }
}