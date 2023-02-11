#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "plateau.hpp"
#include "ia.hpp"

using namespace std;

class Joueur {
    private:
       int x,y;
       Plateau *plateau;
       bool playable;
       IA *ia;
    public:
        Joueur(int x, int y, Plateau *plateau, bool playable, IA *ia);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        void deplacer();
};


#endif