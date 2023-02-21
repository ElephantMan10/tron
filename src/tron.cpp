#include <stdio.h>
#include <stdlib.h>

#include "IA.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "IA.hpp"

int main(int argc, char *argv[])
{
    Plateau *plateau = new Plateau(6, 5);
    // plateau->afficher();
    // cout << "------------------------------" <<endl;
    // plateau->play();
    // plateau->afficher();
    int i = 0;
    while(!plateau->isOver()) {
        cout << "Tour " << i++ << endl;
        cout << plateau->getNbJoueursVivant() << " joueurs restants" << endl;
        plateau->play();
        plateau->afficher();
        cout << "------------------------------" <<endl;
    }
    
    return 0;
}