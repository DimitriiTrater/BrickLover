#ifndef LEVELMENU_HPP
#define LEVELMENU_HPP

class LevelMenu: public Menu
{
private:
    Button levels[5];

public:
    LevelMenu(Button lvl1, Button lvl2, Button lvl3, Button lvl4, Button lvl5);
};

#endif /* LEVELMENU_HPP */