#include <SFML/Graphics.hpp>
#include <iostream>
#include "font/sansation.hpp"
#include "button/button.hpp"
#include "menu/menu.hpp"
#include "level_menu/level_menu.hpp"





int main(int argc, char* argv[])
{
    // full hd
    const double WIDTH  = 1920;
    const double HEIGHT = 1080;

    sf::Font font;
    font.loadFromMemory(&sansation_ttf, sansation_ttf_len);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "BrickLover", sf::Style::Fullscreen);

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

    float levelW = 70;
    float levelH = 70;

    LevelMenu levelMenu(
        Button("1", {levelW, levelH}, charSize, sf::Color::White, sf::Color::Black),
        Button("2", {levelW, levelH}, charSize, sf::Color::White, sf::Color::Black),
        Button("3", {levelW, levelH}, charSize, sf::Color::White, sf::Color::Black),
        Button("4", {levelW, levelH}, charSize, sf::Color::White, sf::Color::Black),
        Button("<-", {levelW, levelH}, charSize, sf::Color::White, sf::Color::Black)
    );

    bool levelMenuIsOpen = false;

    levelMenu.setButtonsLevelFont(font);
    levelMenu.setButtonsLevelPosition(WIDTH, HEIGHT, buttonsW, buttonsH);


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();

            // mouse click
            if (event.type == sf::Event::MouseButtonReleased)
            {
                // start game
                if (mainMenu.isCoverButton(window, 0))
                    if (event.mouseButton.button == sf::Mouse::Left)
                        mainMenu.setAnyButtonsBackground(Menu::bgClicked, 0); // TODO: launch first level

                // open levels
                if (mainMenu.isCoverButton(window, 1))
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        mainMenu.setAnyButtonsBackground(Menu::bgClicked, 1);
                        levelMenuIsOpen = true;
                    }

                // quit
                if (mainMenu.isCoverButton(window, 2))
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        mainMenu.setAnyButtonsBackground(Menu::bgClicked, 2);
                        window.close();    
                    }


                if (levelMenuIsOpen)
                    if (levelMenu.isCoverButton(window, 4))
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {
                            levelMenu.setAnyButtonsBackground(Menu::bgClicked, 4);
                            levelMenuIsOpen = false;
                        }

                    //TODO: create levels

            }

            // for cover
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
            
                if (levelMenuIsOpen)
                    for (int i = 0; i < 5; i++)
                        if (levelMenu.isCoverButton(window, i))
                            levelMenu.setAnyButtonsBackground(Menu::bgCover, i);
                        else levelMenu.setAnyButtonsBackground(Menu::bgStandard, i);

            }   
        
        }    
        window.clear();

        if (!levelMenuIsOpen)
            mainMenu.drawMenu(window);
        if (levelMenuIsOpen)
            levelMenu.drawMenu(window);
        
        window.display();
    }
    return 0;
}