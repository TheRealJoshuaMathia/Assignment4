/*
Authors: Parker Guillen, Joshua Mathia
Description:Function definitions for board class
Date created: 10/16/19
*/

//Pre Processor Declaratives
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <cstddef>
#include <cstdlib>
#include <set>
#include <algorithm>

#include "Player.h"

//using statements
using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
using namespace std;

class Board
{
public:
	Board(int m);				//constructor
	//M doesnt really do anything if using a tree which grows as values are added
	//M is needed as a way to check if the player id will be in bounds 
	//board copy constructor 
	~Board();					//destructor
	bool insert(int playerID, int xPos, int yPos);
	bool remove(int playerID);
	bool find1(int playerID);
	bool moveTo(int playerID, int newxPos, int newypos);
	void printbyID();
	bool checkInsertion(int xPos, int yPos);
	map<int, Player>::iterator findReturn(int playerID);

	void insertPair(int xPos, int yPos);
	bool removePair(int xPos, int yPos);
	void getPair(int playerID, int* xPos, int* yPos);


private:
	//multimap<Player> gameboard;			QUESTION: What type of tree do we want to use here? Set, Map , mulit-set,map
	//want a tree of player values 
	map<int, Player> gameBoard;		//most likely need to change			//defines set tree of players for housing values 
	int N; //number of players on the board
	int M; //size of the board 
	map <int, Player>::iterator itr;
	multimap <int, int> trackPairs; // Checks list of current (x,y) positions
	multimap <int, int>::iterator pairIT;
};
