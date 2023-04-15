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
    for(int p : s->getJvivant()){
      for(int i = 0; i < s->getTaille(); i++){
        for(int j = 0; j < s->getTaille(); j++){
          if(s->getBoard()[i][j] == p){
            x1 = i;
            y1 = j;
          }
        }
      }
      int h = s->getHeuristic();
      s->getNewState(x1,y1,p);
      v.push_back(h);
      // cout << "------ heuri = " << h << "player " << p  << endl;
    }
    return v;
  }
  else{
    this->compteur += 1;
    if(this->joueurActuel == s->getPlayer() ) {
      int bestvalue = -1000000;
      int newID= s->getNextJoueur(id);
      for(State* fils : s->getNewState(x,y,newID)){
        vector<int> coord = fils->getNextJoueurCoord(id);
        vector<int> req = algo(fils,p-1,coord[0],coord[1],newID,s->getJvivant());
        bestvalue = max(v[newID],req[newID]);
        v[newID] = bestvalue;
      }
    }  
    else{
      int player;
      for(int j : s->getJvivant()){
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
      algo(s,p,x1,y1,player,s->getJvivant());
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
      int newID= s->getNextJoueur(id);
      for(State* fils : s->getNewState(x,y,newID)){
        vector<int> coord = fils->getNextJoueurCoord(id);
        vector<int> req = algoAB(fils,p-1,coord[0],coord[1],newID,s->getJvivant(),alpha,beta);
        int val = max(v[newID],req[newID]);
        if(val < bestvalue){
          bestvalue = val;
          if(bestvalue < beta){
            beta = bestvalue;
            if(beta <= alpha){
              v[newID] = bestvalue;
              return v;
            }
          }
        }
        else if (val > bestvalue){
          bestvalue = val;
          if(bestvalue > alpha){
            alpha = bestvalue;
            if(beta < alpha){
              v[newID] = bestvalue;
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

  int bestvalue = INT8_MIN;
  Move* bestmove = NULL;
  for(State* fils : s->getNewState(x,y,id)){
    vector<int> req = algo(fils,p-1,fils->getMove()->getX(),fils->getMove()->getY(),fils->getPlayer(),allJ);
    if(id == fils->getMove()->getId()){
      if(req[fils->getPlayer()-1] > bestvalue || bestmove == NULL || bestvalue == INT8_MIN){
        bestmove = fils->getMove();
        bestvalue = req[fils->getPlayer()-1];
        // cout << "root player :" << fils->getRootPlayer() << endl;
        // cout << "bestvalue : " << bestvalue << endl;
      }
    }
  }
  // if(bestmove != NULL){
    // cout << "////////////////////////////////////" << endl;
    // cout << "bestmove X : " << bestmove->getX() << " Y : " << bestmove->getY() << " id :" << bestmove->getId() << endl;
  // }
  return bestmove;
}

Move* MaxN::getBestMoveAB(State* s, int p, int x,int y,int id, vector<int> allJ, int alpha, int beta) {

  int bestvalue = INT8_MIN;
  Move* bestmove = NULL;
  for(State* fils : s->getNewState(x,y,id)){
    vector<int> req = algoAB(fils,p-1,fils->getMove()->getX(),fils->getMove()->getY(),fils->getPlayer(),allJ,alpha,beta);
    if(id == fils->getMove()->getId()){
      if(req[fils->getPlayer()-1] > bestvalue || bestmove == NULL || bestvalue == INT8_MIN){
        bestmove = fils->getMove();
      }
    }
  }
  return bestmove;
}