class PlayerController
{
private:
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    Player* player;
    float moveSpeed = 10.f; 

    void moveLeft ();
    void moveRight();


public:
    PlayerController();
    PlayerController(Player& player, sf::Keyboard::Key left, sf::Keyboard::Key right);

    void move();
};



