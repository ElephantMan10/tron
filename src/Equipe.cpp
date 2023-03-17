#include "Equipe.hpp"

Equipe::Equipe(int id, vector<Joueur*> joueurs, int** plateau, int idAlgo, int taille) {
    this->id = id;
    this->joueurs = joueurs;
    this->nbJoueurs = joueurs.size();
    this->nbJoueursVivants = joueurs.size();
    this->plateau = plateau;
}

Equipe::Equipe(int id, int nbJoueurs, int** plateau, int idAlgo, int taille) {
    this->id = id;
    this->nbJoueurs = nbJoueurs;
    this->nbJoueursVivants = nbJoueurs;
    this->joueurs = vector<Joueur*>();
    this->plateau = plateau;
    for (size_t i = 0; i < nbJoueurs; i++) {
        int x = rand()%taille, y = rand()%taille;
        while(this->plateau[x][y] != 0) {
            x = rand()%taille;
            y = rand()%taille;
        }


    }
}

int Equipe::getId() {
    return this->id;
}

vector<Joueur*> Equipe::getJoueurs() {
    return this->joueurs;
}

int** Equipe::getPlateau() {
    return this->plateau;
}

void Equipe::setId(int id) {
    this->id = id;
}

void Equipe::setJoueurs(vector<Joueur*> joueurs) {
    this->joueurs = joueurs;
}

void Equipe::addJoueur(Joueur* joueur) {
    this->joueurs.push_back(joueur);
}

void Equipe::removeJoueur(Joueur* joueur) {
    for (int i = 0; i < this->joueurs.size(); i++) {
        if (this->joueurs[i] == joueur) {
            joueur->setVivant(false);
            this->joueurs.erase(this->joueurs.begin() + i);
            break;
        }
    }
}

bool Equipe::operator==(const Equipe &equipe) {
    return this->id == equipe.id;
}

bool Equipe::contains(Joueur* joueur) {
    for (Joueur* j : this->joueurs) {
        if (j == joueur) {
            return true;
        }
    }
    return false;
}

void Equipe::joueurMort(Joueur* joueur) {
    this->removeJoueur(joueur);
}

void Equipe::play() {
    for (Joueur* joueur : this->joueurs) {
        if(joueur->isVivant())
        joueur->play();
    }
}