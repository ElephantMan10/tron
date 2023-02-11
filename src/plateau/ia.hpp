#ifndef IA_HPP
#define IA_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "joueur.hpp"
#include "plateau.hpp"

using namespace std;

class IA {
    private :
        Joueur *joueur;
        Plateau *plateau;
        int x,y;
    public :
        IA(int x, int y, Joueur *joueur, Plateau *plateau);
        void deplacer();
        void deplacerHaut();
        void deplacerBas();
        void deplacerGauche();
        void deplacerDroite();
};

#endif