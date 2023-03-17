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


vector<int> MaxN::algo(State* s, int p, int x,int y, int id, vector<int> allJ){
  vector<int> v;
  int x1;
  int y1;
  if(this->profondeur == 0 || s->isTerminal()){
    for(int p : allJ){
      for(int i = 0; i < s->getTaille(); i++){
        for(int j = 0; j < s->getTaille(); j++){
          if(s->getBoard()[i][j] == p){
            x1 = i;
            y1 = j;
          }
        }
      }
      s->getNewState(x1,y1,p);
      v.push_back(s->getHeuristic());
    }
    return v;
  }
  else{
    this->compteur += 1;
    if(this->joueurActuel == s->getPlayer() ) {
      int bestvalue = -1000000;
      for(State* fils : s->getNewState(x,y,id)){
        vector<int> req = algo(fils,p-1,x,y,id,allJ);
        int id = p%s->getJvivant().size();
        bestvalue = max(v[id],req[id]);
        v[id] = bestvalue;
      }
    }  
    else{
      int player;
      for(int j : allJ){
        if(j == s->getPlayer()){
          for(int i = 0; i < s->getTaille(); i++){
            for(int j = 0; j < s->getTaille(); j++){
              if(s->getBoard()[i][j] == j){
                player = j;
                x1 = i;
                y1 = j;
              }
            }
          }
        }
      }
      algo(s,p,x1,y1,player,allJ);
    }
    return v;
  }
}

vector<int> MaxN::algoAB(State* s, int p, int x, int y, int id,vector<int> allJ, int alpha, int beta){
  vector<int> v;
  int x1;
  int y1;
  if(this->profondeur == 0 || s->isTerminal()){
    for(int p : allJ){
      for(int i = 0; i < s->getTaille(); i++){
        for(int j = 0; j < s->getTaille(); j++){
          if(s->getBoard()[i][j] == p){
            x1 = i;
            y1 = j;
          }
        }
      }
      s->getNewState(x,y,id);
      v.push_back(s->getHeuristic());
    }
    return v;
  }
  else{
    this->compteur += 1;
    if(this->joueurActuel == s->getPlayer() ) {
      int bestvalue = -1000000;
      for(State* fils : s->getNewState(x,y,id)){
        vector<int> req = algoAB(fils,p-1,x,y,id,allJ,alpha,beta);
        int id = p%s->getJvivant().size();
        int val = max(v[id],req[id]);
        if(val < bestvalue){
          bestvalue = val;
          if(bestvalue < beta){
            beta = bestvalue;
            if(beta <= alpha){
              v[id] = bestvalue;
              return v;
            }
          }
        }
        else if (val > bestvalue){
          bestvalue = val;
          if(bestvalue > alpha){
            alpha = bestvalue;
            if(beta < alpha){
              v[id] = bestvalue;
              return v;
            }
          }
        }
      }
    }  
    else{
      int player;
      for(int j : allJ){
        if(j == s->getPlayer()){
          for(int i = 0; i < s->getTaille(); i++){
            for(int j = 0; j < s->getTaille(); j++){
              if(s->getBoard()[i][j] == j){
                player=j;
                x1 = i;
                y1 = j;
              }
            }
          }
        }
      }
      algoAB(s,p,x1,y1,player,allJ,alpha,beta);
    }
    return v;
  }
}

Move* MaxN::getBestMove(State* s, int p, int x, int y, int id, vector<int> allJ) {
  vector<int> v = algo(s,p,x,y,id,allJ);
  int id = p%s->getJvivant().size();
  int bestvalue = v[id];
  Move* bestmove = NULL;
  for(State* fils : s->getNewState(x,y,id)){
    vector<int> req = algo(fils,p-1,x,y,id,allJ);
    if(req[id] > bestvalue || bestmove == NULL){
      bestmove = fils->getMove();
    }
  }
  return bestmove;
}

Move* MaxN::getBestMoveAB(State* s, int p, int x,int y,int id, vector<int> allJ, int alpha, int beta) {
  vector<int> v = algoAB(s,p,x,y,id,allJ,alpha,beta);
  int id = p%s->getJvivant().size();
  int bestvalue = v[id];
  Move* bestmove = NULL;
  for(State* fils : s->getNewState(x,y,id)){
    vector<int> req = algoAB(fils,p-1,x,y,id,allJ,alpha,beta);
    if(req[id] > bestvalue || bestmove == NULL){
      bestmove = fils->getMove();
    }
  }
  return bestmove;
}