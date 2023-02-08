#include <SFML/Graphics.hpp>
#include "../button/button.hpp"

#include "level_menu.hpp"

LevelMenu::LevelMenu(Button lvl1, Button lvl2, Button lvl3, Button lvl4, Button lvl5)
:  levels{lvl1, lvl2, lvl3, lvl4, lvl5}
{}

void LevelMenu::setAllButtonsBackground(const sf::Color& color)
{
        for (int i = 0; i < countOfButtons; i++)
            this->levels[i].setBGColor(color);
}

void LevelMenu::setAnyButtonsBackground(const sf::Color& color, int index)
{this->levels[index].setBGColor(color);}

void LevelMenu::setButtonsLevelPosition(const int WIDTH, const int HEIGHT, int buttonsW, int buttonsH)
{
    int buttonWidth  = WIDTH  / 4 - buttonsW;
    int buttonHeight = HEIGHT / 4 - buttonsH;

    for (int i = 0; i < countOfButtons; i++)
    {
        levels[i].setPosition({(float)buttonWidth, (float)buttonHeight});
        buttonWidth += 100;
    }
}

void LevelMenu::setButtonsLevelFont(const sf::Font& font)
{
    for (int i = 0; i < countOfButtons; i++)
        this->levels[i].setFont(font);
}


void LevelMenu::drawMenu(sf::RenderWindow& window)
{
    for (int i = 0; i < countOfButtons; i++)
        this->levels[i].drawButton(window);
}

bool LevelMenu::isCoverButton(sf::RenderWindow& window,int index) const
{
    return levels[index].isMouseCover(window);
}