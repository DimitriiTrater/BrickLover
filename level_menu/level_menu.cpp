#include <SFML/Graphics.hpp>
#include "../button/button.hpp"
#include "../menu/menu.hpp"

#include "level_menu.hpp"

LevelMenu::LevelMenu(Button lvl1, Button lvl2, Button lvl3, Button lvl4, Button lvl5)
:  levels{lvl1, lvl2, lvl3, lvl4, lvl5}
{}
