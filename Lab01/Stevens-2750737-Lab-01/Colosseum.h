/* 
 * File:   Colosseum.h
 * Author: Jack
 * Purpose: Declare all Colosseum Members
 * Created on September 3, 2015, 12:01 AM
 */
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"

#ifndef COLOSSEUM_H
#define	COLOSSEUM_H


class Colosseum {
    public:
        std::string name;
        int x;
        bool second;
        int max;
        int round;
        bool game;
        int attack1;
        int attack2;
        int attack3;
	Colosseum();
	
//Build the Pokemon, including the name, hp, att, and def 

	void userBuild(Pokemon& p);
	
//Handles the fights between the different pokemon
	
	bool attack(const Pokemon& attacker, Pokemon& defender);

//Handles the round counting in the actual game, including calling on the different attacks
	
	void play(Pokemon& p1, Pokemon& p2);
	
    private:
	int attackBonus;
        int defenseBonus;
        Dice* d20;
       	Dice* d6;
        Dice* d2;
};  

#endif	/* COLOSSEUM_H */

