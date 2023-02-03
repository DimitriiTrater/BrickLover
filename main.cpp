#include <SFML/Graphics.hpp>
#include <iostream>
#include "font/sansation.hpp"
#include "button/button.hpp"
#include "menu/menu.hpp"



int main(int argc, char* argv[])
{
    const double WIDTH = 800;
    const double HEIGHT = 600;

    sf::Font font;
    font.loadFromMemory(&sansation_ttf, sansation_ttf_len);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "BrickLover");
    
    Button startButton("Start", {200, 50}, 20, sf::Color::White, sf::Color::Black);
    startButton.setFont(font);
    startButton.setPosition({300, 200});

    Button levelsButton("Levels", {200, 50}, 20, sf::Color::White, sf::Color::Black);
    levelsButton.setFont(font);
    levelsButton.setPosition({300, 300});

    Button quitButton("Quit", {200, 50}, 20, sf::Color::White, sf::Color::Black);
    quitButton.setFont(font);
    quitButton.setPosition({300, 400});



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

                // for open levels
                if (levelsButton.isMouseCover(window))
                    if (event.mouseButton.button == sf::Mouse::Left)
                        levelsButton.setBGColor(Menu::bgClicked);

                // for quit
                if (quitButton.isMouseCover(window))
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
                if (quitButton.isMouseCover(window))
                    quitButton.setBGColor(Menu::bgCover);
                else quitButton.setBGColor(sf::Color::White);
            }   
        }    
        window.clear();

        startButton.drawButton(window);
        levelsButton.drawButton(window);
        quitButton.drawButton(window);
        
        window.display();
    }
    return 0;
}