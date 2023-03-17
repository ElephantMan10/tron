#include "State.hpp"


State::State(int** board, int taille, vector<int> jvivant , Move* move, vector<State*> children, State* parent, int rootPlayer, int player ,int tour) {
		this->virtualBoard = board;
		this->taille = taille;
		this->jvivant = jvivant;
		this->move = move;
		this->children = children;
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

	vector<State*> State::getNewState(int x, int y, int id){
		Move* m = new Move(x,y,id);
		int ** newBoard;
		vector<vector<int>> moves = m->getAllNextMove();
		vector<Move*> newMoves;

		for(vector<int> move : moves){
			if(move[0] < 0 || move[0] >= this->taille || move[1] < 0 || move[1] >= this->taille){
				continue;
			}
			newBoard = new int*[this->taille];
			for(int i = 0; i < this->taille; i++){
				newBoard[i] = new int[this->taille];
				for(int j = 0; j < this->taille; j++){
					newBoard[i][j] = this->virtualBoard[i][j];
				}
			}
			if(newBoard[move[0]][move[1]] == 0){
				newBoard[move[0]][move[1]] = id;
				newBoard[m->getX()][m->getY()] = -1;
			}
			if(newBoard[move[0]][move[1]] == -1 || newBoard[move[0]][move[1]] != id){
				continue;
			}
			Move* newMove = new Move(move[0],move[1],id);
			newMoves.push_back(newMove);
		}
		vector<int> newJvivant = this->jvivant;
		vector<int> toRemove;
		if(newMoves.empty()){
			toRemove.push_back(id);
		}
		
		for(int id : toRemove){
			for(int i = 0; i < newJvivant.size(); i++){
				if(newJvivant[i] == id){
					newJvivant.erase(newJvivant.begin()+i);
				}
			}
		}

		for(Move* m : newMoves){
			vector<State*> newChildren;
			State* newState = new State(newBoard,this->taille,newJvivant,m,newChildren,this,this->rootPlayer,id,this->tour+1);
			this->children.push_back(newState);
		}
		return this->children;
	}

	int State::getHeuristic(){
	 this->children.size();
	}
