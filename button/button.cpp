#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.hpp"



Button::Button(std::string text, sf::Vector2f buttonSize, int characterSize, sf::Color bgColor, sf::Color textColor)
{
    this->text.setString(text);
    this->textColor = textColor;
    this->text.setFillColor(this->textColor);
    this->text.setCharacterSize(characterSize);

    this->button.setSize(buttonSize);
    this->bgColor = bgColor;
    this->button.setFillColor(this->bgColor);

}


void Button::setFont(const sf::Font& font)
{
    this->text.setFont(font);
}

void Button::setBGColor(const sf::Color& color)
{
    this->button.setFillColor(color);
}

void Button::setTextColor(const sf::Color& color)
{
    this->text.setFillColor(color);
}

void Button::setPosition(const sf::Vector2f& position)
{
    this->button.setPosition(position);

    float xPosition = (position.x + this->button.getLocalBounds().width / 2) - (this->text.getLocalBounds().width / 2);
    float yPosition = (position.y + this->button.getLocalBounds().height / 2) - (this->text.getLocalBounds().height / 2);
    text.setPosition({ xPosition, yPosition });
}

void Button::drawButton(sf::RenderWindow& window)
{
    window.draw(this->button);
    window.draw(this->text);

}

bool Button::isMouseCover(const sf::RenderWindow& window) const
{
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float buttonPosX = this->button.getPosition().x;
    float buttonPosY = this->button.getPosition().y;

    float buttonXPosWidth = this->button.getPosition().x + this->button.getLocalBounds().width;
    float buttonYPosHeight = this->button.getPosition().y + this->button.getLocalBounds().height;

    if (mouseX < buttonXPosWidth && mouseX > buttonPosX && mouseY < buttonYPosHeight && mouseY > buttonPosY)
        return true;
    return false;

}
