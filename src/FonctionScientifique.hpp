#ifndef FONCTIONSCIENTIFIQUE_HPP
#define FONCTIONSCIENTIFIQUE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Joueur.hpp"
#include "Plateau.hpp"
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stdexcept>

using namespace std;
/**
 * La classe qui définie le plateau de jeu et les fonctions permettant d'interagir avec.
 * @author Mathis Roptin, Alexander Camatchy, Victoire Dane Moukoko Ndongo, Felix Senechal, Université de Caen Normandie
 */
 class FonctionScientifique{
    private :
        int nbtest;
        int nbJoueur;
        int algo;
        int* repartitionEquipe;
    public :
        FonctionScientifique(int nbtest, int nbJoueur, int algo, int* repartitionEquipe);
        int** tabVictoire(int profMax, int taille);
        void graph(int** tabVictoire);
        int VictoireTaille(int profMax, int tailleMax);
        int PointCroisement(int j, int** tab);
        int* getProfondeurDifficille(int j, int*** tab);
        int* getProfondeurFacille(int j, int*** tab);
        int MoyenneProfondeur(int j, int*** tab);
        void showGraph(int** tabVictoire);
 };

#endif