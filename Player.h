#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <cstddef>
#include <cstdlib>
#include <set>
#include <map>

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

class Player
{
public :
	/*
	-each player must occupy a unique position on the board 
	-makes the most sense for x,y values to be included in the player class but this brings problems with how to 
	arrange the values in our board tree, and how to find a fast way to access the player position depending on how we 
	insert players
	*/
	Player(int playerID, int xPos, int yPos);		//let user specify id at insert
	~Player();										//player destructor 

	//getters
	int getID() const;								
	int getxPos() const;
	int getyPos() const; 

	//setters
	void setID(int newID);				//probably don't need since each id is assigned to a player at creation 
	void setxPos(int newxPos);			//needed for moveto function but how to access from board class?
	void setyPos(int newyPos);

	//Other public functions? overloaed operators? 


private:
	//want a tree of player values 
	//Before inserts we must check if player positions are in bounds
	int xPos; //number of players on the board
	int yPos; //size of the board 
	int playerID;
};