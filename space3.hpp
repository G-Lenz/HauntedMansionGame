/**************************************************
 * Program Name: Space3.hpp
 * Author: George Lenz
 * Date: 3/18/2018
 * Description: Header file for space3.
***************************************************/
#ifndef SPACE3_HPP
#define SPACE3_HPP
#include <string>
#include <iostream>
#include "spaces.hpp"
#include "character.hpp"
using namespace std;
class Space3 : public Spaces
{
private:
string health = " ++ ";

public:
Space3(Character* aChar) : Spaces()
{
    number = 3;
    player = aChar;
    for(int i=0; i<24; i++)
    {
        for(int j=0; j<20; j++)
        {
            boardPtr[i][j] = "~~~~";
        }
    }
    boardPtr[12][0] = "||";
}

void movePlayer(char& aChar);
void printa(int, int);



};
#endif
