#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "joueur.hpp"

using namespace std;

class Plateau {
    private :
        int taille;
        vector<vector<Joueur*>> joueurs;
    public :
        Plateau(int taille);
        void afficher();
        void ajouterJoueur(Joueur joueur);
        void deplacerJoueur(Joueur joueur, int x, int y);
        int getTaille();
};

#endif