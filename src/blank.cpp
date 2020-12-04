#include "header.h"

Blank::Blank() {
    if (!texture.loadFromFile("sprites/sprite.png")){
        std::cout << "error from load texture!";
    }
    blank.setTexture(texture);
    blank.setTextureRect(sf::IntRect(0*offset, 0*offset, offset, offset));
}
sf::Sprite Blank::getBlank(){ return blank; }