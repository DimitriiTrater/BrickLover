#include <SFML/Graphics.hpp>
#include <iostream>
#include "font/sansation.hpp"
#include "button/button.hpp"
#include "menu/menu.hpp"


int main(int argc, char* argv[])
{
    const double WIDTH  = 800;
    const double HEIGHT = 600;

    sf::Font font;
    font.loadFromMemory(&sansation_ttf, sansation_ttf_len);
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "BrickLover");
    
    Button startButton("Start", {200, 50}, 20, sf::Color::White, sf::Color::Black);
    Button levelsButton("Levels", {200, 50}, 20, sf::Color::White, sf::Color::Black);
    Button quitButton("Quit", {200, 50}, 20, sf::Color::White, sf::Color::Black);

    Menu mainMenu(
                Button("Start", {200, 50}, 20, sf::Color::White, sf::Color::Black),
                Button("Levels", {200, 50}, 20, sf::Color::White, sf::Color::Black), 
                Button("Quit", {200, 50}, 20, sf::Color::White, sf::Color::Black)
                );

    mainMenu.setButtonsMenuFont(font);
    mainMenu.setButtonsMenuPosition();

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();

            
            if (event.type == sf::Event::MouseButtonReleased)
            {
                // for start game
                if (startButton.isMouseCover(window))
                    if (event.mouseButton.button == sf::Mouse::Left)
                        startButton.setBGColor(Menu::bgClicked);
                        // TODO: launch first level

                // for open levels
                if (levelsButton.isMouseCover(window))
                    if (event.mouseButton.button == sf::Mouse::Left)
                        levelsButton.setBGColor(Menu::bgClicked);
                        // TODO: oepn level menu

                // for quit
                if (mainMenu.isCoverButton(window, 2))
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        quitButton.setBGColor(Menu::bgClicked);
                        window.close();    
                    }
            }

            // for cover
            if (event.type == sf::Event::MouseMoved)
            {
                // start button
                if (startButton.isMouseCover(window))
                    startButton.setBGColor(Menu::bgCover);
                else startButton.setBGColor(sf::Color::White);

                // levels button
                if (levelsButton.isMouseCover(window))
                    levelsButton.setBGColor(Menu::bgCover);
                else levelsButton.setBGColor(sf::Color::White);


                // quit button
                if (mainMenu.isCoverButton(window, 2))
                    mainMenu.setButtonsMenuCoverBackground(Menu::bgCover, 2);
                else mainMenu.setButtonsMenuNormalBackground(sf::Color::White);
            }   
        }    
        window.clear();

        mainMenu.drawMenu(window);
        
        window.display();
    }
    return 0;
}