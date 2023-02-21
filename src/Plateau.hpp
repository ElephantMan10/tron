#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Entity.hpp"
#include "Joueur.hpp"

using namespace std;

class Plateau {
    private:
        int taille;
        int** plateau;
        vector<Entity*> entity;
        vector<Joueur*> joueur;
        int nbJoueursVivant;
    public:
        Plateau(int taille, int nbJoueur);
        int getTaille();
        int** getPlateau();
        vector<Joueur*> getJoueur();
        void setTaille(int taille);
        void setPlateau(int** plateau);
        void setJoueur(vector<Joueur*> joueur);
        void ajouterJoueur(Joueur *joueur);
        void supprimerJoueur(Joueur *joueur);
        void afficher();
};

#endif
