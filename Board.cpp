/*
Authors: Parker Guillen, Joshua Mathia
Description:Function definitions for board class
Date created: 10/16/19
*/

#include "Board.h"

//Constructor 
Board::Board(int m)
{
	this->M = m; //defines board size
}

//Destructor
Board::~Board()
{
	cout << "Inside board destructor" << endl;
}

/*
Function name: Insert
parameters: playerID, xPos, yPos
Will allow for inserting of a new player into the board(tree)
Conditions:
playerid must be unique
x,y position should be empty
make sure that insertion of this player will not be greater than M
*/
bool Board::insert(int playerId, int xPos, int yPos)
{
	
	//Check conditions of insertion
	bool success = true;
	bool checkCord = false;

	Player newPlayer(playerId, xPos, yPos);

	//Test to see if playerID exits already in gameboard 
	if (gameBoard.find(playerId) != gameBoard.end()) // find returns an iterator to the end if no element is found
	{
		success = false; //player ID exists in tree already
	}

	//Check if the given X & Y exists in game board.
	checkCord = checkInsertion(xPos, yPos);

	//If checkCord equals true insertion is violated.
	if (checkCord == true)
	{
		success = false;
	}

	//Conditon 3: Checks if the insertion will exceed the board
	if (this->N + 1 > M) //if number of players greater than game board size 
	{
		success = false;	//dont insert
	}

	   //insert returns bool 
	//success = true;
	if (xPos > this->M || yPos > this->M)
	{
		cout << "Positions out of board range insertion failed" << endl;
		success = false;
	}

	if (success != false)
	{
		this->gameBoard.insert({ playerId,newPlayer });   //insert returns bool 
		this->insertPair(xPos, yPos);
		success = true;
		cout<< "insertion successful" << endl;
		this->N += 1;
	}
	else
	{
		cout << "insertion unsuccessful" << endl;
	}


	return success;
}

bool Board::remove(int playerID)
{
	int success = 0; 
	bool removed = false; 
	success = gameBoard.erase(playerID); 
  
	int xPos, yPos;
	
	if (success == 1)
	{
		this->getPair(playerID,&xPos, &yPos);
		this->removePair(xPos, yPos);
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
Function name: find
parameters: playerid, xPos, yPos
Will allow for inserting of a new player into the board(tree)
Conditions:
playerid must be unique
x,y position should be empty
make sure that insertion of this player will not be greater than M

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
		cout << "Player id: " << it->first << "\tposition: " << "("<< it->second.getxPos() << ", " << it->second.getyPos()<< ")" << endl;  
	}
}

bool Board::checkInsertion(int xPos, int yPos)
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

// Function is passed the (x,y) cordinates 
// The cordinates are made into a pair
// And pushed to the back of the list
// The list is sorted at insertion
void Board::insertPair(int xPos, int yPos)
{
	this->trackPairs.insert({ xPos, yPos });

}

bool Board::removePair(int xPos, int yPos)
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

void Board::getPair(int playerID, int *xPos, int *yPos)
{

	itr = this->gameBoard.find(playerID);
	for(; itr != gameBoard.end(); itr++)
	{
		if((*itr).first == playerID)
		{
			*xPos = (*itr).second.getxPos();
			*yPos = (*itr).second.getxPos();
		}
	}
}

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
}

// Function: moveTo()
// 
bool Board::moveTo(int playerID, int newxPos, int newyPos)
{

	map<int, Player>::iterator playertomove; 

	playertomove = this->gameBoard.find(playerID);
	
	if (checkInsertion(newxPos, newyPos) == true) //if true there is already a player at this position which needs to be removed
	{
		for (itr = gameBoard.begin(); itr != gameBoard.end(); itr++)
		{
			if(gameBoard.at(playerID).getxPos() == newxPos && gameBoard.at(playerID).getyPos() == newyPos)
			{
				remove(playerID);

			}
		}
		
		//how do we access the player id from the y values 
		//since we need to remove then player at the occipuided position 
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
