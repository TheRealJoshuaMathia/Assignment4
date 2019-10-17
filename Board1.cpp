#ifndef BoardClass
/*
Authors: Parker Guillen, Josh Mathia
Description:Function definitions for board class
Date created: 10/16/19
*/

#include "Board.h"

//Constructor 
Board::Board(int m)
{
	this->M = m;			//defines board size
}


//destructor
Board::~Board()
{
	cout << "Inside board destructor" << endl;
}


/*
Function name: Insert
parameters: playerid, xPos, yPos
Will allow for inserting of a new player into the board(tree)
Conditions:
playerid must be unique
x,y position should be empty
make sure that insertion of this player will not be greater than M

*/
bool Board::insert(Player playerId, int xPos, int yPos)
{
	//Condition check 
	bool success = false;
	int toinsert = 1;
	if (playerId == playerid already found in board) //search through tree for id 
	{
		toinsert = 0; //cant insert to already occupied positon 
	}
	if (xpos is found on board && y pos is found on board)
	{
		toinsert = 0; 
	}
	if (this->N + 1 >= M)			//if number of players greater than game board size 
	{
		toinsert = 0;		//dont insert
	}

	success = this->gameboard.insert();   //insert returns bool 

	//
	if (success == true)
	{
		cout << "insertion successful" << endl;
		this->N += 1;
	}
	else
	{
		cout << "insertion unsuccessful" << endl;
	}

}


/*
Function Name: Remove
Description: Removes the player from the board by finding the player assicoated with the player ID and removing it using set
erase

*/
bool Board::remove(Player playerID)
{
	//Very basic porbably won't work 
	//either need to adjust the basic class function or figure out how to make it work with x,y values

	int success = 0; 
	bool removed = false; 
	success = gameBoard.erase(playerID);   
	//need to free x,y values but might work fine as x,y are included in player classes
	//brings forth issue of finding the used x,y values within the search tree need to find a way 
	//to implement in either log or constant time
	if (success == 1)
	{
		removed = true;
		cout << "Player ID successfully removed" << endl;
		this->N -= 1; 
	}
	else
	{
		removed = false;
		cout << "Player ID not removed successfully" << endl;

	}

	return removed; 
}

/*
need to go through the tree and find the playerID should be O(log N)
time if implemented correctly or could use STL find function  

*/
bool Board::find(Player playerID)
{

}


bool Board::moveTo(Player playerID, int newxPos, int newyPos)
{
	//first need to check if there is a player with those x,y values 
	bool removesuccess = false;
	if (different player is found at insert position)
	{
		removesuccess = gameboard.remove(player at old position);
	}
	
	//Next want to move the player from current x,y positions to new x,y position 

	//so use insert function which will preform the needed condition checks 
	/*
	Need to figure out how to handle :
	the movement from (x1, y1) to (x2, y2) is always along the same
row or same column or same diagonal in any direction (i.e., top
left -- right-bottom or top-right -- left-bottom).
	*/
}



#endif // !BoardClass
