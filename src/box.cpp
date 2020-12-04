#include "header.h"

Box::Box() {
    if (!texture.loadFromFile("sprites/sprite.png")){
        std::cout << "error from load texture!";
    }
    box.setTexture(texture);
    box.setTextureRect(sf::IntRect(6*offset, 0*offset, offset, offset));
}
sf::Sprite Box::getBox(){ return box; }
void Box::addedBox(unsigned int x, unsigned int y) { 
    qntBox++; 
    posX.push_back(x);
    posY.push_back(y);
}
bool Box::checkCollision(unsigned int x,unsigned int y) {
    for(int i = 0;i<posX.size();i++){
        if(posX[i] == x and posY[i] == y){
            return true;
        }
    }
    return false;
}