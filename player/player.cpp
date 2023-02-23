#include <SFML\Graphics.hpp>
#include "Player.hpp"


Player::Player()
{}


Player::Player(float x, float y, sf::Vector2f size, sf::Color color)
{
    this->x = x;
    this->y = y;

    this->size = size;
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

float Player::getRestriction() // get restriction
{return this->restriction;}

void Player::move(float x) // move;
{
    playerShape.move({x, 0});
}

float Player::getShapeX() // get shape x coordinates
{
    return playerShape.getPosition().x;
}

float Player::getShapeY() // get shape y coordinates
{
    return playerShape.getPosition().y;
}


float Player::getSizeX() // get size
{
    return this->size.x;
}

float Player::getSizeY() // get size y
{
    return this->size.y;
}


void Player::drawPlayer(sf::RenderWindow& window)
{
    window.draw(this->playerShape);
}


