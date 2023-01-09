#include "ball.hpp"

Ball::Ball(float x, float y, float r)
{
    this->x = x;
    this->y = y;
    this->r = r;
}

void Ball::setX(float x)
{this->x = x;}

void Ball::setY(float y)
{this->y = y;}

float Ball::getX()
{return this->x;}

float Ball::getY()
{return this->y;}

float Ball::getR()
{return this->r;}

