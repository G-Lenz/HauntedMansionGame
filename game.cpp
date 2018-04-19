/*****************************************************************************
 * PRogram Name: game.cpp
 * Author: George Lenz
 * Date: 3/20/2018
 * Description: Implementatino file for game class
 * **************************************************************************/

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
#include "pictures.hpp"
using namespace std;

//Print the menu
void Game::printMenu()
{
    inputChar == ' ';
    system("clear");
    printHouse();
    cout << "                ***********************\n";
    cout << "                *    Haunted House    * \n";
    cout << "                ***********************\n" << endl;

    cout << "                     1. Play Game\n";
    cout << "                     2. Quit\n";

    cout << endl << "                    Choose Item: ";

    validate(&menuChoice, 1, 2);
}
//Print the instructions
void Game::printInstruct()
{
    system("clear");
    printButler();
    cout << "Welcome to the haunted mansion, I will be your guide tonight\n\n";
    cout << "Use w to move up\n";
    cout << "Use s to move down\n";
    cout << "Use a to move right\n";
    cout << "Use d to move down\n";
    cout << "USE q at any time during the game to quit\n";

    cout << "\nGOAL: To escape the haunted mansion.\n\n"
         << "You are trapped in a haunted mansion and the doors are locked"
         << "\n\nYou must find all the keys and escape\n"
         << "\nThe only problem is, it is hard to see in the "
         << "mansion and the keys are not visible.\n\n";

    cout << "press ENTER to begin...";
    cin.ignore();
}
//Print the in-game display
void Game::printSpace()
{
    if(player->getCurrentSpace() == 1)
    {
        cout << "HEALTH: " << player->getHealth() << endl;

        cout << "LOBBY: can't see a thing through these cobwebs" << endl;
        lobby->printSpaces(); 
    }
    else if(player->getCurrentSpace() == 2)
    {
        cout << "HEALTH: " << player->getHealth() << endl;

        cout << "COURTYARD: "
             << "It's hard to see through the tall grass" << endl;
        courtyard->printSpaces();
    }
    else if(player->getCurrentSpace() == 3)
    {
        cout << "HEALTH: " << player->getHealth() << endl;

        cout << "KITCHEN: It's too smokey to see in here" << endl;
        kitchen->printSpaces();
 
    }
    else if(player->getCurrentSpace() == 4)
    {
        cout << "HEALTH: " << player->getHealth() << endl;

        cout << "SAUNA: There is too much steam to see" << endl;
        sauna->printSpaces();
 
    }
    else if(player->getCurrentSpace() == 5)
    {
        cout << "HEALTH: " << player->getHealth() << endl;
       
        cout << "I'm not sure what room this is, it's too dark to see" << endl;
        darkRoom->printSpaces();
 
    }
    else if(player->getCurrentSpace() == 6)
    {
        cout << "HEALTH: " << player->getHealth() << endl;

        cout << "Final Room" << endl;   
        boss->printSpaces();

    }
}
//get user input
void Game::userInput()
{
    char aChar;
    system("stty raw");
    cin >> aChar;
    system("stty cooked");
    inputChar = aChar;
}
//decrease health on movement
void Game::stepPenalty()
{
    player->defend(1);
}
//move character based on room
void Game::move()
{
    if(player->getCurrentSpace() == 1)
    {
        lobby->movePlayer(inputChar);
    }
    else if (player->getCurrentSpace() == 2)
    {
        courtyard->movePlayer(inputChar);
    }
    else if(player->getCurrentSpace() == 3)
    {
        kitchen->movePlayer(inputChar);
    }
    else if(player->getCurrentSpace() == 4)
    {
        sauna->movePlayer(inputChar);
    }
    else if(player->getCurrentSpace() == 5)
    {
            darkRoom->movePlayer(inputChar);
    }
    else if (player->getCurrentSpace() == 6)
    {
        boss->movePlayer(inputChar);
    }
}
//take action based on room and space occupied
void Game::spaceAction()
{
    if(player->getCurrentSpace() == 1)
    {
        if(player->getRow() == 13 && player->getColumn() == 16)
        {
            if(player->getKey1() == 0)
            {
                cout << "\nYou found key 1, I wonder what door  it belongs to\n";
                player->setKey1(1);
                keys.push(player->getKey1());
            }
        }
   
    }
    else if(player->getCurrentSpace() == 2)
    {
        if(player->getRow() == 20 && player->getColumn() == 3)
        {
            if(player->getKey2() == 0)
            {
                cout << "\nYou found key 2, I wonder what door  it belongs to\n";
                player->setKey2(2);
                keys.push(player->getKey2());
            }
        }
    
    }  
    else if(player->getCurrentSpace() == 3)
    {
        if(player->getRow() == 10 && player->getColumn() == 4)
        {
            if(player->getKey3() == 0)
            {
                cout << "\nYou found key 3, I wonder what door  it belongs to\n";
                player->setKey3(3);
                keys.push(player->getKey3());
            }
        }
    
    }
    else if(player->getCurrentSpace() == 4)
    {
        if(player->getRow() == 7 && player->getColumn() == 9)
        {
            if(player->getKey4() == 0)
            {
                cout << "\nYou found key 4, I wonder what door  it belongs to\n";
                player->setKey4(4);
                keys.push(player->getKey4());
            }    
        }
    
    }
    else if(player->getCurrentSpace() == 5)
    {
        if(player->getRow() == 23 && player->getColumn() == 0)
        {
            if(player->getKey5() == 0)
            {
                cout << "\nYou found key 5, Best to use it on the last door\n";
                player->setKey5(5);
                keys.push(player->getKey5());
            }
        }
    
    }
    else if(player->getCurrentSpace() == 6)
    {   
        cout << "You have successfully opened all the doors exept one\n";
        cout << endl << "All that stands in your way now is the bat up ahead.";
        cout << endl << "\nI bet if you approach it you can scare it away." << endl;
        if(player->getRow() == 0 && player->getColumn() == 10)
        {
            system("clear");
            drac->printDracula();
            cout << endl << "That was no bat, it was Dracula!"
                 << endl << "You must defeat him to escape." << endl;

            cout << endl << "Press ENTER to continue..." << endl;
            cin.ignore();
            Game::fight();
   
        }
    }
}
//print the information in the queue
void Game::printKeys()
{
    cout << "\nKeys:\n";
    while(!keys.empty())
    {                  
        cout << "Key " << keys.front() << endl;
        temp.push(keys.front());
        keys.pop();        
    }
    if(keys.empty())   {
        keys.swap(temp);
    }
}
//Implement boss fighting sequence
void Game::fight()
{
    while(player->getHealth() >  0 && drac->getHealth() > 0)
    {
        system("clear");
        drac->printDracula();
        player->defend(drac->attack());
        if(player->getHealth() <= 0)
        {
            break;
        }
        cout << endl << "Dracula Health: " << drac->getHealth()
             << "    " << "Your Health: " << player->getHealth() << endl;
        cout << "Dracula attacked and caused you " << drac->attack()
             << " damage!\n";
        cout << endl << "Press ENTER to attack back...";
        cin.ignore();
        system("clear");
        drac->printDracula();
        drac->defend(player->attack());
        cout << endl << "Dracula Health: " << drac->getHealth()
             << "    " << "Your Health: " << player->getHealth() << endl;
        cout << endl<< "You caused " << player->attack()
                       << " damage" << endl << endl;
        cout << "Press ENTER to continue...";
        cin.ignore();
    }
        if(drac->getHealth() <= 0)
        {
            system("clear");
            printWin();
            cout << endl << endl;
            cout << "press ENTER to return to menu...";
            cin.ignore();
            loss = 1;
         }
        else if(player->getHealth() <=0)
        {
            system("clear");
            printLoss();
            cout << endl << endl;
            cout << "Press ENTER to continue...";
            cin.ignore();
            cout  << endl << endl;
            loss = 1;
        }
  
}
//Check to see if player has health left
void Game::healthCheck() 
{
        if (player->getHealth() == 0)
        {   system("clear");
            printLoss();
            cout <<  endl;
            cout << endl <<"press ENTER to continue...";
            cin.ignore();
            loss = 1;
        }
 
}
//Set all game information to default
void Game::newGame()
{   
    loss = 0;
    player->reset();
    drac->setHealth(100);
    while(!keys.empty())
    {
        keys.pop();
    }
}
