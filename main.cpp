/*************************************************************************************
 * Program NAme: main.cpp
 * Author: George Lenz
 * Date: 3/20/2018
 * Description: runs a haunted house game

pictures in this game were used from:
http://www.chris.com/ascii/joan/www.geocities.com/SoHo/7373/haloween.html
*************************************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include "spaces.hpp"
#include "space1.hpp"
#include "character.hpp"
#include "space2.hpp"
#include "space3.hpp"
#include "space4.hpp"
#include "space5.hpp"
#include <queue>
#include "space6.hpp"
#include "dracula.hpp"
#include "validate.hpp"
#include "game.hpp"
using namespace std;
int main()
{

Game* game;


do
{
    //create a game
    game = new Game();
    
    //menu
    game->printMenu();
    if(game->getMenuChoice() == 1)
    {
        //instructions
        game->printInstruct();

        //print display
        system("clear");
        game->printSpace();
        //move character and update
        while(game->getInput()!='q')
        {
             //get input, decrease health for step
             game->userInput();
             game->stepPenalty();  
             system("clear");
            //Move 
            game->move();

            //print current board and check to see if key was found 
            //or if there is action to be taken
            game->printSpace();
            game->spaceAction();
            //check health and current game status
            game->healthCheck();
            if(game->getLoss() == 1)
            {
                break;
            }
            //print keys
            game->printKeys();  
        }
    }
    //start a new game and clear memory
    game->newGame();
    delete game;
}while(game->getMenuChoice() !=2);
 

return 0;

}


