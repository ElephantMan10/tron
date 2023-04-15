#include "State.hpp"


State::State(int** board, int taille, vector<int> jvivant , Move* move, State* parent, int rootPlayer, int player ,int tour) {
	this->virtualBoard = board;
	this->taille = taille;
	this->jvivant = jvivant;
	this->move = move;
	this->children = vector<State*>(); // pas de children pour l'instant
	this->parent = parent;
	this->rootPlayer = rootPlayer;
	this->player = player;
	this->tour = tour;
};

int** State:: getBoard(){
	return this->virtualBoard;
}

int State:: getTaille(){
	return this->taille;
}

Move* State:: getMove(){
	return this->move;
}

vector<State*> State:: getChildren(){
	return this->children;
}

State* State:: getParent(){
	return this->parent;
}

int State:: getRootPlayer(){
	return this->rootPlayer;
}

int State:: getPlayer(){
	return this->player;
}

int State:: getTour(){
	return this->tour;
}

vector<int> State:: getJvivant(){
	return this->jvivant;
}

bool State:: isTerminal(){
	if(this->children.empty() || this->jvivant.size() == 1){
		return true;
	}
	else{
		return false;
	}
}

int State:: getNextJoueur(int id){
	for(size_t i = 0; i < this->jvivant.size(); i++){
		if(this->jvivant[i] == id){
			if(i == this->jvivant.size()-1)
				return this->jvivant[0];
			else
				return this->jvivant[i+1];
		}
	}
	return -1;
}

vector<int> State:: getNextJoueurCoord(int id){
	vector<int> coord;
	int newid = this->getNextJoueur(id);
	for(int i = 0; i < this->taille; i++){
		for(int j = 0; j < this->taille; j++){
			if(this->virtualBoard[i][j] == newid){
				coord.push_back(i);
				coord.push_back(j);
				return coord;
			}
		}
	}
	return coord;
}

vector<State*> State::getNewState(int x, int y, int id){
	Move* m = new Move(x,y,id);
	vector<int **> allNewBoard;
	vector<vector<int>> moves = m->getAllNextMove();
	vector<Move*> newMoves;

	for(vector<int> move : moves){
		if(move[0] < 0 || move[0] >= this->taille || move[1] < 0 || move[1] >= this->taille){
			continue;
		}
		int** newBoard = new int*[this->taille];
		for(int i = 0; i < this->taille; i++){
			newBoard[i] = new int[this->taille];
			for(int j = 0; j < this->taille; j++){
				newBoard[i][j] = this->virtualBoard[i][j];
			}
		}
		newBoard[m->getX()][m->getY()] = -1;
		if(newBoard[move[0]][move[1]] == 0){
			newBoard[move[0]][move[1]] = id;
			Move* newMove = new Move(move[0],move[1],id);
			newMoves.push_back(newMove);
			allNewBoard.push_back(newBoard);
		}
	}
	vector<int> newJvivant = this->jvivant;
	vector<int> toRemove;
	if(newMoves.empty()){
		toRemove.push_back(this->player);
	}

	for(int ida : toRemove){
		for(size_t i = 0; i < newJvivant.size(); i++){
			if(newJvivant[i] == ida){
				newJvivant.erase(newJvivant.begin()+i);
			}
		}
	}

	int newId = this->getNextJoueur(this->player);
	for(size_t i = 0; i < newMoves.size(); i++){
		Move *m = newMoves[i];
		State* newState = new State(allNewBoard[i],this->taille,newJvivant,m,this,this->rootPlayer,newId,this->tour);
		this->children.push_back(newState);
	}
	return this->children;
}

int State::getHeuristic(){
	pair<int,int> coord = {this->move->getX(),this->move->getY()};
	vector<pair<int,int>>* visited = new vector<pair<int,int>>();
    return heuristic(this->virtualBoard,this->taille,coord,visited);
	// return this->children.size();
}

int heuristic(int** board, int taille, pair<int,int> coord, vector<pair<int,int>>* visited) {
	for(pair<int,int> p : *visited){
        if(p.first == coord.first && p.second == coord.second){
            return -1;
        }
    }
    visited->push_back(coord);
    int count = 0;
    if(coord.first > 0 && board[coord.first-1][coord.second] == 0){
        count += 1 + heuristic(board,taille,{coord.first-1,coord.second},visited);
    }
    if(coord.first < taille-1 && board[coord.first+1][coord.second] == 0){
        count += 1 + heuristic(board,taille,{coord.first+1,coord.second},visited);
    }
    if(coord.second > 0 && board[coord.first][coord.second-1] == 0){
        count += 1 + heuristic(board,taille,{coord.first,coord.second-1},visited);
    }
    if(coord.second < taille-1 && board[coord.first][coord.second+1] == 0){
        count += 1 + heuristic(board,taille,{coord.first,coord.second+1},visited);
    }
    return count;
}