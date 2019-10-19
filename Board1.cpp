/*
Authors: Parker Guillen, Josh Mathia
Description:Function definitions for board class
Date created: 10/16/19
*/

#include "Board.h"

//Constructor 
Board::Board(int m)
{
	this->M = m; //defines board size
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
bool Board::insert(int playerId, int xPos, int yPos)
{
	//Check conditions of insertion
	bool success = false;
	bool checkCord = false;

	Player newPlayer(playerId, xPos,yPos);

	//Test to see if playerID exits already in gameboard 
	if(gameBoard.find(playerId) != gameBoard.end()) // find returns an iterator to the end if no element is found
	{
		success = false; //player ID exists in tree already
	}

	//Check if the given X & Y exists in game board.
	checkCord = checkInsertion(xPos, yPos);

	//If checkCord equals true insertion is violated.
	if(checkCord == true)
	{
		success = false;
	}

	//Conditon 3: Checks if the insertion will exceed the board
	if (this->N + 1 > M) //if number of players greater than game board size 
	{
		success = false;	//dont insert
	}

	this->gameBoard.insert({playerId,newPlayer});   //insert returns bool 
	success = true;
	
	if (success == true)
	{
		//Insert (x,y)
		this->insertPair(xPos, yPos);
		cout << "insertion successful" << endl;
		this->N += 1;
	}
	else
	{
		cout << "Insertion was unsuccessful" << endl;
	}

	return success;
}

/*
Function Name: Remove
Description: Removes the player from the board by finding the player assicoated with the player ID and removing it using set
erase

*/
bool Board::remove(int playerID)
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
		this->removePair();
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
bool Board::find(int playerID)
{
	bool success = false; 
	if (this->gameBoard.find(playerID) == gameBoard.end())
	{
		cout << "Player not found in board." << endl; 
		success = false;
	}
	else
	{
		cout << "Player found in board." << endl;
		success = true; 
	}

	return success;
}

/*
Used to print the contents of the STL map 
*/
void Board::printbyID()
{
	for (map<int, Player>::const_iterator it = gameBoard.begin();
		it != gameBoard.end(); ++it)
	{
		cout << "Player id: " << it->first << "X position: " << it->second.getxPos() << "Y position: " << it->second.getyPos() << endl; 
	}
}

bool Board::moveTo(Player playerID, int newxPos, int newyPos)
{
	//first need to check if there is a player with those x,y values 
	//bool removesuccess = false;
	// if (different player is found at insert position)
	// {
	// 	removesuccess = gameboard.remove(player at old position);
	// }
	
	//Next want to move the player from current x,y positions to new x,y position 

	//so use insert function which will preform the needed condition checks 
	/*
	Need to figure out how to handle :
	the movement from (x1, y1) to (x2, y2) is always along the same
row or same column or same diagonal in any direction (i.e., top
left -- right-bottom or top-right -- left-bottom).
	*/
}

bool Board::checkInsertion(int &xPos, int &yPos)
{
	bool found = false;

	pairIT = this->trackPairs.find(xPos); // Iterates starting at given x Position

	for(; pairIT != trackPairs.end(); pairIT++)
	{
		if((*pairIT).first == xPos && (*pairIT).second == yPos)
		{
			found = true;
		}
	}
	return found;
}

<<<<<<< HEAD
// Function is passed the (x,y) cordinates 
// The cordinates are made into a pair
// And pushed to the back of the list
// The list is sorted at insertion
void Board::insertPair(int &xPos, int &yPos)
{
	this->trackPairs.insert(xPos, yPos);

}

bool Board::removePair(int &xPos, int &yPos)
{
	bool success = false;

	pairIT = this->trackPairs.find(xPos); // Iterates starting at given x Position

	for(; pairIT != trackPairs.end(); pairIT++)
	{
		if((*pairIT).first == xPos && (*pairIT).second == yPos)
		{
			this->trackPairs.erase(pairIT);
			success = true;
		}
	}
	return success;
	
}

void Board::getPair()
{
	
	for()

}
=======

map<int,Player>::iterator Board::findReturn(int playerID)			//instead of this we could have trees for x and y positions as well to improve timing
{
	bool found = false;

	this->itr = gameBoard.begin();

	map<int, Player>::iterator toreturn; 

	for (; itr != gameBoard.end(); itr++)
	{
		if (itr->first == playerID)
		{
			found = true;
			return itr;
		}
	}
	//return found;
}


bool Board::moveTo(int playerID, int newxPos, int newyPos)
{

	map<int, Player>::iterator playertomove; 

	playertomove = this->gameBoard.find(playerID);				//
	
	if (checkInsertion(newxPos, newyPos) == true)			//if true there is already a player at this position which needs to be removed
	{
		//how do we access the player id from the y values 
		//since we need to remove then player at the occipuided poition 
		//want to return the iterator from first to access this key 
		//find player and remove them

	}

	//need to check if x is the same 
	int xoffset = 0, yoffset = 0; 
	bool tomove = false;
	xoffset = abs(playertomove->second.getxPos() - newxPos);
	yoffset = abs(playertomove->second.getyPos() - newyPos);
	if (newxPos > this->M || newyPos > this->M)					//are we doing with zero positions or starting at 1//UPDATE
	{
		cout << "wanted positions are out of range" << endl;
		tomove = false;
	}
	else if ((playertomove->second.getxPos() == newxPos) && (playertomove->second.getyPos() != newyPos))		//moving up or down a column
	{
		//x position isnt changing so this is 
		tomove = true;
	}
	else if ((playertomove->second.getxPos() != newxPos) && (playertomove->second.getyPos() == newyPos))			//moving left of right a row 
	{
		tomove = true;
	}
	else if (xoffset == yoffset)										//diagonal move 
	{
		tomove = true;  
	}
	else
	{
		tomove = false;
	}

	
	if (tomove == true)
	{
		playertomove->second.setxPos(newxPos);			//changes the players x position 
		playertomove->second.setyPos(newyPos);			//changes the players y position 
		cout << "Player successfully moved" << endl;
	}
	else
	{
		cout << "Player could not be removed" << endl;
	}

	return tomove;
}
>>>>>>> b72e3f00a111a0115e3220fdaf1bdb402321d73c
