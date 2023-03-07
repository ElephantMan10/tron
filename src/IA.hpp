#ifndef IA_HPP
#define IA_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <set>

using namespace std;

class IA {
    private:
        int x;
        int y;
        int** plateau;
        int nAlgo;
        bool vivant;
        void algo(int a);
        void algoRandom();
        int algoParanoid(int profondeur);
        int idJoueur;
        int taille;
        int profondeur;
        vector<int> joueurs;
    public:
        IA(int x, int y, int** plateau, int nAlgo, int idJoueur, int taille, int profondeur, vector<int> joueurs);
        int getX();
        int getY();
        int getHeuristique();
        int** getPlateau();
        int getIdJoueur();
        int getTaille();
        int getAlgo();
        bool isVivant();
        void setX(int x);
        void setY(int y);
        void setAlgo(int nAlgo);
        void setPlateau(int** plateau);
        void setVivant(bool vivant);
        void play();
};

#endif
#endif