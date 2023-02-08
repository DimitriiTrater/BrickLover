#include <SFML/Graphics.hpp>
#include "../button/button.hpp"
#include "menu.hpp"


Menu::Menu(Button startButton, Button levelsButton, Button quitButton)
{
    this->buttons[0] = startButton;
    this->buttons[1] = levelsButton;
    this->buttons[2] = quitButton;

}


void Menu::setButtonsMenuFont(const sf::Font& font)
{
    for (int i = 0; i < 3; i++)
        this->buttons[i].setFont(font);
}


void Menu::setButtonsMenuNormalBackground(const sf::Color& color)
{
    for (int i = 0; i < 3; i++)
        this->buttons[i].setBGColor(color);
}

void Menu::setButtonsMenuCoverBackground(const sf::Color& color, int index)
{this->buttons[index].setBGColor(color);}


void Menu::setButtonsMenuPosition()
{
    float i = 200;
    int plis = 100;
    for (int j = 0; j < 3; j++)
    {
        buttons[j].setPosition({300, i});
        i += plis;
    }
}


void Menu::drawMenu(sf::RenderWindow& window)
{
    for (int i = 0; i < 3; i++)
        this->buttons[i].drawButton(window);
}

bool Menu::isCoverButton(sf::RenderWindow& window,int index) const
{
    return buttons[index].isMouseCover(window);
}




const sf::Color Menu::bgStandard = sf::Color::White;
const sf::Color Menu::bgCover    = sf::Color(160, 160, 160);
const sf::Color Menu::bgClicked  = sf::Color( 96,  96,  96);