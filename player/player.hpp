#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
private:
    float x;
    float y;
    float restriction[2];
    
public:
    Player(float x, float y);

    void setX(float x);
    void setY(float y);
    void setRestriction(float restriction, int indexRestriction);

    float getX();
    float getY();
    float getRestriction(int indexRestriction);

};
#endif /* PLAYER_HPP */