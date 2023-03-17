#ifndef MAXN_HPP
#define MAXN_HPP
#include "State.hpp"
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
    vector<int> algo(State* s, int p, Joueur* j,vector<Joueur*> allJ);
    vector<int> algoAB(State* s, int p, Joueur* j,vector<Joueur*> allJ, int alpha, int beta);
};
#endif