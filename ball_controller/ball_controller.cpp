#include <SFML/Graphics.hpp>
#include <iostream>
#include "../ball/ball.hpp"
#include "../player/player.hpp"
#include "ball_controller.hpp"

BallController::BallController(Ball& ball, sf::Keyboard::Key start)
: ball(&ball), start(start)
{}

void BallController::startLive()
{
    if (sf::Keyboard::isKeyPressed(start))
        stateOfLive = true;
}


void BallController::collisionWithBoard()
{
    if (ball->getShapeX() - ball->getR() <= 0)
        dx = -dx;

    if (ball->getShapeY() - ball->getR() <= 0)
        dy = -dy;

    if (ball->getShapeX() + ball->getR() >= ball->getRestriction(0))
        dx = -dx;

    if (ball->getShapeY() + ball->getR() >= ball->getRestriction(1))
    {    
        dy = -dy;
        ball->setPosition({950, 850});
        stateOfLive = false;
    }
}

void BallController::setPlayer(Player& player)
{
    this->player = &player;
}


void BallController::collisionWithPlayer()
{
    if (
        ball->getShapeX() + ball->getR() >= player->getShapeX()                       &&
        ball->getShapeX() + ball->getR() <= player->getShapeX() + player->getSizeX()  &&  
        ball->getShapeY() + ball->getR() == player->getShapeY() - player->getSizeY()
       )
    {
        dy = -dy;
        std::cout << "Ponk!" << std::endl;

    }
}

void BallController::move()
{
    startLive();
    if (stateOfLive)
    {
        collisionWithPlayer();
        collisionWithBoard();
        ball->move(dx, dy);
    }
    else 
    {
        ball->setPosition({player->getShapeX() + player->getSizeX() / 2, player->getShapeY() - player->getSizeY() - 40});
    }
}
