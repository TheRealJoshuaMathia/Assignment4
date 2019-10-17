#include "Player.h"

Player::Player(int playerID, int xPos, int yPos)
{
    this->playerID = playerID;
    this->xPos = xPos;
    this->yPos = yPos;
}

Player::~Player()
{
    //Destructor
}
int Player::getID()const
{
    return this->playerID;
}
int Player::getxPos()const
{
    return this->xPos;
}
int Player::getyPos()const
{
    return this->yPos;
}

void Player::setID(int newID)
{
    this->playerID = newID;
}

void Player::setxPos(int newxPos)
{
    this->xPos = newxPos;
}
 
void Player::setyPos(int newyPos)
{
    this->yPos = newyPos;
}
