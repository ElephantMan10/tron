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
        vector<Equipe*> equipes;
        vector<Equipe*> equipesVivantes;
        int nbEquipesVivantes;
        vector<int> equipes;
    public:
        Plateau(int taille, int nbJoueur);
        Plateau(int taille, int nbJoueur, int* algos);
        Plateau(int taille, int nbEquipes, int* nbJoueurs, int* algos);
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
        void setPlateauJoueurs();
        void ajouterJoueur(Joueur *joueur);
        void joueurMort(Joueur *joueur);
        void afficher();
        void play();
        bool isOver();
        void end();
};

#endif
