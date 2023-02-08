#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button
{
private:

    sf::RectangleShape button;

    sf::Color bgColor;

    sf::Color textColor;

    sf::Text text;

public:
    Button(std::string text, sf::Vector2f buttonSize, int characterSize, sf::Color bgNormal, sf::Color textNormal);

    void setFont(const sf::Font& font);

    void setBGColor(const sf::Color& color);

    void setTextColor(const sf::Color& color);

    void setPosition(const sf::Vector2f& position);

    void drawButton(sf::RenderWindow& window);

    bool isMouseCover(const sf::RenderWindow& window) const;

};


#endif /* BUTTON_HPP */