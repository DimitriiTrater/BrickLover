#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:
    Button buttons[3];

public:

    Menu(Button startButton, Button levelsButton, Button quitButton);
    void drawMenu(sf::RenderWindow& window);

    void setButtonsMenuNormalBackground(const sf::Color& color);
    void setButtonsMenuCoverBackground(const sf::Color& color, int index);
    void setButtonsMenuPosition();
    void setButtonsMenuFont(const sf::Font& font);

    bool isCoverButton(sf::RenderWindow& window, int index) const;
    
    static const sf::Color bgStandard;
    static const sf::Color bgCover;
    static const sf::Color bgClicked;

};

#endif /* MENU_HPP */
