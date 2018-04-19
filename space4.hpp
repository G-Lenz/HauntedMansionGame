/**************************************************
 * Program Name: Space4.hpp
 * Author: George Lenz
 * Date: 3/18/2018
 * Description: Header file for space4.
***************************************************/
#ifndef SPACE4_HPP
#define SPACE4_HPP
#include <string>
#include <iostream>
#include "spaces.hpp"
#include "character.hpp"
using namespace std;
class Space4 : public Spaces
{
private:
string health = " ++ ";

public:
Space4(Character* aChar) : Spaces()
{
    number = 4;
    player = aChar;
    for(int i=0; i<24; i++)
    {
        for(int j=0; j<20; j++)
        {
            boardPtr[i][j] = "oOoO";
        }
    }
    boardPtr[0][10] = "o||O";
}

void movePlayer(char& aChar);




};
#endif
