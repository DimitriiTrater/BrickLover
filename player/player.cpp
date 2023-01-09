#include "Player.hpp"


Player::Player(float x, float y) // constructor
{
    this->x = x;
    this->y = y;
}


void Player::setX(float x) // set x position
{this->x = x;}

void Player::setY(float y) // set y position
{this->y = y;}

void Player::setRestriction(float restriction, int indexRestriction)
{this->restriction[indexRestriction] = restriction;}



float Player::getX() // get x position
{return this->x;}

float Player::getY() // get y position
{return this->y;}

float Player::getRestriction(int indexRestriction) // get restriction
{return this->restriction[indexRestriction];}
