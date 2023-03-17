#ifndef PARANOID_HPP
#define PARANOID_HPP
#include "State.hpp"
#include "Move.hpp"

class Paranoid {
    public:
        Paranoid(int j, int p);
        int getJoueur();
        int getProfondeur();
        int getCompteur();
        int algo(State* s, int p, int x, int y, int id);
        Move* getBestMove(State* s, int p, int x, int y, int id);
    private:
        int joueur;
        int profondeur;
        int compteur;
};

#endif