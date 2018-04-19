/**************************************************
 * Program Name: character.hpp
 * Author George Lenz
 * Date: 3/18/2018
 * Description: Header file for character class
**************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include "spaces.hpp"
using namespace std;

class Character
{
private:
string charLeft;
string charRight;
string charUpDown;
int health;
int row;
int column;
string previous;
int currentSpace;
int key1;
int key2;
int key3;
int key4;
int key5;
int woodStake;
int shield;
int garlic;

public:
Character()
{
 
    charLeft = "<(<)";
    charRight = "(>)>";
    charUpDown = "<()>";
    row = 0;
    column = 0;
    previous = "....";
    currentSpace = 1;
    key1 = 0;
    key2=0;
    key3=0;
    key4=0;
    key5=0;
    health = 1000;
  
}
~Character(){};
string getCharLeft()
{
    return charLeft;
}

string getCharRight()
{
    return charRight;
}

string getCharUpDown()
{
    return charUpDown;
}

int getHealth()
{
    return health;
}
int getRow()
{
    return row;
}

int getColumn()
{
    return column;
}

string getPrevious()
{
    return previous;
}

int getCurrentSpace()
{
    return currentSpace;
}

int getKey1()
{
    return key1;
}

int getKey2()
{
    return key2;
}
int getKey3()
{
    return key3;
}
int getKey4()
{
    return key4;
}
int getKey5()
{
    return key5;
}

void setHealth(int aNum)
{
    health = aNum;
}

void setKey1(int aNum)
{
    key1 = aNum;
}
void setKey2(int aNum)
{
    key2 = aNum;
}
void setKey3(int aNum)
{
    key3 = aNum;
}
void setKey4(int aNum)
{
    key4 = aNum;
}
void setKey5(int aNum)
{
    key5 = aNum;
}
void setRow(int aRow)
{
    row = aRow;
}

void setColumn(int aColumn)
{
    column = aColumn;
}

void setPrevious(string aString)
{
    previous = aString;
}

void setCurrentSpace(int aSpace)
{
    currentSpace = aSpace;
}

void setWoodStake()
{
    woodStake = 1;
}

void setGarlic()
{
    garlic = 1;
}
//inflict damage
int attack()
{
    if(woodStake == 1)
    {
        return 20;
    }

    else
    {
        return 10;
    }
}
//Take damage
void defend(int attack)
{
    if(garlic == 1)
    {    
        health = health - (attack-5);
    }
    else
    {
        health = health - attack;
    }
}
//reset player information
void reset()
{
    health = 1000;
    key1 = 0;
    key2 = 0;
    key3 = 0;
    key4 = 0;
    key5 = 0;
    currentSpace = 1;
    previous = "....";
    row = 0;
    column = 0;
}
};
#endif
