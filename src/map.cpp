#include "header.h"
#include "box.cpp"
#include "blank.cpp"
#include "objective.cpp"
#include "player.cpp"
#include "wall.cpp"

Map::Map() {
    texture.loadFromFile("sprites/sprite.png");
    showBackground();
    make();
}

void Map::showBackground() {
    for(i = 0; i<size;i++) {
        for(j=0;j<size;j++) {
            background[i][j].setTexture(texture);
            background[i][j].setTextureRect(sf::IntRect(11*offset, 6*offset, offset, offset));
            background[i][j].setPosition(sf::Vector2f(i*64.f,j*64.f));
        }
    }
}
void Map::backup() {
    for(i = 0;i<size;i++){
        for(j=0;j<size;j++){
            projMap[i][j] = backupMap[i][j];
        }
    }
}
void Map::make() {
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            switch(projMap[i][j]) {
            case 0:
                mapa[i][j] = blank.getBlank();
                mapa[i][j].setPosition(sf::Vector2f(j*64.f,i*64.f));
                break;
            case 1:
                mapa[i][j] = wall.getWall();
                mapa[i][j].setPosition(sf::Vector2f(j*64.f,i*64.f));
                break;
            case 2:
                mapa[i][j] = box.getBox();
                mapa[i][j].setPosition(sf::Vector2f(j*64.f,i*64.f));
                if(obj.test(j,i)) { mapa[i][j].setColor(sf::Color(255, 255, 255, 128)); }
                break;
            case 3:
                objBg[i][j] = obj.getObj();
                objBg[i][j].setPosition(sf::Vector2f(j*64.f,i*64.f));
                projMap[i][j] = 0;
                obj.added(j, i);
                break;
            case 4:
                mapa[i][j] = player.getPlayer();
                mapa[i][j].setPosition(sf::Vector2f(j*64.f,i*64.f));
                player.setPos(j, i);
                break;
            }
        }
    }
}

void Map::show() {
    make();
    obj.win();
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            window.draw(background[i][j]);
        }
    }
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            window.draw(objBg[i][j]);
        }
    }
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            window.draw(mapa[i][j]);
        }
    }
}

int Map::search(unsigned int x, unsigned int y) { return projMap[y][x]; }

void Map::change(unsigned int x, unsigned int y, int thing) { projMap[y][x] = thing; }