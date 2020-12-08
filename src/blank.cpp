#include "header.h"

Blank::Blank() {
    texture.loadFromFile("sprites/sprite.png");
    blank.setTexture(texture);
    blank.setTextureRect(sf::IntRect(0*offset, 0*offset, offset, offset));
}

sf::Sprite Blank::getBlank(){ return blank; }