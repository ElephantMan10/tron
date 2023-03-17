#ifndef MOVE_HPP
#define MOVE_HPP
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Move {
    private :
        int x;
        int y;
        int id;

    public:
        Move(int x, int y, int id);
        int getX();
        int getY();
        int getId();
        vector<vector<int>> getAllNextMove();
        void afficher();
};




#endif