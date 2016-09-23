/* 
 * File:   Colosseum.h
 * Author: Jack
 *
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
        string name = "";
        int x;
        bool second;
        int max;
        int round;
        bool game;
        int attackBonus;
        int defenseBonus;
        int attack1;
        int attack2;
        int attack3;
	Colosseum();
	
	void userBuild(Pokemon& p);
	
	
	bool attack(const Pokemon& attacker, Pokemon& defender);
	
	void play(Pokemon& p1, Pokemon& p2);
	
    private:
        Dice* d20;
        Dice* d6;
        Dice* d2;
};  

#endif	/* COLOSSEUM_H */

