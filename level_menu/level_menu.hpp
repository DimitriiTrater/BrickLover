#ifndef LEVELMENU_HPP
#define LEVELMENU_HPP

class LevelMenu
{
private:
    int countOfButtons = 5;
    Button levels[5];

public:
    LevelMenu(Button lvl1, Button lvl2, Button lvl3, Button lvl4, Button lvl5);
    

    void setAllButtonsBackground(const sf::Color& color);
    void setAnyButtonsBackground(const sf::Color& color, int index);
    void setButtonsLevelPosition(const int WIDTH, const int HEIGHT, int buttonsW, int buttonsH);
    void setButtonsLevelFont(const sf::Font& font);
    
    bool isCoverButton(sf::RenderWindow& window, int index) const;
    void drawMenu(sf::RenderWindow& window);


};

#endif /* LEVELMENU_HPP */