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

/*
Information: 
Set and map trees provide log time for insertion, deletion, and searching.

SET: Ordered container that doesn't allow duplicates, iterator types can be used to access elements, 
begin,end,empty,size can all be used
Insert: returns an iterator 

MAP: stores collection of ordered values that consist of their keys and the values at the keys,
keys are unique but values are not, many keys can map to the same values. 
for inserting must provide pair<Keytype, value type> 
Find not very useful for searching 
can use array indexing operator ValueType & operator[](const keyType & key) 

NOTE: The current tree used for the game board probably isn't the right way to implement as we need to be able to 
access elements in the tree in at least log n time

*/

class Board
{
public:
	Board(int m);				//constructor
	//M doesnt really do anything if using a tree which grows as values are added
	//M is needed as a way to check if the player id will be in bounds 
	//board copy constructor 
	~Board();					//destructor
	//NEED TO FIGURE OUT HOW STRUCTURE TREE SO PLAYER POSITION VALUES ARE EASILY ACCESSED
	bool insert(int playerID, int xPos, int yPos);
	bool remove(int playerID);
	bool find(Player playerID);
	bool moveTo(Player playerID, int newxPos, int newypos);
	void printbyID();
	bool checkInsertion(int &xPos, int &yPos);



private:
	//multimap<Player> gameboard;			QUESTION: What type of tree do we want to use here? Set, Map , mulit-set,map
	//want a tree of player values 
	map<int,Player> gameBoard;		//most likely need to change			//defines set tree of players for housing values 
	int N; //number of players on the board
	int M; //size of the board 
	map <int,Player>::iterator itr;
};
