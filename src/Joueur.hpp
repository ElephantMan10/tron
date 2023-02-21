#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <string>
#include "IA.hpp"

using namespace std;

class Joueur {
    private:
        int x;
        int y;
        int score;
        int** plateau;
        IA *ia;
        int id;
    public:
        Joueur(int x, int y, int** plateau, int id, IA *ia);
        int getX();
        int getY();
        int getScore();
        int** getPlateau();
        IA* getIA();
        int getId();
        void setX(int x);
        void setY(int y);
        void setScore(int score);
        void setPlateau(int** plateau);
        void setIA(IA *ia);
        void play();
};

#endif