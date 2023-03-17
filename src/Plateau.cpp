#include "Plateau.hpp"
/**
 * La classe qui définie le plateau de jeu et les fonctions permettant d'interagir avec.
 * @author Mathis Roptin, Alexander Camatchy, Victoire Dane Moukoko Ndongo, Felix Senechal, Université de Caen Normandie
 */
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
    this->joueurs = vector<int>();
    for (int i = 0; i < nbJoueurs; i++) {
        this->joueurs.push_back(i+1);
    }
    for (int i = 1; i <= nbJoueurs; i++) {
        int x = rand()%taille, y = rand()%taille;
        while(this->plateau[x][y] != 0) {
            x = rand()%taille;
            y = rand()%taille;
        }
        this->joueur.push_back(new Joueur(x, y, this->plateau, i, new IA(x, y, this->plateau, 0, i, this->taille, 0, this->joueurs,0)));
        cout << "Algo joueur " << i << " : " << this->joueur[i-1]->getIA()->getAlgo() << endl;
        this->plateau[x][y] = i;
    }
    this->joueurVivant = this->joueur;
}

Plateau::Plateau(int taille, int nbJoueurs, int* algos) {
    this->taille = taille;
    this->nbJoueursVivant = nbJoueurs;
    this->plateau = new int*[taille];
    for (int i = 0; i < taille; i++) {
        this->plateau[i] = new int[taille];
        for (int j = 0; j < taille; j++) {
            this->plateau[i][j] = 0;
        }
    }
    cout << "nbJoueurs : " << nbJoueurs << endl;
    this->joueurs = vector<int>();
    for (int i = 0; i < nbJoueurs; i++) {
        this->joueurs.push_back(i+1);
    }
    for (int i = 0; i < nbJoueurs*2; i+=2) {
        int x = rand()%taille, y = rand()%taille;
        while(this->plateau[x][y] != 0) {
            x = rand()%taille;
            y = rand()%taille;
        }
        cout << "Algo joueur " << i/2+1 << " : " << algos[i] << ", profondeur : " << algos[i+1] << endl;
        this->joueur.push_back(new Joueur(x, y, this->plateau, i/2+1, new IA(x, y, this->plateau, algos[i], i/2+1, this->taille, algos[i+1], this->joueurs,0)));
        this->plateau[x][y] = i/2+1;
    }
    this->joueurVivant = this->joueur;
}

Plateau::Plateau(int taille, int nbEquipes, int*nbJoueurs, int* algos){
    this->taille = taille;
    this->nbJoueursVivant = 0;
    for(int i = 0; i < nbEquipes; i++){
        this->nbJoueursVivant += nbJoueurs[i];
    }
    this->plateau = new int*[taille];
    for (int i = 0; i < taille; i++) {
        this->plateau[i] = new int[taille];
        for (int j = 0; j < taille; j++) {
            this->plateau[i][j] = 0;
        }
    }
    this->joueurs = vector<int>();
    for (int i = 0; i < nbEquipes; i++) {
        for(int j = 0; j < nbJoueurs[i]; j++){
            this->joueurs.push_back((i+1)*(j+1));
        }
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
    for (int i = 0; i < this->joueurVivant.size(); i++) {
        if (this->joueurVivant[i] == joueur) {
            this->joueurVivant.erase(this->joueurVivant.begin() + i);
            this->nbJoueursVivant--;
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
    // if(this->isOver()) {
    //     return;
    // }
    vector<Joueur*> joueurMort;
    for (Joueur* j : this->joueurVivant) {
        this->plateau[j->getX()][j->getY()] = -1;
        j->play();
        if (!j->isVivant()) {
            this->joueurMort(j);
        } else {
            this->plateau[j->getX()][j->getY()] = j->getId();
        }
        this->setPlateauJoueurs();
    }
    for (Joueur* j : joueurMort) {
        this->joueurMort(j);
    }
    for(Joueur* j : this->joueur) {
        cout << "Joueur " << j->getId() << " : " << (j->isVivant()?"vivant":"mort") << endl;
    }
}

bool Plateau::isOver() {
    if(this->nbJoueursVivant <= 1) {
        cout << "Fin de la partie" << endl;
        this->winner = new int[this->joueurVivant.size()];
        for (int i = 0; i < this->joueurVivant.size(); i++) {
            this->winner[i] = this->joueurVivant[i]->getId();
            cout << "Joueur " << this->joueurVivant[i]->getId() << " a gagné" << endl;
        }
        return true;
    }
    return false;
}

int Plateau::getNbJoueursVivant() {
    return this->nbJoueursVivant;
}

void Plateau::setNbJoueursVivant(int nbJoueursVivant) {
    this->nbJoueursVivant = nbJoueursVivant;
}

int* Plateau::getWinner() {
    return this->winner;
}

void Plateau::setPlateauJoueurs() {
    for (Joueur* j : this->joueur) {
        j->setPlateau(this->plateau);
    }
}

Plateau::~Plateau() { 
    for (int i = 0; i < this->taille; i++) {
        delete[] this->plateau[i];
    }
    delete[] this->plateau;
    for (Joueur* j : this->joueur) {
        delete j;
    }
    this->joueur.clear();
    this->joueurVivant.clear();
}