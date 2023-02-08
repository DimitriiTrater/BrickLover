#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:
    Button buttons[3];

public:

    Menu();
    Menu(Button startButton, Button levelsButton, Button quitButton);
    void drawMenu(sf::RenderWindow& window);

    void setAllButtonsMenuBackground(const sf::Color& color);
    void setAnyButtonsMenuBackground(const sf::Color& color, int index);
    void setButtonsMenuPosition(const int WIDTH, const int HEIGHT, int buttonsW, int buttonsH);
    void setButtonsMenuFont(const sf::Font& font);

    bool isCoverButton(sf::RenderWindow& window, int index) const;
    
    static const sf::Color bgStandard;
    static const sf::Color bgCover;
    static const sf::Color bgClicked;

};

#endif /* MENU_HPP */
