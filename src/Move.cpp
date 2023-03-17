#include "Move.hpp"

/*s'occcupe seuelement de renvoyer les prochaines coordonnées du joueur 
qu'elle soit valide ou non*/

Move::Move(int x, int y, int id) {
    this->x = x;
    this->y = y;
    this->id = id;
}

int Move::getX() {
    return this->x;
}

int Move::getY() {
    return this->y;
}

int Move::getId() {
    return this->id;
}

vector<vector<int>> Move::getAllNextMove() {
    vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> allNextMove;
    for(vector<int> move : direction) {
        vector<int> v;
        v.push_back(this->x+move[0]);
        v.push_back(this->y+move[1]);
        allNextMove.push_back(v);
    }

    return allNextMove;
}

void Move::afficher() {
    cout << "x : " << this->x << " y : " << this->y << " id : " << this->id << endl;
}

