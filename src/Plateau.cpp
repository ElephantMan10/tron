#include "Plateau.hpp"

Plateau::Plateau(int taille, int nbJoueurs) {
    srand(getpid());
    this->taille = taille;
    this->nbJoueursVivant = nbJoueurs;
    this->plateau = new int*[taille];
    for (int i = 0; i < taille; i++) {
        this->plateau[i] = new int[taille];
        for (int j = 0; j < taille; j++) {
            this->plateau[i][j] = 0;
        }
    }
    this->joueursInt = vector<int>();
    for (int i = 0; i < nbJoueurs; i++) {
        this->joueursInt.push_back(i+1);
    }
    for (int i = 1; i <= nbJoueurs; i++) {
        int x = rand()%taille, y = rand()%taille;
        while(this->plateau[x][y] != 0) {
            x = rand()%taille;
            y = rand()%taille;
        }
        this->joueurs.push_back(new Joueur(x, y, this->plateau, i, new IA(x, y, this->plateau, 0, i, this->taille, 0, this->joueursInt,0)));
        cout << "Algo joueur " << i << " : " << this->joueurs[i-1]->getIA()->getAlgo() << endl;
        this->plateau[x][y] = i;
    }
    this->joueurVivant = this->joueurs;
}

Plateau::Plateau(int taille, int nbJoueurs, int* algos) {
    srand(getpid());
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
    this->joueursInt = vector<int>();
    for (int i = 0; i < nbJoueurs; i++) {
        this->joueursInt.push_back(i+1);
    }
    for (int i = 0; i < nbJoueurs*2; i+=2) {
        // int x = (rand()%(taille/nbJoueurs))+i*(taille/nbJoueurs), y = (rand()%(taille/nbJoueurs))+i*(taille/nbJoueurs);
        int x = rand()%taille, y = rand()%taille;
        while(this->plateau[x][y] != 0) {
            // x = (rand()%(taille/nbJoueurs))+i*(taille/nbJoueurs);
            // y = (rand()%(taille/nbJoueurs))+i*(taille/nbJoueurs);
            x = rand()%taille;
            y = rand()%taille;
        }
        cout << "Algo joueur " << i/2+1 << " : " << algos[i] << ", profondeur : " << algos[i+1] << endl;
        this->joueurs.push_back(new Joueur(x, y, this->plateau, i/2+1, new IA(x, y, this->plateau, algos[i], i/2+1, this->taille, algos[i+1], this->joueursInt,0)));
        this->plateau[x][y] = i/2+1;
    }
    this->joueurVivant = this->joueurs;
}

Plateau::Plateau(int taille, int nbEquipes, int* nbJoueurs, int* algos, int* profondeur) {
    srand(getpid());
    this->taille = taille;
    this->nbEquipesVivantes = nbEquipes;
    this->nbJoueursVivant = 0;
    this->plateau = new int*[taille];
    for (int i = 0; i < taille; i++) {
        this->plateau[i] = new int[taille];
        for (int j = 0; j < taille; j++) {
            this->plateau[i][j] = 0;
        }
    }
    // cout << "création des equipes : nb = " << nbEquipes << endl;
    this->equipesInt = vector<int>();
    for (int i = 0; i < nbEquipes; i++) {
        this->equipesInt.push_back(i+1);
    }
    // cout << "création des joueurs" << endl;
    this->joueursInt = vector<int>();
    for (int i = 0; i < nbEquipes; i++) {
        for (int j = 0; j < nbJoueurs[i]; j++) {
            this->joueursInt.push_back(i+1);
            nbJoueursVivant++;
        }
    }
    // cout << "nbJoueursVivant : " << nbJoueursVivant << endl;
    this->equipes = vector<Equipe*>();
    this->equipes.push_back(new Equipe(1, nbJoueurs[0], this->plateau, algos[0], this->taille, profondeur[0], 1));
    for(int i = 1; i < nbEquipes; i++) {
        this->equipes.push_back(new Equipe(i+1, nbJoueurs[i], this->plateau, algos[i], this->taille, profondeur[i], nbJoueurs[i]+1));
    }
    // cout << "placement des joueurs" << endl;
    for(int i = 0; i < nbEquipes; i++) {
        // cout << "equipe " << i << " : " << nbJoueurs[i] << endl;
        for (int j = 0; j < nbJoueurs[i]; j++) {
            int x = this->equipes[i]->getJoueurs()[j]->getX(), y = this->equipes[i]->getJoueurs()[j]->getY();
            // cout << "Algo joueur " << j << " : " << this->equipes[i]->getJoueurs()[j]->getIA()->getAlgo() << endl;
            this->joueurs.push_back(this->equipes[i]->getJoueurs()[j]);
            this->plateau[x][y] = this->equipes[i]->getJoueurs()[j]->getId();
        }
        // cout << "fin equipe " << i << endl;
    }
    for(int i = 0; i < nbEquipes; i++) {
        this->equipes[i]->setPlateau(this->plateau);
    }
    this->joueurVivant = this->joueurs;
    this->equipesVivantes = this->equipes;
}

int Plateau::getTaille() {
    return this->taille;
}

int** Plateau::getPlateau() {
    return this->plateau;
}

vector<Joueur*> Plateau::getJoueur() {
    return this->joueurs;
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
    this->joueurs = joueur;
}

void Plateau::setJoueurVivant(vector<Joueur*> joueurVivant) {
    this->joueurVivant = joueurVivant;
}

void Plateau::ajouterJoueur(Joueur *joueur) {
    this->joueurs.push_back(joueur);
}

void Plateau::joueurMort(Joueur *joueur) {
    for (size_t i = 0; i < this->joueurVivant.size(); i++) {
        if (this->joueurVivant[i] == joueur) {
            this->joueurVivant.erase(this->joueurVivant.begin() + i);
            this->nbJoueursVivant--;
            break;
        }
    }
}

void Plateau::equipeMorte(Equipe *equipe) {
    for (size_t i = 0; i < this->equipesVivantes.size(); i++) {
        if (this->equipesVivantes[i] == equipe) {
            equipe->setVivant(false);
            this->equipesVivantes.erase(this->equipesVivantes.begin() + i);
            this->nbEquipesVivantes--;
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
    for(Joueur* j : this->joueurs) {
        cout << "Joueur " << j->getId() << " : " << (j->isVivant()?"vivant":"mort") << endl;
    }
}

void Plateau::playEquipe() {
    vector<Equipe*> equipeMort;
    for (Equipe* e : this->equipesVivantes) {
        e->play();
        if (!e->isVivant()) {
            equipeMort.push_back(e);
        } else {
            this->plateau = e->getPlateau();
        }
        this->setPlateauEquipes();
    }
    for (Equipe* e : equipeMort) {
        this->equipeMorte(e);
        cout << "Equipe " << e->getId() << " est morte" << endl;
    }
    for(Equipe* e : this->equipes) {
        cout << "Equipe " << e->getId() << " : " << (e->isVivant()?"vivant":"mort") << endl;
    }
}

bool Plateau::isOver() {
    if(this->nbJoueursVivant <= 1) {
        //cout << "Fin de la partie" << endl;
        this->winner = new int[this->joueurVivant.size()];
        for (size_t i = 0; i < this->joueurVivant.size(); i++) {
            this->winner[i] = this->joueurVivant[i]->getId();
            //cout << "Joueur " << this->joueurVivant[i]->getId() << " a gagné" << endl;
        }
        return true;
    }
    return false;
}


// bool Plateau::isOver() {
//     if(this->nbEquipesVivantes <= 1) {
//         cout << "Fin de la partie" << endl;
//         this->winner = new int[this->equipesVivantes.size()];
//         for (size_t i = 0; i < this->equipesVivantes.size(); i++) {
//             this->winner[i] = this->equipesVivantes[i]->getId();
//             cout << "Équipe " << this->equipesVivantes[i]->getId() << " a gagné" << endl;
//         }
//         return true;
//     }
//     return false;
// }

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
    for (Joueur* j : this->joueurs) {
        j->setPlateau(this->plateau);
    }
}

void Plateau::setPlateauEquipes() {
    for (Equipe* e : this->equipes) {
        e->setPlateau(this->plateau);
    }
}

Plateau::~Plateau() { 
    for (int i = 0; i < this->taille; i++) {
        delete[] this->plateau[i];
    }
    delete[] this->plateau;
    for (Joueur* j : this->joueurs) {
        delete j;
    }
    this->joueurs.clear();
    this->joueurVivant.clear();
}