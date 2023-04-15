#include "Equipe.hpp"

Equipe::Equipe(int id, vector<Joueur*> joueurs, int** plateau, int idAlgo, int taille) {
    this->id = id;
    this->joueurs = joueurs;
    this->nbJoueurs = joueurs.size();
    this->nbJoueursVivants = joueurs.size();
    this->plateau = plateau;
}

Equipe::Equipe(int id, int nbJoueurs, int** plateau, int idAlgo, int taille, int profondeur, int idStart) {
    this->id = id;
    this->nbJoueurs = nbJoueurs;
    this->nbJoueursVivants = nbJoueurs;
    this->joueurs = vector<Joueur*>();
    this->plateau = plateau;
    this->joueursInt = vector<int>();
    for(int i = 0; i < nbJoueurs; i++) {
        this->joueursInt.push_back(idStart+i);
    }
    for (int i = 0; i < nbJoueurs; i++) {
        int x = rand()%taille, y = rand()%taille;
        while(this->plateau[x][y] != 0) {
            x = rand()%taille;
            y = rand()%taille;
        }
        this->joueurs.push_back(new Joueur(x, y, this->plateau, idStart+i, new IA(x, y, this->plateau, idAlgo, idStart+i, taille, profondeur, this->joueursInt,0)));
        this->plateau[x][y] = id;
    }
    this->joueursVivants = this->joueurs;
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

void Equipe::setPlateau(int** plateau) {
    this->plateau = plateau;
    this->setPlateauJoueurs();
}

void Equipe::setPlateauJoueurs() {
    for(Joueur* joueur : this->joueurs) {
        joueur->setPlateau(this->plateau);
    }
}

void Equipe::addJoueur(Joueur* joueur) {
    this->joueurs.push_back(joueur);
    this->joueursVivants.push_back(joueur);
}

void Equipe::removeJoueur(Joueur* joueur) {
    for (size_t i = 0; i < this->joueursVivants.size(); i++) {
        if (this->joueursVivants[i] == joueur) {
            this->joueursVivants.erase(this->joueurs.begin() + i);
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
    this->nbJoueursVivants--;
}

void Equipe::play() {
    for (Joueur* joueur : this->joueursVivants) {
        this->plateau[joueur->getX()][joueur->getY()] = -1;
        joueur->play();
        if(joueur->isVivant()) {
            this->plateau[joueur->getX()][joueur->getY()] = joueur->getId();
        } else {
            this->joueurMort(joueur);
        }
        this->setPlateauJoueurs();
    }
}

void Equipe::setVivant(bool vivant) {
    this->vivant = vivant;
    for (Joueur* joueur : this->joueurs) {
        joueur->setVivant(vivant);
    }
}

bool Equipe::isVivant() {
    this->vivant = this->nbJoueursVivants > 0;
    return this->vivant;
}