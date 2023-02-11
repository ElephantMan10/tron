#ifndef MUR_HPP
#define MUR_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "joueur.hpp"
#include "plateau.hpp"

using namespace std;

class Mur : public Joueur{
    private :
        int x,y;
        Plateau *plateau;
    public :
        Mur(int x, int y, Plateau *plateau) : Joueur(x,y,plateau,false, NULL) {};
};

#endif