#ifndef FONCTIONSCIENTIFIQUE_HPP
#define FONCTIONSCIENTIFIQUE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Joueur.hpp"
#include "Plateau.hpp"
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>


using namespace std;

/**
 * La classe qui définie le plateau de jeu et les fonctions permettant d'interagir avec.
 * @author Mathis Roptin, Alexander Camatchy, Victoire Dane Moukoko Ndongo, Felix Senechal, Université de Caen Normandie
 */
 class FonctionScientifique{
    private :
        int nbtest;
        int nbJoueur;
        int nbEquipe;
        int* algo;
        int* repartitionEquipe;
    public :
        FonctionScientifique(int nbtest, int nbJoueur, int nbEquipe, int* algo, int* repartitionEquipe);
        int** tabVictoire(int profMin, int profMax, int taille);
        int** tabVictoireNbJoueur(int JoueurMax, int taille);
        void graph(int** tabVictoire);
        int VictoireTaille(int profMax, int tailleMin, int tailleMax);
        int PointCroisement(int j, int** tab, int size);
        int* getProfondeurDifficille(int j, int*** tab, int nbIteration, int size);
        int* getProfondeurFacille(int j, int*** tab, int nbIteration, int size);
        int MoyenneProfondeur(int j, int*** tab, int nbIteration, int size);
        void showGraph(int taille, string pathfile);
        void showGraphBis(int taille, string pathfile);
        string tabToCSV(int** tab, int nbJoueur, int min, int taille);
 };

#endif