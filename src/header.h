#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <fstream>

const int offset = 64;
const int size = 15;

int i;
int j;

class Player {
private:
    sf::Texture texture;
    sf::Sprite player;
    unsigned int posX = 0;
    unsigned int posY = 0;
public:
    Player();
    sf::Sprite getPlayer();
    void setPos(unsigned int x, unsigned int y);
    void moveLeft(unsigned int con);
    void moveRight(unsigned int con);
    void moveUp(unsigned int con);
    void moveDown(unsigned int con);
};

class Box {
private:
    sf::Texture texture;
    sf::Sprite box;
public:
    Box();
    sf::Sprite getBox();
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
    int amount = 0;
    
public:
    Objective();
    sf::Sprite getObj();
    void added(unsigned int x, unsigned int y);
    void win();
    bool check(unsigned int x, unsigned int y);
};

class Wall {
private:
    sf::Texture texture;
    sf::Sprite wall;
public:
    Wall();
    sf::Sprite getWall();
};

class Map {
private:
    sf::Texture texture;
    sf::Sprite map[size][size];
    sf::Sprite background[size][size];
    sf::Sprite objBg[size][size];
    int grid[size][size];
public:
    Map();
    void show();
    void showBackground();
    void getFromFile(std::string name);
    void backup();
    void make();
    int search(unsigned int x, unsigned y);
    void change(unsigned int x, unsigned int y, int thing);
};

std::ifstream file;
Player player;
Blank blank;
Box box;
Objective obj;
Wall wall;
Map map;
sf::Event event;
sf::VideoMode display(size*64, size*64);
sf::RenderWindow window(display, "Sokoban");
sf::Font font;
unsigned int counter;