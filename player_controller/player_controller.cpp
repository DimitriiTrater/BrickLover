#include <SFML/Graphics.hpp>
#include <iostream>
#include "../player/player.hpp"
#include "player_controller.hpp"


// private
void PlayerController::moveLeft()
{
    if (sf::Keyboard::isKeyPressed(left))
    {
        std::cout << "Move Left" << std::endl;

        player->move(-moveSpeed);
    }
}


void PlayerController::moveRight()
{
    if (sf::Keyboard::isKeyPressed(right)){
    std::cout << "Move Right" << std::endl;
 
        player->move(moveSpeed);
}}




// public
PlayerController::PlayerController()
{}

PlayerController::PlayerController(Player& player, sf::Keyboard::Key left, sf::Keyboard::Key right)
: player(&player), left(left), right(right)
{}


void PlayerController::move()
{
    this->moveLeft();
    this->moveRight();
}

