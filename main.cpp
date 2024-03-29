#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "font/sansation.hpp"
#include "button/button.hpp"
#include "menu/menu.hpp"
#include "player/player.hpp"
#include "player_controller/player_controller.hpp"
#include "ball/ball.hpp"
#include "ball_controller/ball_controller.hpp"


int main(int argc, char* argv[])
{

    // font
    sf::Font font;
    font.loadFromMemory(&sansation_ttf, sansation_ttf_len);


    // button for exit from level
    Button exitFromLevelButton("Back", {100, 50}, 20, sf::Color::White, sf::Color::Black);
    exitFromLevelButton.setPosition({10, 10});
    exitFromLevelButton.setFont(font);

    // States of the game
    enum State
    {
        MainMenuState,
        InGameState,
    };

    State state = MainMenuState; // standard state

    // full hd
    const double WIDTH  = 1920;
    const double HEIGHT = 1080;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "BrickLover", sf::Style::Fullscreen);

    // buttons for main menu
    float buttonsW = 400;
    float buttonsH = 100; 
    float charSize = 40;

    Menu mainMenu(
        Button("Start",  {buttonsW, buttonsH}, charSize, sf::Color::White, sf::Color::Black),
        Button("Quit",   {buttonsW, buttonsH}, charSize, sf::Color::White, sf::Color::Black)
    );

    mainMenu.setButtonsFont(font);
    mainMenu.setButtonsPosition(WIDTH, HEIGHT, buttonsW, buttonsH);

    // Create player and controller
    Player player(800, 950, {300, 25}, sf::Color::White);
    player.setRestriction(WIDTH);

    PlayerController controller(player, sf::Keyboard::Left, sf::Keyboard::Right);

    Ball ball(925, 850, 20, sf::Color::White);
    ball.setRestriction(WIDTH, 0);
    ball.setRestriction(HEIGHT, 1);


    BallController ballController(ball, sf::Keyboard::Space);
    ballController.setPlayer(player);

    // count of lives
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition({300, 10});

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            switch (state)
            {
            case MainMenuState:
                if (event.type == sf::Event::MouseButtonReleased)
                {
                    // start tutorial
                    if (mainMenu.isCoverButton(window, 0))
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {
                            mainMenu.setAnyButtonsBackground(Menu::bgClicked, 0); 
                            state = InGameState;
                        }

                    // quit
                    if (mainMenu.isCoverButton(window, 1))
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {
                            mainMenu.setAnyButtonsBackground(Menu::bgClicked, 1);
                            window.close();    
                        }
                }                
                
                if (event.type == sf::Event::MouseMoved)
                {
                    // start button
                    if (mainMenu.isCoverButton(window, 0))
                        mainMenu.setAnyButtonsBackground(Menu::bgCover, 0);
                    else mainMenu.setAnyButtonsBackground(Menu::bgStandard, 0);

                    // quit button
                    if (mainMenu.isCoverButton(window, 1))
                        mainMenu.setAnyButtonsBackground(Menu::bgCover, 1);
                    else mainMenu.setAnyButtonsBackground(Menu::bgStandard, 1);
                }
                
                break;
            case InGameState:
                if (event.type == sf::Event::MouseMoved)
                    if (exitFromLevelButton.isMouseCover(window))
                        exitFromLevelButton.setBGColor(Menu::bgCover);
                    else exitFromLevelButton.setBGColor(Menu::bgStandard);

                if (event.type == sf::Event::MouseButtonReleased)
                    if (exitFromLevelButton.isMouseCover(window))
                        if (event.mouseButton.button == sf::Mouse::Left)
                                state = MainMenuState;
                if (ballController.getLives() < 1)
                {
                    state = MainMenuState;
                    window.close();
                }               
                
                break;
            default:
                break;
            }
        }            
        window.clear();

        switch (state)
        {
        case MainMenuState:
            mainMenu.drawMenu(window);
            break;
        case InGameState:
            text.setString("Lives: " + std::to_string(ballController.getLives()));
            window.draw(text);
            ballController.move();
            controller.move();
            ball.drawBall(window);
            player.drawPlayer(window);
            exitFromLevelButton.drawButton(window);
            break;
        default:
            window.clear();
            break;
        }
        
        window.display();
    }
    return 0;
}