#include <SFML/Graphics.hpp>
#include "ball.hpp"

Ball::Ball(float x, float y, float r, sf::Color color)
{
    this->x = x;
    // this->dx = -1;

    this->y = y;
    // this->dy = -1;
    
    this->r = r;
    ballShape.setFillColor(color);
    ballShape.setRadius(r);
    ballShape.setPosition({x, y});

}

void Ball::setX(float x)
{this->x = x;}

void Ball::setY(float y)
{this->y = y;}

void Ball::setRestriction (float restriction, int index)
{
    this->restriction[index] = restriction;
}

void Ball::setPosition (sf::Vector2f pos)
{
    ballShape.setPosition(pos);
}


float Ball::getX()
{return this->x;}

float Ball::getY()
{return this->y;}

float Ball::getR()
{return this->r;}

float Ball::getRestriction(int index)
{return this->restriction[index];}

float Ball::getShapeX()
{
    return ballShape.getPosition().x;
}
float Ball::getShapeY()
{
    return ballShape.getPosition().y;
}



void Ball::move(float x, float y)
{
    ballShape.move({x, y});
}

void Ball::drawBall(sf::RenderWindow& window)
{
    window.draw(ballShape);   
}


