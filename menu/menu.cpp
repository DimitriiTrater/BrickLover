#include <SFML/Graphics.hpp>
#include "../button/button.hpp"
#include "menu.hpp"



Menu::Menu()
{
}


Menu::Menu(Button startButton, Button levelsButton, Button quitButton)
{
    this->buttons[0] = startButton;
    this->buttons[1] = levelsButton;
    this->buttons[2] = quitButton;

}


void Menu::setButtonsFont(const sf::Font& font)
{
    for (int i = 0; i < countOfButtons; i++)
        this->buttons[i].setFont(font);
}


void Menu::setAllButtonsBackground(const sf::Color& color)
{
    for (int i = 0; i < countOfButtons; i++)
        this->buttons[i].setBGColor(color);
}

void Menu::setAnyButtonsBackground(const sf::Color& color, int index)
{this->buttons[index].setBGColor(color);}


void Menu::setButtonsPosition(const int WIDTH, const int HEIGHT, int buttonsW, int buttonsH)
{
    int buttonWidth  = WIDTH  / 2 - buttonsW / 2;
    int buttonHeight = HEIGHT / 4 - buttonsH;
    
    for (int i = 0; i < countOfButtons; i++)
    {
        buttons[i].setPosition({(float)buttonWidth, (float)buttonHeight});
        buttonHeight += 300;
    }
}


void Menu::drawMenu(sf::RenderWindow& window)
{
    for (int i = 0; i < countOfButtons; i++)
        this->buttons[i].drawButton(window);
}

bool Menu::isCoverButton(sf::RenderWindow& window,int index) const
{
    return buttons[index].isMouseCover(window);
}




const sf::Color Menu::bgStandard = sf::Color::White;
const sf::Color Menu::bgCover    = sf::Color(160, 160, 160);
const sf::Color Menu::bgClicked  = sf::Color( 96,  96,  96);