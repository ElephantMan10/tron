#include "MaxN.hpp"

MaxN::MaxN(int ja, int p,vector<int> j) {
  this->joueurActuel = ja;
  this->profondeur = p;
  this->joueurs = j;
  this->compteur = 0;
};

int MaxN::getJoueurActuel(){
  return this->joueurActuel;
}

int MaxN::getProfondeur(){
  return this->profondeur;
}

vector<int> MaxN::getJoueur(){
  return this->joueurs;
}

vector<int> MaxN::algo(State* s, int p, Joueur* j, vector<Joueur*> allJ){
   vector<int> v;
  if(this->profondeur == 0 || s->isTerminal()){
    for(Joueur* p : allJ){
      s->getNewState(p);
      v.push_back(s->getHeuristic());
    }
    return v;
  }
  else{
    this->compteur += 1;
    if(this->joueurActuel == s->getPlayer() ) {
      int bestvalue = -1000000;
      for(State* fils : s->getNewState(j)){
        vector<int> req = algo(fils,p-1,j,allJ);
        int id = p%s->getJvivant().size();
        bestvalue = max(v[id],req[id]);
        v[id] = bestvalue;
      }
    }  
    else{
      for(Joueur* j : allJ){
        if(j->getId() != s->getPlayer()){
        algo(s,p,j,allJ);
        }
      }
    }
    return v;
  }
}

vector<int> MaxN::algoAB(State* s, int p, Joueur* j,vector<Joueur*> allJ, int alpha, int beta){
  vector<int> v;
  if(this->profondeur == 0 || s->isTerminal()){
    for(Joueur* p : allJ){
      s->getNewState(p);
      v.push_back(s->getHeuristic());
    }
    return v;
  }
  else{
    this->compteur += 1;
    if(this->joueurActuel == s->getPlayer() ) {
      int bestvalue = -1000000;
      for(State* fils : s->getNewState(j)){
        vector<int> req = algoAB(fils,p-1,j,allJ,alpha,beta);
        int id = p%s->getJvivant().size();
        bestvalue = max(v[id],req[id]);
        v[id] = bestvalue;
        alpha = max(alpha,bestvalue);
        if(beta <= alpha){
          break;
        }
      }
    }  
    else{
      for(Joueur* j : allJ){
        if(j->getId() != s->getPlayer()){
        algoAB(s,p,j,allJ,alpha,beta);
        }
      }
    }
    return v;
  }
}