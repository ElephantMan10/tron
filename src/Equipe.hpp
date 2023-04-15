#include <iostream>
#include <string>
#include <vector>
#include "Joueur.hpp"
#include "IA.hpp"

using namespace std;

class Equipe {
    private:
        int id;
        vector<Joueur*> joueurs;
        vector<Joueur*> joueursVivants;
        vector<int> joueursInt;
        int** plateau;
        int nbJoueurs;
        int nbJoueursVivants;
        int idAlgo;
        bool vivant;
    public:
        Equipe(int id, vector<Joueur*> joueurs, int** plateau, int idAlgo, int taille);
        Equipe(int id, int nbJoueurs, int** plateau, int idAlgo, int taille, int profondeur, int idStart);
        int getId();
        vector<Joueur*> getJoueurs();
        int getNbJoueurs();
        int getNbJoueursVivants();
        int** getPlateau();
        void setId(int id);
        void setJoueurs(vector<Joueur*> joueurs);
        void setPlateau(int** plateau);
        void setPlateauJoueurs();
        void addJoueur(Joueur* joueur);
        void removeJoueur(Joueur* joueur);
        bool operator==(const Equipe &equipe);
        bool contains(Joueur* joueur);
        void joueurMort(Joueur* joueur);
        void play();
        void setVivant(bool vivant);
        bool isVivant();
};