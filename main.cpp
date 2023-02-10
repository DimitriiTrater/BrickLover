#include <SFML/Graphics.hpp>
#include <iostream>
#include "font/sansation.hpp"
#include "button/button.hpp"
#include "menu/menu.hpp"
#include "level_menu/level_menu.hpp"
#include "player/player.hpp"
#include "player_controller/player_controller.hpp"
#include "ball/ball.hpp"


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
        LevelMenuState,
        FirstLevelState,
        SecondLevelState,
        ThirdLevelState,
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
        Button("Levels", {buttonsW, buttonsH}, charSize, sf::Color::White, sf::Color::Black), 
        Button("Quit",   {buttonsW, buttonsH}, charSize, sf::Color::White, sf::Color::Black)
    );

    mainMenu.setButtonsFont(font);
    mainMenu.setButtonsPosition(WIDTH, HEIGHT, buttonsW, buttonsH);

    // buttons for levels menu
    float levelW = 70;
    float levelH = 70;

    LevelMenu levelMenu(
        Button("1",  {levelW, levelH}, charSize, sf::Color::White, sf::Color::Black),
        Button("2",  {levelW, levelH}, charSize, sf::Color::White, sf::Color::Black),
        Button("3",  {levelW, levelH}, charSize, sf::Color::White, sf::Color::Black),
        Button("4",  {levelW, levelH}, charSize, sf::Color::White, sf::Color::Black),
        Button("<-", {levelW, levelH}, charSize, sf::Color::White, sf::Color::Black)
    );

    levelMenu.setButtonsLevelFont(font);
    levelMenu.setButtonsLevelPosition(WIDTH, HEIGHT, buttonsW, buttonsH);

    // Create player and controller
    Player player(800, 950, {300, 25}, sf::Color::White);
    player.setRestriction(WIDTH);

    PlayerController controller(player, sf::Keyboard::Left, sf::Keyboard::Right);

    Ball ball(925, 850, 20, sf::Color::White);

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
                    // start game
                    if (mainMenu.isCoverButton(window, 0))
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {
                            mainMenu.setAnyButtonsBackground(Menu::bgClicked, 0); // TODO: launch first level
                            state = FirstLevelState;
                        }

                    // open levels
                    if (mainMenu.isCoverButton(window, 1))
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {
                            mainMenu.setAnyButtonsBackground(Menu::bgClicked, 1);
                            state = LevelMenuState;
                        }

                    // quit
                    if (mainMenu.isCoverButton(window, 2))
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {
                            mainMenu.setAnyButtonsBackground(Menu::bgClicked, 2);
                            window.close();    
                        }
                }                
                
                if (event.type == sf::Event::MouseMoved)
                {
                    // start button
                    if (mainMenu.isCoverButton(window, 0))
                        mainMenu.setAnyButtonsBackground(Menu::bgCover, 0);
                    else mainMenu.setAnyButtonsBackground(Menu::bgStandard, 0);

                    // levels button
                    if (mainMenu.isCoverButton(window, 1))
                        mainMenu.setAnyButtonsBackground(Menu::bgCover, 1);
                    else mainMenu.setAnyButtonsBackground(Menu::bgStandard, 1);


                    // quit button
                    if (mainMenu.isCoverButton(window, 2))
                        mainMenu.setAnyButtonsBackground(Menu::bgCover, 2);
                    else mainMenu.setAnyButtonsBackground(Menu::bgStandard, 2);
                }
                
                break;
            case LevelMenuState:
                if (event.type == sf::Event::MouseButtonReleased)
                    if (levelMenu.isCoverButton(window, 4))
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {
                            levelMenu.setAnyButtonsBackground(Menu::bgClicked, 4);
                            state = MainMenuState;
                        }
                
                if (event.type = sf::Event::MouseMoved)
                    for (int i = 0; i < 5; i++)
                        if (levelMenu.isCoverButton(window, i))
                            levelMenu.setAnyButtonsBackground(Menu::bgCover, i);
                        else levelMenu.setAnyButtonsBackground(Menu::bgStandard, i);
                break;
            case FirstLevelState:
                if (event.type == sf::Event::MouseMoved)
                    if (exitFromLevelButton.isMouseCover(window))
                        exitFromLevelButton.setBGColor(Menu::bgCover);
                    else exitFromLevelButton.setBGColor(Menu::bgStandard);

                if (event.type == sf::Event::MouseButtonReleased)
                    if (exitFromLevelButton.isMouseCover(window))
                        if (event.mouseButton.button == sf::Mouse::Left)
                                state = MainMenuState;
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
        case LevelMenuState:
            levelMenu.drawMenu(window);
            break;
        case FirstLevelState:
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