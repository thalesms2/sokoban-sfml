#include "header.h"

Objective::Objective() {
    texture.loadFromFile("sprites/sprite.png");
    obj.setTexture(texture);
    obj.setTextureRect(sf::IntRect(0*offset, 3*offset, offset, offset));
}

sf::Sprite Objective::getObj() { return obj; }

void Objective::added(unsigned int x, unsigned int y) {
    posX.push_back(x);
    posY.push_back(y);
    amount++;
}

void Objective::win() {
    int checked = 0;
    for(i = 0;i<amount;i++) {
        if(map.search(posX[i], posY[i]) == 2) {
            checked++;
        }
    }
    if(checked == amount) {
        std::cout << "Ganhou" << std::endl;
    }
}

bool Objective::check(unsigned int x, unsigned int y) {
    for(unsigned int i = 0;i<posX.size();i++){
        if(posX[i] == x and posY[i] == y) { return true; }
    }
    return false;
}