#include <stdio.h>
#include <stdlib.h>

#include "IA.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "IA.hpp"

int main(int argc, char *argv[])
{
    Plateau *plateau; // que des grilles carrées
    if(argc <= 1) plateau = new Plateau(5, 5); // pas d'arguments donc on lance le jeu avec une grille de 5 par 5 et 5 joueurs
    else if(argc == 2) plateau = new Plateau(atoi(argv[1]), 5); // un argument donc on lance le jeu avec une grille de taille argv[1] par argv[1] et 5 joueurs
    else if(argc == 3) plateau = new Plateau(atoi(argv[1]), atoi(argv[2])); // deux arguments donc on lance le jeu avec une grille de taille argv[1] par argv[1] et argv[2] joueurs, ia aleatoires
    else { // plus de deux arguments donc on lance le jeu avec une grille de taille argv[1] par argv[1], les autres arguments seront les algos avec leur profondeur et autants joueurs qu'il y a d'algos dans les arguments en leur donnant l'algo en question
        int nbJoueurs = argc - 2;
        if(nbJoueurs%2 != 0) {
            cout << "Erreur : nombre d'arguments incorrect" << endl << "Usage : ./tron [taille] [algo joueur 1] [profondeur1] [algo joueur2] [profondeur2] ..." << endl;
            return 0;
        }
        int algos[nbJoueurs];
        for(int i = 0; i < nbJoueurs; i++) {
            algos[i] = atoi(argv[i+2]);
        }
        // cout << "nbJoueur : " << nbJoueurs << endl;
        plateau = new Plateau(atoi(argv[1]), nbJoueurs/2, algos);
    }
    // Pour les equipes : argv[1] = taille de la grille, argv[2] = algo equipe 1, argv[3] = nb Joueurs, argv[4] = profondeur, argv[5] = algo equipe 2, ...

    plateau->afficher();
    cout << "------------------------------" <<endl;
    cout << "Début du jeu" << endl;
    plateau->play();
    plateau->afficher();
    cout << "------------------------------" <<endl;
    int i = 1;
    while(!plateau->isOver()) {
        cout << "Tour " << i++ << endl;
        plateau->play();
        plateau->afficher();
        cout << plateau->getNbJoueursVivant() << " joueurs restants" << endl;
        cout << "------------------------------" <<endl;
    }
    delete plateau;
    
    return 0;
}