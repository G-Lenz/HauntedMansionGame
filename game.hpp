/******************************************************************
 * Program Name: game.hpp
 * Author: George Lenz
 * Date: 3/20/2018
 * Description: Header file for game class
 * ***************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include <stdlib.h>
#include "spaces.hpp"
#include "space1.hpp"
#include "character.hpp"
#include "space2.hpp"
#include "space3.hpp"
#include "space4.hpp"
#include "space5.hpp"
#include <queue>
#include "space6.hpp"
#include "dracula.hpp"
#include "validate.hpp"
#include "game.hpp"
//#include "pictures.hpp"
class Game
{

private:

char inputChar;
Character* player;
Dracula* drac;
Space1* lobby;
Space2* courtyard;
Space3* kitchen;
Space4* sauna;
Space5* darkRoom;
Space6* boss; 
queue<int> keys;
queue<int> temp;
int menuChoice;
int loss;

public:
Game()
{
player = new Character();
drac = new Dracula();
lobby = new Space1(player);
courtyard = new Space2(player);
kitchen = new Space3(player);
sauna = new Space4(player);
darkRoom = new Space5(player);
boss = new Space6(player);

lobby->setRight(kitchen);
lobby->setBottom(sauna);
lobby->setTop(darkRoom);
lobby->setLeft(courtyard);
courtyard->setRight(lobby);
kitchen->setLeft(lobby);
sauna->setTop(lobby);
darkRoom->setBottom(lobby);
darkRoom->setTop(boss);
boss->setBottom(darkRoom);

lobby->placeChar(player->getCharUpDown());
menuChoice = 0;
loss = 0;
}

~Game()
{
    delete player;
    delete drac;
    delete lobby;
    delete courtyard;
    delete kitchen;
    delete sauna;
    delete darkRoom;
    delete boss;
}
int getLoss()
{
    return loss;
}
char getInput()
{
    return inputChar;
}
int getMenuChoice()
{
    return menuChoice;
}

Space1* getLobby()
{
    return lobby;
}
void setInputChar(char aChar)
{
    inputChar = aChar;
}
void printMenu();
void printInstruct();
void printSpace();
void userInput();
void stepPenalty();
void move();
void spaceAction();
void printKeys();
void fight();
void healthCheck();
void newGame();
};


#endif
