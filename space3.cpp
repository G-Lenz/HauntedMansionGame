/********************************************************
 * Program Name: space3.cpp
 * Author: George Lenz
 * Date: 03/18/2018
 * Description: Implementation file for space3 class
********************************************************/
#include <iostream>
#include <string>
#include "space3.hpp"
#include "spaces.hpp"
#include "character.hpp"
using namespace std;
void Space3::movePlayer(char& aChar)
{
    
    if(aChar == 'w')
     {
         if(player->getRow() == 0)
         {
             return;
         }  
         boardPtr[player->getRow()][player->getColumn()]=player->getPrevious();
         player->setRow(player->getRow()-1);
         player->setPrevious(boardPtr[player->getRow()][player->getColumn()]);
         placeChar(player->getCharUpDown());
     }
     if(aChar == 's')
     {
         if(player->getRow() == 23)
         {
             return;
         }
         boardPtr[player->getRow()][player->getColumn()]=player->getPrevious();
         player->setRow(player->getRow()+1);
         player->setPrevious(boardPtr[player->getRow()][player->getColumn()]);
         placeChar(player->getCharUpDown());
     }
     if(aChar == 'd')
     {
         if(player->getColumn() == 19)
         {
           return;
         }
         boardPtr[player->getRow()][player->getColumn()]=player->getPrevious();
         player->setColumn(player->getColumn() + 1);
         player->setPrevious(boardPtr[player->getRow()][player->getColumn()]);
         placeChar(player->getCharRight());
     }
     if(aChar == 'a')
     {
         if(player->getColumn() == 0)
         {
            if(player->getRow() == 12)
            {
                player->setColumn(19);
                player->setRow(12);
                player->setPrevious("..||");
                nextSpace(left);
                return;
                 
            }
 
 
            return;
         }
         boardPtr[player->getRow()][player->getColumn()]=player->getPrevious();
         player->setColumn(player->getColumn() -1);
         player->setPrevious(boardPtr[player->getRow()][player->getColumn()]);
         placeChar(player->getCharLeft());
     }
   

}

void Space3::printa(int arow, int acolumn)
{
    cout << boardPtr[arow][acolumn] << endl;
}
