#ifndef IA_HPP
#define IA_HPP

#include <iostream>
#include <string>

class IA {
    private:
        int x;
        int y;
        int** plateau;
        int* score;
    public:
        IA(int x, int y, int** plateau, int* score);
        int getX();
        int getY();
        int getScore();
        int** getPlateau();
        void setX(int x);
        void setY(int y);
        void setScore(int score);
        void setPlateau(int** plateau);
};

#endif