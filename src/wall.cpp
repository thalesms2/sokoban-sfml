#include "header.h"

Wall::Wall() {
    if (!texture.loadFromFile("sprites/sprite.png")){
        std::cout << "error from load texture!";
    }
    wall.setTexture(texture);
    wall.setTextureRect(sf::IntRect(6*offset, 7*offset, offset, offset));
}
sf::Sprite Wall::getWall(){ return wall; }