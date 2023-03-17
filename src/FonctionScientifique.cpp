#include "FonctionScientifique.hpp"
/**
 * La classe qui définie le plateau de jeu et les fonctions permettant d'interagir avec.
 * @author Mathis Roptin, Alexander Camatchy, Victoire Dane Moukoko Ndongo, Felix Senechal, Université de Caen Normandie
 */
 FonctionScientifique::FonctionScientifique(int nbtest, int nbJoueur, int algo, int* repartitionEquipe){
    this->nbtest=nbtest;
    this->nbJoueur=nbJoueur;
    this->algo=algo;
    this->repartitionEquipe=repartitionEquipe;
 }
 int** FonctionScientifique::tabVictoire(int profMax, int taille){
    int** tab;
    
    for(int prof=0; prof<profMax; prof++){
        int algos[nbJoueur];
        for(int i = 0; i<sizeof(repartitionEquipe); i++) {
            //algos : l'algo(algo), profondeur, nbequipier
            algos[i] = algo;
            algos[i+1] = prof;
            algos[i+2] = repartitionEquipe[i];  
        }
        for(int i=0; i < sizeof(repartitionEquipe); i++) {
            tab[prof][i] = 0;
        }
        for(int j = 0; j<100;j++){
            Plateau *plateau = new Plateau(taille, nbJoueur, algos);
            while(!plateau->isOver()){
                plateau->play();
            }
            int winner = plateau->getWinner()[0];
            tab[prof][winner] +=1;
        }
        
    }
    return tab;
 }

 int FonctionScientifique::VictoireTaille(int profMax, int tailleMax){
    int*** tab;
    for(int taille=3; taille<=tailleMax; taille++){
        tab[taille-3] = tabVictoire(profMax, taille);
    }
    return 0;
 }

 int FonctionScientifique::PointCroisement(int j, int** tab){
    for(int i; i<=sizeof(tab); i++){
        for(int t; t<sizeof(tab[i]); i++){
            if(tab[i][t]>=tab[i][j]){
                break;
            }
            return i;
        }
    }
    return -1;
 }

 int* FonctionScientifique::getProfondeurDifficille(int j, int*** tab){
    int* result = new int[2];
    result[0]=0;
    result[1]=0;
    for(int i; i<=sizeof(tab); i++){
        int p = PointCroisement(j, tab[i]);
        if(result[0]<p){
            result[0]=p;
            result[1]=i+3;
        }
    }
    return result;
 }

int* FonctionScientifique::getProfondeurFacille(int j, int*** tab){
    int* result = new int[2];
    result[0]=100000;
    result[1]=0;
    for(int i; i<=sizeof(tab); i++){
        int p = PointCroisement(j, tab[i]);
        if(result[0]>p){
            result[0]=p;
            result[1]=i+3;
        }
    }
    return result;
 }

int FonctionScientifique::MoyenneProfondeur(int j, int*** tab){
    int result = 0;
    for(int i; i<=sizeof(tab); i++){
        int p = PointCroisement(j, tab[i]);
        result+=p;
    }
    return result/sizeof(tab);
 }