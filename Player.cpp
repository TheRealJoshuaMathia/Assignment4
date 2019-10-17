#ifndef Player

/*
Description: Class definitions for player class
*/

#include "Player.h"


Player::Player(int playerID, int xPos, int yPos)
{
	this->playerID = playerID;
	this->xPos = xPos;
	this->yPos = yPos;
}

Player::~Player()
{
	cout << "inside player destructor" << endl;
}


//getters
int Player::getID() const
{
	return this->playerID;
}

int Player::getxPos() const
{
	return this->xPos;
}

int Player::getyPos() const
{
	return this->yPos;
}

//setters
void Player::setxPos(int newxPos)
{
	this->xPos = newxPos;
}

void Player::setyPos(int newyPos)
{
	this->yPos = newyPos;
}




#endif // !Player
