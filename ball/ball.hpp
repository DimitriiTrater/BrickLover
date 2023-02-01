#ifndef BALL_HPP
#define BALL_HPP

class Ball
{

private:
    float x;  // x spawn point ball
    float y;  // y spawn point ball
    float dx; // x speed
    float dy; // y speed
    float r;  // radius ball

public:
    Ball(float x, float y, float r);
    
    void setX  (float x);
    void setDX (float dx);

    void setY  (float y);
    void setDY (float dy);


    float getX();
    float getDX();

    float getY();
    float getDY();
    
    float getR();


};

#endif /* Ball_HPP */