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

void Objective::checkWin() {
    int checked = 0;
    for(i = 0;i<amount;i++) {
        if(map.search(posX[i], posY[i]) == 2) {
            checked++;
        }
    }
    if(checked == amount) {
        hasWon = true;
    }
}

void Objective::showWin() {
    if(hasWon) {
        font.loadFromFile("fonts/Ubuntu-Regular.ttf");
        text.setFont(font);
        text.setString("Voce ganhou");
        text.setCharacterSize(100);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(sf::Vector2f(170.f,370.f));
        window.draw(text);
    }
}
bool Objective::check(unsigned int x, unsigned int y) {
    for(unsigned int i = 0;i<posX.size();i++){
        if(posX[i] == x and posY[i] == y) { return true; }
    }
    return false;
}

bool Objective::getHasWon() { 
    if(hasWon){
        return true;
    }
    return false;
}