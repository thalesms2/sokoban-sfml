#include "header.h"
#include "box.cpp"
#include "blank.cpp"
#include "objective.cpp"
#include "player.cpp"
#include "wall.cpp"

Map::Map() {
    texture.loadFromFile("sprites/sprite.png");
    getFromFile("levels/level1.txt");
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

void Map::getFromFile(std::string name) {
    int counter = 0;
    char inputChar = ' ';
    file.open(name);
    while(file.get(inputChar)) {
        grid[counter/15][counter%15] = inputChar - '0'; 
        counter++;
    }
    file.close();
}

void Map::make() {
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            switch(grid[i][j]) {
            case 0:      
                map[i][j] = blank.getBlank();                                                          
                map[i][j].setPosition(sf::Vector2f(j*64.f,i*64.f));
                break;
            case 1:
                map[i][j] = wall.getWall();
                map[i][j].setPosition(sf::Vector2f(j*64.f,i*64.f));
                break;
            case 2:
                map[i][j] = box.getBox();
                map[i][j].setPosition(sf::Vector2f(j*64.f,i*64.f));
                if(obj.check(j,i)) { map[i][j].setColor(sf::Color(255, 255, 255, 128)); }
                break;
            case 3:
                objBg[i][j] = obj.getObj();
                objBg[i][j].setPosition(sf::Vector2f(j*64.f,i*64.f));
                grid[i][j] = 0;
                obj.added(j, i);
                break;
            case 4:
                map[i][j] = player.getPlayer();
                map[i][j].setPosition(sf::Vector2f(j*64.f,i*64.f));
                player.setPos(j, i);
                break;
            }
        }
    }
}

void Map::show() {
    make();
    obj.checkWin();
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
            window.draw(map[i][j]);
        }
    }
}

int Map::search(unsigned int x, unsigned int y) { return grid[y][x]; }

void Map::change(unsigned int x, unsigned int y, int thing) { grid[y][x] = thing; }