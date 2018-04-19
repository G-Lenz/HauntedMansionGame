/************************************************************
 * Program: dracula.hpp
 * Author: George Lenz
 * Date: 3/20/2018
 * Description: Header file for dracula
 * ********************************************************/
#ifndef DRACULA_HPP
#define DRACULA_HPP
#include <iostream>
using namespace std;

class Dracula
{
private:

int health;

public:

Dracula()
{
    health = 100;
}
//print display
void  printDracula()
{
cout<<"                     __.......__" << endl;
cout<<"                  .-:::::::::::::-." << endl;
cout<<"                .:::''':::::::''':::." << endl;
cout<<"              .:::'     `:::'     `:::." << endl; 
cout<<"         .'\\  ::'   ^^^  `:'  ^^^   '::  /`." << endl;
cout<<"        :   \\ ::   _.__       __._   :: /   ;" << endl;
cout<<"       :     \\`: .' ___\\     /___ `. :'/     ;" << endl; 
cout<<"      :       /\\   (_|_)\\   /(_|_)   /\\       ;" << endl;
cout<<"      :      / .\\   __.' ) ( `.__   /. \\      ;" << endl;
cout<<"      :      \\ (        {   }        ) /      ;" << endl;
cout<<"       :      `-(     .  ^\"^  .     )-'      ;" << endl;
cout<<"        `.       \\  .'<`-._.-'>'.  /       .'" << endl;
cout<<"          `.      \\    \\;`.';/    /      .'" << endl;
cout<<"            `._    `-._       _.-'    _.'" << endl;
cout<<"             .'`-.__ .'`-._.-'`. __.-'`." << endl;
cout<<"           .'       `.         .'       `." << endl;
cout<<"         .'           `-.   .-'           `."<< endl;
 
}

int getHealth()
{
    return health;
}

void setHealth(int aNum)
{
    health = aNum;
}
//inflict damage
int attack()
{
    return 15;
}
//take damage
void defend(int attack)
{
    health = health - attack;
}

};
#endif


