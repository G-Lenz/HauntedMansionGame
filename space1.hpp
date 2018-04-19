/**************************************************
 * Program Name: Space1.hpp
 * Author: George Lenz
 * Date: 3/18/2018
 * Description: Header file for space1.
***************************************************/
#ifndef SPACE1_HPP
#define SPACE1_HPP
#include <string>
#include <iostream>
#include "spaces.hpp"
#include "character.hpp"
using namespace std;
class Space1 : public Spaces
{
private:
string key = "O--\"";

public:
Space1(Character* aChar) : Spaces()
{
    number = 1;
    player = aChar;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            boardPtr[i][j] = "....";
        }
    }
    boardPtr[12][0] = "||..";
    boardPtr[12][19] = "..||";
    boardPtr[0][10] = ".||.";
    boardPtr[23][10] = ".||.";
}

string getKey()
{
    return key;
}
void movePlayer(char& aChar);



};
#endif
