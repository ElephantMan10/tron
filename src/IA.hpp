#ifndef IA_HPP
#define IA_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "MaxN.hpp"
#include "Paranoid.hpp"

using namespace std;

class IA {
    private:
        int x;
        int y;
        int** plateau;
        int score;
        int nAlgo;
        bool vivant;
        int tour;
        void algo(int a);
        void algoRandom();
        void algoMaxN();
        void algoMaxNAB();
        void algoParanoid();
        int idJoueur;
        int taille;
        int profondeur;
        vector<int> joueurs;
        

    public:
        IA(int x, int y, int** plateau, int nAlgo, int idJoueur, int taille, int profondeur, vector<int> joueurs,int tour);
        int getX();
        int getY();
        int getScore();
        int** getPlateau();
        int getIdJoueur();
        int getTaille();
        int getAlgo();
        bool isVivant();
        void setX(int x);
        void setY(int y);
        void setAlgo(int nAlgo);
        void setPlateau(int** plateau);
        void setScore(int score);
        void setVivant(bool vivant);
        void play();
};

#endif