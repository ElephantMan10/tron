#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <string>
#include "Entity.hpp"
#include "IA.hpp"

using namespace std;

class Joueur : public Entity {
    private:
        int x;
        int y;
        int score;
        int** plateau;
        IA *ia;
    public:
        Joueur(int x, int y, int** plateau, int id, IA *ia);
        int getX();
        int getY();
        int getScore();
        int** getPlateau();
        IA* getIA();
        void setX(int x);
        void setY(int y);
        void setScore(int score);
        void setPlateau(int** plateau);
        void setIA(IA *ia);
};

#endif