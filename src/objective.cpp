#include "header.h"

Objective::Objective() {
    if (!texture.loadFromFile("sprites/sprite.png")){
        std::cout << "error from load texture!";
    }
    obj.setTexture(texture);
    obj.setTextureRect(sf::IntRect(0*offset, 3*offset, offset, offset));
}
sf::Sprite Objective::getObj(){ return obj; }
