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
        this->joueurVivant.push_back(this->joueur[i]);
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

vector<Joueur*> Plateau::getJoueurVivant() {
    return this->joueurVivant;
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

void Plateau::setJoueurVivant(vector<Joueur*> joueurVivant) {
    this->joueurVivant = joueurVivant;
}

void Plateau::ajouterJoueur(Joueur *joueur) {
    this->joueur.push_back(joueur);
}

void Plateau::joueurMort(Joueur *joueur) {
    for (int i = 0; i < this->joueur.size(); i++) {
        if (this->joueurVivant[i] == joueur) {
            Joueur *j = this->joueurVivant[i];
            this->joueurVivant.erase(this->joueurVivant.begin() + i);
            j->remove();
            break;
        }
    }
}

void Plateau::afficher() {
    for (int i = 0; i < this->taille; i++) {
        for (int j = 0; j < this->taille; j++) {
            cout << "[";
            if (this->plateau[i][j] == 0) {
                cout << " ";
            } else if (this->plateau[i][j] == -1) {
                cout << "#";
            } else {
                cout << this->plateau[i][j];
            }
            cout << "]";
        }
        cout << endl;
    }
}

void Plateau::play() {
    if(this->isOver()) {
        return;
    }
    for (int i = 0; i < this->joueur.size(); i++) {
        this->plateau[this->joueur[i]->getX()][this->joueur[i]->getY()] = -1;
        this->joueur[i]->play();
        if (this->joueur[i]->getScore() == -1) {
            this->joueurMort(this->joueur[i]);
            this->nbJoueursVivant--;
        } else {
            this->plateau[this->joueur[i]->getX()][this->joueur[i]->getY()] = this->joueur[i]->getId();
        }
    }
}

bool Plateau::isOver() {
    return this->nbJoueursVivant <= 1;
}

int Plateau::getNbJoueursVivant() {
    return this->nbJoueursVivant;
}

void Plateau::setNbJoueursVivant(int nbJoueursVivant) {
    this->nbJoueursVivant = nbJoueursVivant;
}

void Plateau::end() {
    for (int i = 0; i < this->taille; i++) {
        delete[] this->plateau[i];
    }
    delete[] this->plateau;
    for (int i = 0; i < this->joueur.size(); i++) {
        delete this->joueur[i];
    }
}