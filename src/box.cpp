#include "header.h"

Box::Box() {
    texture.loadFromFile("sprites/sprite.png");
    box.setTexture(texture);
    box.setTextureRect(sf::IntRect(6*offset, 0*offset, offset, offset));
}

sf::Sprite Box::getBox(){ return box; }