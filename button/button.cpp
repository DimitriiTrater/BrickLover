#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.hpp"


Button::Button()
{}

Button::Button(std::string text, sf::Vector2f size, sf::Color bgNormal, sf::Color textNormal)
{
    this->text.setString(text);
    this->textNormal = textNormal;
    this->text.setColor(this->textNormal);

    this->button.setSize(size);
    this->bgNormal = bgNormal;
    this->button.setFillColor(this->bgNormal);


}
