#include "IA.hpp"

IA::IA(int x, int y, int** plateau, int nAlgo, int idJoueur, int taille, int profondeur, vector<int> joueurs, int tour) {
    this->x = x;
    this->y = y;
    this->plateau = plateau;
    this->score = 0;
    this->idJoueur = idJoueur;
    this->taille = taille;
    this->vivant = true;
    this->nAlgo = nAlgo;
    this->profondeur = profondeur;
    this->joueurs = joueurs;
    this->tour = tour;
    srand(time(NULL)); // graine random
}

int IA::getX() {
    return this->x;
}

int IA::getY() {
    return this->y;
}

int IA::getScore() {
    return this->score;
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

void IA::setScore(int score) {
    this->score = score;
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
            this->algoMaxN();
            break;
        case 2:
            this->algoMaxNAB();
            break;
        case 3:
            this->algoParanoid();
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
    for(size_t i = 0; i < direction.size(); i++) {
        if(this->x+direction[i][0] < 0 || this->x+direction[i][0] >= this->taille || this->y+direction[i][1] < 0 || this->y+direction[i][1] >= this->taille) {
            supprDirection.push_back(direction[i]);
        } else if(this->plateau[this->x+direction[i][0]][this->y+direction[i][1]] != 0) {
            supprDirection.push_back(direction[i]);
        }
    }
    for(size_t i = 0; i < supprDirection.size(); i++) {
        for(size_t j = 0; j < direction.size(); j++) {
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

void IA::algoMaxN() {
    // TODO
    State* p = NULL;
    Move* start = new Move(this->x,this->y,this->idJoueur);
    State* s = new State(this->plateau,this->taille,this->joueurs,start,p,this->idJoueur,this->idJoueur,this->tour);
    MaxN alg = MaxN(this->idJoueur,this->profondeur,this->joueurs);
    Move* m = alg.getBestMove(s,this->profondeur,this->x,this->y,this->idJoueur,this->joueurs);
    if(m == NULL) {
        this->vivant = false;
    } else {
        this->x = m->getX();
        this->y = m->getY();
    }
}

void IA::algoMaxNAB() {
    // TODO
    State* p = NULL;
    Move* start = new Move(this->x,this->y,this->idJoueur);
    State* s = new State(this->plateau,this->taille,this->joueurs,start,p,this->idJoueur,this->idJoueur,this->tour);
    MaxN alg = MaxN(this->idJoueur,this->profondeur,this->joueurs);
    Move* m = alg.getBestMove(s,this->profondeur,this->x,this->y,this->idJoueur,this->joueurs);
    if(m == NULL) {
        this->vivant = false;
    } else {
        this->x = m->getX();
        this->y = m->getY();
    }
}

void IA::algoParanoid() {
    // TODO
    State* p = NULL;
    Move* start = new Move(this->x,this->y,this->idJoueur);
    State* s = new State(this->plateau,this->taille,this->joueurs,start,p,this->idJoueur,this->idJoueur,this->tour);
    Paranoid alg = Paranoid(this->idJoueur,this->profondeur);
    Move* m = alg.getBestMove(s,this->profondeur,this->x,this->y,this->idJoueur);
    if(m == NULL) {
        this->vivant = false;
    } else {
        this->x = m->getX();
        this->y = m->getY();
    }
}