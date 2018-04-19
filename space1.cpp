/********************************************************
 * Program Name: space1.cpp
 * Author: George Lenz
 * Date: 03/18/2018
 * Description: Implementation file for space1 class
********************************************************/
#include <iostream>
#include <string>
#include "space1.hpp"
#include "spaces.hpp"
#include "character.hpp"

void Space1::movePlayer(char& aChar)
{
    
    if(aChar == 'w')
    {
        if(player->getRow() == 0)
        {
            if(player->getColumn() == 10 && player->getKey4() > 0)
            {
                player->setColumn(10);
                player->setRow(23);
                player->setPrevious(" || ");
                nextSpace(top);
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
            if(player->getColumn() == 10 && player->getKey3() > 0)
            {
                player->setColumn(10);
                player->setRow(0);
                player->setPrevious("o||O");
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
             if(player->getRow() == 12 && player->getKey2() >0)
             {
                 player->setColumn(0);
                 player->setRow(12);
                 player->setPrevious("||~~");
                 nextSpace(right);
                 return;
                 
             }
 
            
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
             if(player->getRow() == 12 && player->getKey1() >0)
             {
                 player->setColumn(19);
                 player->setRow(12);
                 player->setPrevious("ww||");
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
