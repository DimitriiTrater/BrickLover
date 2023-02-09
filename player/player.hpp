#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
private:
    sf::RectangleShape playerShape;
    float x;
    float y;
    float restriction;
    
public:
    Player(float x, float y, sf::Vector2f size, sf::Color color);



    void setX(float x);
    void setY(float y);
    void setRestriction(float WIDTH);
    // void setPosition(const sf::Vector2f& position);



    float getX();
    float getY();
    float getRestriction(int indexRestriction);


    void drawPlayer(sf::RenderWindow& window);


};
#endif /* PLAYER_HPP */