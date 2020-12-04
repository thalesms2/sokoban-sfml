#include "header.h"

Player::Player() {
    if (!texture.loadFromFile("sprites/sprite.png")){
        std::cout << "error from load texture!";
    }
    player.setTexture(texture);
    player.setTextureRect(sf::IntRect(0*offset, 5*offset, offset, offset));
}

sf::Sprite Player::getPlayer(){ return player; }
void Player::setPos(unsigned int x, unsigned int y) { 
    posX = x;
    posY = y;
}
void Player::moveLeft(unsigned int con) {
    moved = true;
    player.setTextureRect(sf::IntRect((3+con)*offset, 7*offset, offset, offset));
    if(posX>0){
        switch(map.projMap[posY][posX-1]){
        case 0:
            posX--;
            break;
        case 2:
            if(map.projMap[posY][posX-2] == 0){
                posX--;
                map.projMap[posY][posX-1] = 0;
                map.projMap[posY][posX-2] = 2;
            }else if(map.projMap[posY][posX-2] == 3){
                posX--;
                map.projMap[posY][posX-1] = 0;
                map.projMap[posY][posX-2] = 5;
            }
            break;
        case 3:
            posX--;
            map.projMap[posY][posX-1] = 6;
            break;
        default:
            break;
        }
    }
}
void Player::moveRight(unsigned int con) {
    moved = true;
    player.setTextureRect(sf::IntRect((0+con)*offset, 7*offset, offset, offset));
    if(posX<tam-1 and !box.checkCollision(posX+1, posY)){
        posX++;
    }
}
void Player::moveUp(unsigned int con) {
    moved = true;
    player.setTextureRect(sf::IntRect((3+con)*offset, 5*offset, offset, offset));
    if(posY>0 and !box.checkCollision(posX, posY-1)){
        posY--;
    }
}
void Player::moveDown(unsigned int con) {
    moved = true;
    player.setTextureRect(sf::IntRect((0+con)*offset, 5*offset, offset, offset));
    if(posY<tam-1 and !box.checkCollision(posX, posY+1)){
        posY++;
    }
}

bool Player::att() { return moved; }
unsigned int Player::getPosX() { return posX; }
unsigned int Player::getPosY() { return posY; }