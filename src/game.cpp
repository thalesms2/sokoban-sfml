#include "map.cpp"

int game() {
    while (window.isOpen()) {
        window.setFramerateLimit(60);
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::A) {
                    player.moveLeft(counter);
                }
                if (event.key.code == sf::Keyboard::Left) {
                    player.moveLeft(counter);
                }
                if (event.key.code == sf::Keyboard::D) {
                    player.moveRight(counter);
                }
                if (event.key.code == sf::Keyboard::Right) {
                    player.moveRight(counter);
                }
                if (event.key.code == sf::Keyboard::W) {
                    player.moveUp(counter);
                }
                if (event.key.code == sf::Keyboard::Up) {
                    player.moveUp(counter);
                }
                if (event.key.code == sf::Keyboard::S) {
                    player.moveDown(counter);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    player.moveDown(counter);
                }
                if (event.key.code == sf::Keyboard::R) {
                    map.getFromFile("levels/level1.txt");
                }
                counter = (counter + 1) % 3;
            default:
                break;
            }
        }
        window.clear();
        map.show();
        window.display();
    }
    return 0;
}
