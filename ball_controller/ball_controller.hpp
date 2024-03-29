#ifndef BALLCONTROLLER_HPP
#define BALLCONTROLLER_HPP


class BallController
{
private:
    sf::Keyboard::Key start;
    Ball* ball;
    Player* player;
    bool stateOfLive = false;
    float dx = -1; // x speed
    float dy = -1; // y speed

    void collisionWithBoard();
    void collisionWithPlayer();
    void startLive();

    int lives = 3;


public:
    BallController(Ball& ball, sf::Keyboard::Key start);

    int getLives() const;
    void setPlayer(Player& player);
    void move();
};


#endif /* BALLCONTROLLER_HPP */