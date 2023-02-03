#include <SFML/Graphics.hpp>
#include "font/sansation.hpp"
#include "button/button.hpp"


int main(int argc, char* argv[])
{
    const double width = 800;
    const double height = 800;

    sf::Font font;
    font.loadFromMemory(&sansation_ttf, sansation_ttf_len);

    sf::RenderWindow window(sf::VideoMode(width, height), "BrickLover");


    return 0;
}