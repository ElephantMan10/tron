#ifndef MUR_HPP
#define MUR_HPP

#include <iostream>
#include <string>
#include "Entity.hpp"

using namespace std;

class Mur : public Entity {
    private:
        int x;
        int y;
        int*** plateau;
    public:
        Mur(int x, int y, int*** plateau);
        int getX();
        int getY();
        int*** getPlateau();
        void setX(int x);
        void setY(int y);
        void setPlateau(int*** plateau);
};

#endif