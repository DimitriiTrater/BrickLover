#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
private:
    sf::RectangleShape playerShape;
    float x;
    float y;
    float restriction;
    sf::Vector2f size;
    
public:
    Player();
    Player(float x, float y, sf::Vector2f size, sf::Color color);



    void setX(float x);
    void setY(float y);
    void setRestriction(float WIDTH);
    // void setPosition(const sf::Vector2f& position);



    float getX();
    float getY();
    float getRestriction();
    float getShapeX();
    float getSizeX(); // get size


    void move(float x);

    void drawPlayer(sf::RenderWindow& window);


};
#endif /* PLAYER_HPP */