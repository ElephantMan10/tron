#include "plateau.hpp"

Plateau::Plateau(int taille) {
    this->taille = taille;
    this->joueurs.resize(taille);
    for (int i = 0; i < taille; i++) {
        this->joueurs[i].resize(taille);
    }
}

void Plateau::ajouterJoueur(Joueur joueur) {
    this->joueurs[joueur.getX()][joueur.getY()] = &joueur;
}

void Plateau::afficher() {
    for (int i = 0; i < this->taille; i++) {
        for (int j = 0; j < this->taille; j++) {
            if (this->joueurs[i][j] == NULL) {
                cout << " ";
            } else {
                cout << "X";
            }
        }
        cout << endl;
    }
}

int Plateau::getTaille() {
    return this->taille;
}