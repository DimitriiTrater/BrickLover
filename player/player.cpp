#include <SFML\Graphics.hpp>
#include "Player.hpp"


Player::Player(float x, float y, sf::Vector2f size, sf::Color color)
{
    this->x = x;
    this->y = y;

    this->playerShape.setSize(size);
    this->playerShape.setFillColor(color);
    this->playerShape.setPosition({x, y});
}


void Player::setX(float x) // set x position
{this->x = x;}

void Player::setY(float y) // set y position
{this->y = y;}

void Player::setRestriction(float WIDTH)
{
    this->restriction = WIDTH;
}



float Player::getX() // get x position
{return this->x;}

float Player::getY() // get y position
{return this->y;}

float Player::getRestriction(int indexRestriction) // get restriction
{return this->restriction;}


void Player::drawPlayer(sf::RenderWindow& window)
{
    window.draw(this->playerShape);
}


