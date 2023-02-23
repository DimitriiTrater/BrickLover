#ifndef BALL_HPP
#define BALL_HPP

class Ball
{

private:

    sf::CircleShape ballShape;
    float x;  // x spawn point ball
    float y;  // y spawn point ball
    float r;  // radius ball
    float restriction[2]; // restriction

public:
    Ball(float x, float y, float r, sf::Color color);
    
    void setX  (float x);
    // void setDX (float dx);

    void setY  (float y);
    // void setDY (float dy);

    void setRestriction (float restriction, int index);

    void setPosition (sf::Vector2f pos);


    float getX();
    // float getDX();

    float getY();
    // float getDY();

    float getShapeX();

    float getShapeY();

    float getR();

    float getRestriction(int index);

    void move(float x, float y);
    void drawBall(sf::RenderWindow& window);


};

#endif /* Ball_HPP */