#include "Plateau.hpp"

Plateau::Plateau(int taille, int nbJoueurs) {
    this->taille = taille;
    this->nbJoueursVivant = nbJoueurs;
    this->plateau = new int*[taille];
    for (int i = 0; i < taille; i++) {
        this->plateau[i] = new int[taille];
        for (int j = 0; j < taille; j++) {
            this->plateau[i][j] = 0;
        }
    }
    for (int i = 0; i < nbJoueurs; i++) {
        this->joueur.push_back(new Joueur((i*5)%taille, (i*3)%taille, this->plateau, i+1, new IA((i*5)%taille, (i*3)%taille, this->plateau, 0)));
        this->plateau[(i*5)%taille][(i*3)%taille] = i+1;
    }
}

int Plateau::getTaille() {
    return this->taille;
}

int** Plateau::getPlateau() {
    return this->plateau;
}

vector<Joueur*> Plateau::getJoueur() {
    return this->joueur;
}

void Plateau::setTaille(int taille) {
    this->taille = taille;
}

void Plateau::setPlateau(int** plateau) {
    this->plateau = plateau;
}

void Plateau::setJoueur(vector<Joueur*> joueur) {
    this->joueur = joueur;
}

void Plateau::ajouterJoueur(Joueur *joueur) {
    this->joueur.push_back(joueur);
}

void Plateau::supprimerJoueur(Joueur *joueur) {
    for (int i = 0; i < this->joueur.size(); i++) {
        if (this->joueur[i] == joueur) {
            this->joueur.erase(this->joueur.begin() + i);
        }
    }
}

void Plateau::afficher() {
    for (int i = 0; i < this->taille; i++) {
        for (int j = 0; j < this->taille; j++) {
            cout << "[";
            if (this->plateau[i][j] == 0) {
                cout << " ";
            } else {
                cout << this->plateau[i][j];
            }
            cout << "]";
        }
        cout << endl;
    }
}
