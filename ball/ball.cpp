#include <SFML/Graphics.hpp>
#include "ball.hpp"

Ball::Ball(float x, float y, float r, sf::Color color)
{
    this->x = x;
    this->dx = -1;

    this->y = y;
    this->dy = -1;
    
    this->r = r;
    ballShape.setFillColor(color);
    ballShape.setRadius(r);
    ballShape.setPosition({x, y});

}

void Ball::setX(float x)
{this->x = x;}

void Ball::setDX(float dx)
{this->dx = dx;}


void Ball::setY(float y)
{this->y = y;}

void Ball::setDY(float dy)
{this->dy = dy;}

float Ball::getX()
{return this->x;}

float Ball::getDX()
{return this->dx;}

float Ball::getY()
{return this->y;}

float Ball::getDY()
{return this->dy;}

float Ball::getR()
{return this->r;}

void Ball::drawBall(sf::RenderWindow& window)
{
    window.draw(ballShape);   
}


