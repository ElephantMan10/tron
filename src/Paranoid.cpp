#include "Paranoid.hpp"

Paranoid::Paranoid(int j, int p){ 
    this->joueur = j;
    this->profondeur = p;
    this->compteur = 0;
}

int Paranoid::algo(State* s, int p, Joueur* j) {
    // TODO le code d'un algo minmax de base
    if(p == 0 || s->isTerminal()){
        s->getNewState(j);
        return s->getHeuristic();
    } else {
        int b;
        this->compteur++;
        if(this->joueur == s->getPlayer()){
            b = INT8_MIN;
            for(State* fils : s->getNewState(j)){
                int bestval = algo(fils,p-1,j);
                if(bestval > b ){
                    b = bestval;
                }
            }
        } else {
            b = INT8_MAX;
             for(State* fils : s->getNewState(j)){
                int bestval = this->algo(fils, p-1, j);
                if(bestval < b ){
                    b = bestval;
                }
            }
        }   
        return b;
    }
}
