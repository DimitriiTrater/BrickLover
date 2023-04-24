#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:
    int countOfButtons = 2;
    Button buttons[2];

public:

    Menu();
    Menu(Button startButton, Button quitButton);
    void drawMenu(sf::RenderWindow& window);

    void setAllButtonsBackground(const sf::Color& color);
    void setAnyButtonsBackground(const sf::Color& color, int index);
    void setButtonsPosition(const int WIDTH, const int HEIGHT, int buttonsW, int buttonsH);
    void setButtonsFont(const sf::Font& font);

    bool isCoverButton(sf::RenderWindow& window, int index) const;
    
    static const sf::Color bgStandard;
    static const sf::Color bgCover;
    static const sf::Color bgClicked;

};

#endif /* MENU_HPP */
