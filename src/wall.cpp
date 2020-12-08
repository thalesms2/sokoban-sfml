#include "header.h"

Wall::Wall() {
    texture.loadFromFile("sprites/sprite.png");
    wall.setTexture(texture);
    wall.setTextureRect(sf::IntRect(10*offset, 0*offset, offset, offset));
}

sf::Sprite Wall::getWall(){ return wall; }