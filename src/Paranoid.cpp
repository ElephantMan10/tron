#include "Paranoid.hpp"

Paranoid::Paranoid(int j, int p){ 
    this->joueur = j;
    this->profondeur = p;
    this->compteur = 0;
}

int Paranoid::getJoueur(){
    return this->joueur;
}

int Paranoid::getProfondeur(){
    return this->profondeur;
}

int Paranoid::getCompteur(){
    return this->compteur;
}

int Paranoid::algo(State* s, int p, int x, int y, int id) {
    // TODO le code d'un algo minmax de base
    if(p == 0 || s->isTerminal()){
        s->getNewState(x,y,id);
        return s->getHeuristic();
    } else {
        int b;
        this->compteur++;
        if(this->joueur == s->getPlayer()){
            b = INT8_MIN;
            for(State* fils : s->getNewState(x,y,id)){
                int bestval = algo(fils,p-1,x,y,id);
                if(bestval > b ){
                    b = bestval;
                }
            }
        } else {
            b = INT8_MAX;
             for(State* fils : s->getNewState(x,y,id)){
                int bestval = this->algo(fils, p-1, x, y, id);
                if(bestval < b ){
                    b = bestval;
                }
            }
        }   
        return b;
    }
}

Move* Paranoid::getBestMove(State* s, int p, int x, int y, int id){
    int bestval = INT8_MIN;
    Move* bestmove = NULL;
    for(State* fils :  s->getNewState(x,y,id)){
        int val = this->algo(fils,p-1, x, y, id);
        if(val > bestval || bestmove == NULL){
            bestval = val;
            bestmove = fils->getMove();
        }
    }
    return bestmove;
}