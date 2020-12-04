#include "header.h"
#include "box.cpp"
#include "blank.cpp"
#include "objective.cpp"
#include "player.cpp"
#include "wall.cpp"

Mapa::Mapa() {
    if (!texture.loadFromFile("sprites/sprite.png")){
        std::cout << "error from load texture!";
    }
    makeMap();
    background();
}
void Mapa::att() {
    if(player.att()) {
        projMap[playerPos[1]][playerPos[0]] = 0;
        projMap[player.getPosY()][player.getPosX()] = 4;
    }
}
void Mapa::showMap(){
    makeMap();
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            window.draw(bg[i][j]);
        }
    }
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            window.draw(mapa[i][j]);
        }
    }
}
void Mapa::background(){
    for(i = 0; i<tam;i++){
        for(j=0;j<tam;j++){
            bg[i][j].setTexture(texture);
            bg[i][j].setTextureRect(sf::IntRect(11*offset, 6*offset, offset, offset));
            bg[i][j].setPosition(sf::Vector2f(i*64.f,j*64.f));
        }
    }
}
void Mapa::changeDirect(unsigned int x, unsigned int y, int thing) {
    projMap[y][x] = thing;
}
int Mapa::seach(unsigned int x, unsigned y){ return projMap[y][x]; }
void Mapa::makeMap(){
    att();
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            switch(projMap[j][i]){
            case 0:
                mapa[i][j] = blank.getBlank();
                mapa[i][j].setPosition(sf::Vector2f(i*64.f,j*64.f));
                break;
            case 1:
                mapa[i][j] = wall.getWall();
                mapa[i][j].setPosition(sf::Vector2f(i*64.f,j*64.f));
                break;
            case 2:
                mapa[i][j] = box.getBox();
                mapa[i][j].setPosition(sf::Vector2f(i*64.f,j*64.f));
                box.addedBox(i, j);
                break;
            case 3:
                mapa[i][j] = obj.getObj();
                mapa[i][j].setPosition(sf::Vector2f(i*64.f,j*64.f));
                break;
            case 4:
                mapa[i][j] = player.getPlayer();
                mapa[i][j].setPosition(sf::Vector2f(i*64.f,j*64.f));
                if(playerPos.size()<2) {
                    playerPos.push_back(i);
                    playerPos.push_back(j);
                }else{
                    playerPos.clear();
                    playerPos.push_back(i);
                    playerPos.push_back(j);
                }
                player.setPos(i,j);
                break;
            }
        }
    }
}