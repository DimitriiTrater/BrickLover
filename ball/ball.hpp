#ifndef BALL_HPP
#define BALL_HPP

class Ball
{

private:

    sf::CircleShape ballShape;
    float x;  // x spawn point ball
    float y;  // y spawn point ball
    float dx = -1; // x speed
    float dy = -1; // y speed
    float r;  // radius ball

public:
    Ball(float x, float y, float r, sf::Color color);
    
    void setX  (float x);
    void setDX (float dx);

    void setY  (float y);
    void setDY (float dy);


    float getX();
    float getDX();

    float getY();
    float getDY();
    
    float getR();

    void drawBall(sf::RenderWindow& window);


};

#endif /* Ball_HPP */