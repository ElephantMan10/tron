#ifndef MAXN_HPP
#define MAXN_HPP
#include "State.hpp"
#include "Move.hpp"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class MaxN {
  private :
    int joueurActuel;
    int profondeur;
    vector<int> joueurs;
    int compteur;

  public:
    MaxN(int ja, int p, vector<int> j);
    int getJoueurActuel();
    vector<int> getJoueur();
    int getProfondeur();
    vector<int> algo(State* s, int p, int x, int y, int id,vector<int> allJ);
    vector<int> algoAB(State* s, int p, int x, int y, int id,vector<int> allJ, int alpha, int beta);
    Move* getBestMove(State* s, int p, int x, int y, int id,vector<int> allJ);
    Move* getBestMoveAB(State* s, int p, int x, int y, int id,vector<int> allJ, int alpha, int beta);
};
#endif