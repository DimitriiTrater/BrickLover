#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button
{
private:

    sf::RectangleShape button;

    sf::Color bgNormal;
    sf::Color bgHover;
    sf::Color bgClicked;

    sf::Color textNormal;
    sf::Color textHover;
    sf::Color textClicked;

    sf::Text text;

public:
    Button();

    Button(std::string text, sf::Vector2f size, sf::Color bgNormal, sf::Color textNormal);


};


#endif /* BUTTON_HPP */