#include <SFML/Graphics.hpp>
#include "font/sansation.hpp"
#include "button/button.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
    const double width = 800;
    const double height = 600;

    sf::Font font;
    font.loadFromMemory(&sansation_ttf, sansation_ttf_len);

    sf::RenderWindow window(sf::VideoMode(width, height), "BrickLover");
    
    
    
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

            // for quit
            if (event.type == sf::Event::MouseButtonReleased)
                if (quitButton.isMouseCover(window))
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        quitButton.setBGColor(sf::Color(96, 96, 96));
                        window.close();    
                    }


            // for cover
            if (event.type == sf::Event::MouseMoved)
            {
                // start button
                if (startButton.isMouseCover(window))
                    startButton.setBGColor(sf::Color(160, 160, 160));
                else startButton.setBGColor(sf::Color::White);

                // levels button
                if (levelsButton.isMouseCover(window))
                    levelsButton.setBGColor(sf::Color(160, 160, 160));
                else levelsButton.setBGColor(sf::Color::White);


                // quit button
                if (quitButton.isMouseCover(window))
                    quitButton.setBGColor(sf::Color(160, 160, 160));
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