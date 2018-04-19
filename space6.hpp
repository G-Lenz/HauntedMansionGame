/**************************************************
 * Program Name: Space6.hpp
 * Author: George Lenz
 * Date: 3/18/2018
 * Description: Header file for space6.
***************************************************/
#ifndef SPACE6_HPP
#define SPACE6_HPP
#include <string>
#include <iostream>
#include "spaces.hpp"
#include "character.hpp"
using namespace std;
class Space6 : public Spaces
{
private:
string health = " ++ ";

public:
Space6(Character* aChar) : Spaces()
{
    number = 6;
    player = aChar;
    for(int i=0; i<24; i++)
    {
        for(int j=0; j<20; j++)
        {
            boardPtr[i][j] = "[][]";
        }
    }
    boardPtr[0][10] = "^()^";
    boardPtr[23][10] = "||||";
}

void movePlayer(char& aChar);



};
#endif
