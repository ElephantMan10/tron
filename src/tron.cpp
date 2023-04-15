#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include "IA.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "IA.hpp"
#include "FonctionScientifique.hpp"

int main(int argc, char *argv[]){
	if(argc>1){
		if(atoi(argv[1])==-1){
			cout << "fonction scientifique" <<endl;
			// pour faire les test il faut lancer avec -1 devant pour diférencier d'une partie normale
			// on met derrière en paramètre le nombre de joueur, la profondeur minimal, la profondeur max, le nombre de tests que l'on veut effectuer pour chaque profondeur, la taille de la grille de jeu et les algos a utiliser.
			// pour les algo on peut soit leur donnée le même algo pour tous en ne rajoutant qu'un chiffre ou en rajouter autant qu'il y a de joueur.
			
			// on initialise le jeu avec une grille de 10 par 1O, 4 joueurs, une profondeur minimal de 0, une profondeur max de 10, et les ia utilise l'algo 2
			int nbJoueur=4; 
			int profMin=0; 
			int profMax=10; 
			int nbTest=10; 
			int tailleTab=10; 
			int algo=2; 
			if(argc < 8 && argc!=2) {
				cerr << "Erreur : nombre d'arguments incorrect" << endl << "Usage : ./tron -1 [nbJoueur] [profMin] [profMax] [nbTest] [tailleTab] [algo]" << endl;
				return 0;
			}
			if(argc > 8 && (argc-7)!=atoi(argv[2])) {
				cerr << "Erreur : nombre d'arguments incorrect" << endl << "Usage : ./tron -1 [nbJoueur] [profMin] [profMax] [nbTest] [tailleTab] [algo]" << endl;
				return 0;
			}
			if(argc > 2){ // si on a des argument on remplace les valeur par défaut
				cout << "fonction scientifique" <<endl;
				nbJoueur=atoi(argv[2]); 
				profMin=atoi(argv[3]); 
				profMax=atoi(argv[4]); 
				nbTest=atoi(argv[5]); 
				tailleTab=atoi(argv[6]); 
				algo=atoi(argv[7]); 
			}
			cout << "fonction scientifique" <<endl;
			cout << nbJoueur <<endl;
			cout << profMin <<endl;
			cout << profMax <<endl;
			cout << nbTest <<endl;
			cout << tailleTab <<endl;
			cout << algo <<endl;
			int tab[nbJoueur];
			int algos[nbJoueur];
			for(int i=0; i<nbJoueur; i++){
				tab[i]=1;
				if(argc>8){
					algos[i]=atoi(argv[i+7]); 
				}
				else{
					algos[i]=algo; 
				}
			}
			int taille = profMax-profMin;
			FonctionScientifique *fs = new FonctionScientifique(nbTest, nbJoueur, nbJoueur, algos, tab);
			int** tabV = fs->tabVictoire(profMin, profMax, tailleTab);
			//int** tabV = fs->tabVictoireNbJoueur(10, 15);
			string path = fs->tabToCSV(tabV, nbJoueur, profMin, profMax);
			fs->showGraph(taille, path);
		}
		else{
			cout << "partie classique" <<endl;
			Plateau *plateau; // que des grilles carrées
			if(argc <= 1) plateau = new Plateau(5, 5); // pas d'arguments donc on lance le jeu avec une grille de 5 par 5 et 5 joueurs
			else if(argc == 2) plateau = new Plateau(atoi(argv[1]), 4); // un argument donc on lance le jeu avec une grille de taille argv[1] par argv[1] et 4 joueurs
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
		}
	}

	return 0;
}