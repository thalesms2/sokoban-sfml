#ifndef GAME_H
#include <SFML/Graphics.hpp>
#define GAME_H
    namespace game {
        sf::Vector2f canvas(600,600);
        sf::VideoMode display(800, 800);
        sf::RenderWindow window(display, "Sokoban");
        sf::RectangleShape shape(game::canvas);
    }
    
#endif