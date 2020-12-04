#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>

const int offset = 64;
const int tam = 15;

int i;
int j;



class Player {
private:
    sf::Texture texture;
    sf::Sprite player;
    unsigned int posX = 0;
    unsigned int posY = 0;
    bool moved = false;
public:
    Player();
    sf::Sprite getPlayer();
    void setPos(unsigned int x, unsigned int y);
    void moveLeft(unsigned int con);
    void moveRight(unsigned int con);
    void moveUp(unsigned int con);
    void moveDown(unsigned int con);
    bool att();
    unsigned int getPosX();
    unsigned int getPosY();
};

class Box {
private:
    sf::Texture texture;
    sf::Sprite box;
    std::vector<unsigned int> posX;
    std::vector<unsigned int> posY;
    unsigned int qntBox = 0;
public:
    Box();
    sf::Sprite getBox();
    void addedBox(unsigned int x, unsigned int y);
    bool checkCollision(unsigned int x,unsigned int y);
};

class Blank {
private:
    sf::Texture texture;
    sf::Sprite blank;
public:
    Blank();
    sf::Sprite getBlank();
};

class Objective {
private:
    sf::Texture texture;
    sf::Sprite obj;
    std::vector<unsigned int> posX;
    std::vector<unsigned int> posY;
public:
    Objective();
    sf::Sprite getObj();
};

class Wall {
private:
    sf::Texture texture;
    sf::Sprite wall;
public:
    Wall();
    sf::Sprite getWall();
};

class Mapa {
private:
    std::vector<unsigned int> playerPos;
    sf::Texture texture;
    sf::Sprite mapa[tam][tam];
    sf::Sprite bg[tam][tam];
public:
    int projMap[tam][tam] ={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,
                             0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,
                             0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,
                             0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,
                             0,0,0,1,0,0,0,3,0,2,0,1,0,0,0,
                             0,0,0,1,0,4,0,0,0,0,0,1,0,0,0,
                             0,0,0,1,0,0,0,3,0,2,0,1,0,0,0,
                             0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,
                             0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,
                             0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Mapa();
    void att();
    void showMap();
    void background();
    void makeMap();
    int seach(unsigned int x, unsigned y);
    void changeDirect(unsigned int x, unsigned int y, int thing);
};

Player player;
Blank blank;
Box box;
Objective obj;
Wall wall;
Mapa map;
sf::Vector2f canvas(1260,960);
sf::VideoMode display(1260, 960);
sf::RenderWindow window(display, "Sokoban");
sf::RectangleShape shape(canvas);
unsigned int counter;
