/***************************************************
 * Program name: spaces.hpp
 * Author: George Lenz
 * Date: 3/18/2018
 * Description: header file for virtual spaces class
*****************************************************/
#ifndef SPACES_HPP
#define SPACES_HPP
#include<iostream>
#include "character.hpp"
#include <string>
using namespace std;
class Spaces
{
protected:
Spaces* top;
Spaces* bottom;
Spaces* left;
Spaces* right;
Character* player;
string** boardPtr;
int width;
int height;
int number;
public:
Spaces()
{
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    player = nullptr;
    width = 20;
    height = 24;
    number = 0;
    boardPtr = new string*[height];
   

    for(int i=0; i<height; i++)
    {
        boardPtr[i] = new string[width];
    }

    
}

~Spaces()
{
   for(int i=0; i<height; i++)
   {
       delete [] boardPtr[i];
   }
   delete [] boardPtr;
};
Spaces* getTop()
{
    return top;
}

Spaces* getBottom()
{
    return bottom;
}

Spaces* getLeft()
{
    return left;
}

Spaces* getRight()
{
    return right;
}

Character* getPlayer()
{
    return player;
}
int getWidth()
{
    return width;
}
int getHeight()
{
    return height;
}

int getNumber()
{
    return number;
}

string** getBoardPtr()
{
    return boardPtr;
}

void setTop(Spaces* aSpace)
{
    top = aSpace;
}

void setBottom(Spaces* aSpace)
{
    bottom = aSpace;
}

void setLeft(Spaces* aSpace)
{
    left = aSpace;
}

void setRight(Spaces* aSpace)
{
    right = aSpace;
}

void printSpaces()
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            cout << boardPtr[i][j];
        }
        cout << endl;
    }
}

void placeChar(string aString)
{   
    boardPtr[player->getRow()][player->getColumn()] = aString;
}

void nextSpace(Spaces* aSpace)
{
    aSpace->placeChar(player->getCharUpDown());
    player->setCurrentSpace(aSpace->getNumber());
}

    

virtual void movePlayer(char& aChar) = 0;

};
#endif
