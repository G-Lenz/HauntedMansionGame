/********************************************************
 * Program Name: space6.cpp
 * Author: George Lenz
 * Date: 03/18/2018
 * Description: Implementation file for space6 class
********************************************************/
#include <iostream>
#include <string>
#include "space6.hpp"
#include "spaces.hpp"
#include "character.hpp"
using namespace std;
void Space6::movePlayer(char& aChar)
{
    
    if(aChar == 'w')
     {
         if(player->getRow() == 0)
         {
            if(player->getColumn() == 10)
            {
                
                return;
                 
            }
 
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
            if(player->getColumn() == 10)
            {
                player->setColumn(10);
                player->setRow(0);
                player->setPrevious(" || ");
                nextSpace(bottom);
                return;
                 
            }
 
 
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
             return;
         }
         boardPtr[player->getRow()][player->getColumn()]=player->getPrevious();
         player->setColumn(player->getColumn() -1);
         player->setPrevious(boardPtr[player->getRow()][player->getColumn()]);
         placeChar(player->getCharLeft());
     }
   

}


