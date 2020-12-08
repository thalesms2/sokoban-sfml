#include "header.h"

Player::Player() {
    texture.loadFromFile("sprites/sprite.png");
    player.setTexture(texture);
    player.setTextureRect(sf::IntRect(0*offset, 5*offset, offset, offset));
}

sf::Sprite Player::getPlayer(){ return player; }

void Player::setPos(unsigned int x, unsigned int y) { 
    posX = x;
    posY = y;
}

void Player::moveLeft(unsigned int con) {
    player.setTextureRect(sf::IntRect((3+con)*offset, 7*offset, offset, offset));
    if(posX>0) {
        if(map.search(posX-1, posY) == 0){
            map.change(posX, posY, 0);
            map.change(posX-1, posY, 4);
        }else if(map.search(posX-1, posY) == 2) {
            if(map.search(posX-2, posY) == 0) {
                map.change(posX, posY, 0);
                map.change(posX-1, posY, 4);
                map.change(posX-2, posY, 2);
            }
        }
    }
}

void Player::moveRight(unsigned int con) {
    player.setTextureRect(sf::IntRect((0+con)*offset, 7*offset, offset, offset));
    if(posX<size) {
        if(map.search(posX+1, posY) == 0){
            map.change(posX, posY, 0);
            map.change(posX+1, posY, 4);
        }else if(map.search(posX+1, posY) == 2) {
            if(map.search(posX+2, posY) == 0) {
                map.change(posX, posY, 0);
                map.change(posX+1, posY, 4);
                map.change(posX+2, posY, 2);
            }
        }
    }
}

void Player::moveUp(unsigned int con) {
    player.setTextureRect(sf::IntRect((3+con)*offset, 5*offset, offset, offset));
    if(posY>0) {
        if(map.search(posX, posY-1) == 0){
            map.change(posX, posY, 0);
            map.change(posX, posY-1, 4);
        }else if(map.search(posX, posY-1) == 2) {
            if(map.search(posX, posY-2) == 0) {
                map.change(posX, posY, 0);
                map.change(posX, posY-1, 4);
                map.change(posX, posY-2, 2);
            }
        }
    }
}

void Player::moveDown(unsigned int con) {
    player.setTextureRect(sf::IntRect((0+con)*offset, 5*offset, offset, offset));
    if(posX<size) {
        if(map.search(posX, posY+1) == 0){
            map.change(posX, posY, 0);
            map.change(posX, posY+1, 4);
        }else if(map.search(posX, posY+1) == 2) {
            if(map.search(posX, posY+2) == 0) {
                map.change(posX, posY, 0);
                map.change(posX, posY+1, 4);
                map.change(posX, posY+2, 2);
            }
        }
    }
}