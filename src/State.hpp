#ifndef STATE_HPP
#define STATE_HPP
#include <iostream>
#include "Move.hpp"
#include <string>
#include <list>
#include <vector>

using namespace std;

class State {
	private :
		int** virtualBoard;
		int taille;
		vector<int> jvivant;
		Move* move;
		vector<State*> children;
		State* parent;
		int rootPlayer;
		int player;
		int tour;

	public:
		State(int** board, int taille, vector<int> jvivant, Move* move, vector<State*> children, State* parent, int rootPlayer, int player , int tour);
		int** getBoard();
		int getTaille();
		vector<int> getJvivant();
		Move* getMove();
		vector<State*> getChildren();
		State* getParent();
		int getRootPlayer();
		int getPlayer();
		int getTour();
		bool isTerminal();
		int getJoueur();
		State* play();
		vector<State*> getNewState(int x, int y, int id);
		int getHeuristic();
};

#endif