#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Equipe.hpp"
#include "Joueur.hpp"

using namespace std;
/**
 * La classe qui définie le plateau de jeu et les fonctions permettant d'interagir avec.
 * @author Mathis Roptin, Alexander Camatchy, Victoire Dane Moukoko Ndongo, Felix Senechal, Université de Caen Normandie
 */
class Plateau {
    private:
        int taille;
        int** plateau;
        vector<Joueur*> joueur;
        vector<Joueur*> joueurVivant;
        int nbJoueursVivant;
        int* winner;
        vector<int> joueurs;
    public:
        /**
        * constructeur du plateau
        * @param taille est un int, 
        * @param nbJoueur est un int
        * @requires taille est de type int, nbJoueur est de type int
        * @ensures taille>0, nbJoueur>0
        */
        Plateau(int taille, int nbJoueur);
        /**
        * constructeur du plateau
        * @param taille est un int
        * @param nbJoueur est un int
        * @param algos est un int
        * @requires taille est de type int, nbJoueur est de type int
        * @ensures taille>0, nbJoueur>0
        */
        Plateau(int taille, int nbJoueur, int* algos);
        Plateau(int taille, int nbJoueur, int* nbJoueurs, int* algos);
        ~Plateau();
        int getTaille();
        int** getPlateau();
        vector<Joueur*> getJoueur();
        vector<Joueur*> getJoueurVivant();
        int getNbJoueursVivant();
        int* getWinner();
        vector<int> getJoueurs();
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
        void end();
};

#endif
