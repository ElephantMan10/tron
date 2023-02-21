#include <stdio.h>
#include <stdlib.h>

#include "Entity.hpp"
#include "IA.hpp"
#include "Joueur.hpp"
#include "Mur.hpp"
#include "Plateau.hpp"
#include "IA.hpp"

int main(int argc, char *argv[])
{
    Plateau *plateau = new Plateau(10, 5);
    plateau->afficher();
    
    return 0;
}