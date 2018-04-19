/**************************************************
 * Program Name: Space2.hpp
 * Author: George Lenz
 * Date: 3/18/2018
 * Description: Header file for space2.
***************************************************/
#ifndef SPACE2_HPP
#define SPACE2_HPP
#include <string>
#include <iostream>
#include "spaces.hpp"
#include "character.hpp"
using namespace std;
class Space2 : public Spaces
{
private:
string health = " ++ ";

public:
Space2(Character* aChar) : Spaces()
{
    number = 2;
    player = aChar;
    for(int i=0; i<24; i++)
    {
        for(int j=0; j<20; j++)
        {
            boardPtr[i][j] = "wwww";
        }
    }
    boardPtr[12][19] = "ww||";
}

void movePlayer(char& aChar);
void printa(int, int);



};
#endif
