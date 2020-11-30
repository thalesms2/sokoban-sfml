#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>

int gamefunc() {
    
    sf::Font font;
    if(!font.loadFromFile("Ubuntu-Regular.ttf")) {
        std::cout << "error from load font!";
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Sokoban");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    game::shape.setFillColor(sf::Color::White);

    while (game::window.isOpen()) {
        sf::Event event;
        sf::Sprite player;
        game::window.setFramerateLimit(60);
        player.setColor(sf::Color::Black);
        while (game::window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                game::window.close();
        }
        game::window.clear();
        game::window.draw(game::shape);
        game::window.draw(player);
        game::window.draw(text);
        game::window.display();
    }
    return 0;
}