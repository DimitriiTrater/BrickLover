#include <SFML/Graphics.hpp>
#include <iostream>
#include "font/sansation.hpp"
#include "button/button.hpp"
#include "menu/menu.hpp"


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

    mainMenu.setButtonsMenuFont(font);
    mainMenu.setButtonsMenuPosition(WIDTH, HEIGHT, buttonsW, buttonsH);




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
                        mainMenu.setAnyButtonsMenuBackground(Menu::bgClicked, 0); // TODO: launch first level

                // open levels
                if (mainMenu.isCoverButton(window, 1))
                    if (event.mouseButton.button == sf::Mouse::Left)
                        mainMenu.setAnyButtonsMenuBackground(Menu::bgClicked, 1); // TODO: oepn level menu
                        

                // quit
                if (mainMenu.isCoverButton(window, 2))
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        mainMenu.setAnyButtonsMenuBackground(Menu::bgClicked, 2);
                        window.close();    
                    }
            }

            // for cover
            if (event.type == sf::Event::MouseMoved)
            {
                // start button
                if (mainMenu.isCoverButton(window, 0))
                    mainMenu.setAnyButtonsMenuBackground(Menu::bgCover, 0);
                else mainMenu.setAnyButtonsMenuBackground(Menu::bgStandard, 0);

                // levels button
                if (mainMenu.isCoverButton(window, 1))
                    mainMenu.setAnyButtonsMenuBackground(Menu::bgCover, 1);
                else mainMenu.setAnyButtonsMenuBackground(Menu::bgStandard, 1);


                // quit button
                if (mainMenu.isCoverButton(window, 2))
                    mainMenu.setAnyButtonsMenuBackground(Menu::bgCover, 2);
                else mainMenu.setAnyButtonsMenuBackground(Menu::bgStandard, 2);
            }   
        
        }    
        window.clear();

        mainMenu.drawMenu(window);
        
        window.display();
    }
    return 0;
}