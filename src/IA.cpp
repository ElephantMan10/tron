#include "IA.hpp"

IA::IA(int x, int y, int** plateau, int nAlgo, int idJoueur, int taille, int profondeur, vector<int> joueurs) {
    this->x = x;
    this->y = y;
    this->plateau = plateau;
    this->idJoueur = idJoueur;
    this->taille = taille;
    this->vivant = true;
    this->nAlgo = nAlgo;
    this->profondeur = profondeur;
    this->joueurs = joueurs;
    srand(time(NULL)); // graine random
}

int IA::getX() {
    return this->x;
}

int IA::getY() {
    return this->y;
}

int IA::getHeuristique() {
    int heuristique = 0;
    
    return heuristique;
}

int** IA::getPlateau() {
    return this->plateau;
}

int IA::getAlgo() {
    return this->nAlgo;
}

void IA::setX(int x) {
    this->x = x;
}

void IA::setY(int y) {
    this->y = y;
}

void IA::setPlateau(int** plateau) {
    this->plateau = plateau;
}

void IA::setAlgo(int nAlgo) {
    this->nAlgo = nAlgo;
}

void IA::setVivant(bool vivant) {
    this->vivant = vivant;
}

void IA::play() {
    this->algo(this->nAlgo);
}

void IA::algo(int a) {
    switch(a) {
        case 0:
            this->algoRandom();
            break;
        case 1:
            this->algoParanoid(this->profondeur);
            break;
        default:
            this->vivant = false;
            cout << "Algo non trouvé pour Joueur " << this->idJoueur << " => mort" << endl;
            break;
    }
}

bool IA::isVivant() {
    return this->vivant;
}

void IA::algoRandom() {
    vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> supprDirection;
    for(int i = 0; i < direction.size(); i++) {
        if(this->x+direction[i][0] < 0 || this->x+direction[i][0] >= this->taille || this->y+direction[i][1] < 0 || this->y+direction[i][1] >= this->taille) {
            supprDirection.push_back(direction[i]);
        } else if(this->plateau[this->x+direction[i][0]][this->y+direction[i][1]] != 0) {
            supprDirection.push_back(direction[i]);
        }
    }
    for(int i = 0; i < supprDirection.size(); i++) {
        for(int j = 0; j < direction.size(); j++) {
            if(supprDirection[i][0] == direction[j][0] && supprDirection[i][1] == direction[j][1]) {
                direction.erase(direction.begin()+j);
            }
        }
    }
    if(direction.empty()) {
        this->vivant = false;
    } else {
        int a = (int)(rand() % direction.size());
        this->x += direction[a][0];
        this->y += direction[a][1];
    }
}

int IA::algoParanoid(int profondeur) {
    if(profondeur == 0) {
        return this->getHeuristique();
    }

    return 0;
}