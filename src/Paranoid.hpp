#ifndef PARANOID_HPP
#define PARANOID_HPP
#include "Joueur.hpp"
#include "State.hpp"

class Paranoid {
    public:
        Paranoid(int j, int p);
        int algo(State* s, int p, Joueur* j);
    private:
        int joueur;
        int profondeur;
        int compteur;
};

#endif