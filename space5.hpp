/**************************************************
 * Program Name: Space5.hpp
 * Author: George Lenz
 * Date: 3/18/2018
 * Description: Header file for space5.
***************************************************/
#ifndef SPACE5_HPP
#define SPACE5_HPP
#include <string>
#include <iostream>
#include "spaces.hpp"
#include "character.hpp"
using namespace std;
class Space5 : public Spaces
{
private:
string health = " ++ ";

public:
Space5(Character* aChar) : Spaces()
{
    number = 5;
    player = aChar;
    for(int i=0; i<24; i++)
    {
        for(int j=0; j<20; j++)
        {
            boardPtr[i][j] = "    ";
        }
    }
    boardPtr[0][10] = " || ";
    boardPtr[23][10] = " || ";
}

void movePlayer(char& aChar);



};
#endif
