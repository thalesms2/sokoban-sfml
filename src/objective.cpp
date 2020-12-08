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
    qntObj++;
}

void Objective::win() {
    for(i = 0;i<qntObj;i++) {
        if(map.search(posX[i], posY[i]) == 2) {
            qntBoxOnObj++;
        }
    }
    if(qntBoxOnObj == qntObj) {
        std::cout << "Ganhou" << std::endl;
    }
    qntBoxOnObj = 0;
}

bool Objective::test(unsigned int x, unsigned int y) {
    for(unsigned int i = 0;i<posX.size();i++){
        if(posX[i] == x and posY[i] == y) { return true; }
    }
    return false;
}