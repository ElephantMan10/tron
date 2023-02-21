#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Joueur.hpp"

using namespace std;

class Plateau {
    private:
        int taille;
        int** plateau;
        vector<Joueur*> joueur;
        vector<Joueur*> joueurVivant;
        int nbJoueursVivant;
    public:
        Plateau(int taille, int nbJoueur);
        int getTaille();
        int** getPlateau();
        vector<Joueur*> getJoueur();
        vector<Joueur*> getJoueurVivant();
        int getNbJoueursVivant();
        void setTaille(int taille);
        void setPlateau(int** plateau);
        void setJoueur(vector<Joueur*> joueur);
        void setJoueurVivant(vector<Joueur*> joueurVivant);
        void setNbJoueursVivant(int nbJoueursVivant);
        void ajouterJoueur(Joueur *joueur);
        void joueurMort(Joueur *joueur);
        void afficher();
        void play();
        bool isOver();
};

#endif
