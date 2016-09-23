/* 
 * File:   Colosseum.cpp
 * Author: Jack
 * Purpose: Handle all the fights, building, and playing of the Pokemon.
 * Created on September 3, 2015, 12:01 AM
 */

#include "Colosseum.h"
#include "Dice.h"
#include <iostream>
#include <string>


Colosseum::Colosseum() {
    d20 = new Dice(20);
    d6 = new Dice;
    d2 = new Dice(2);
    round = 1;
    game = true;
    attack1 = 0;
    attack2 = 0;
    attack3 = 0;
    attackBonus = 0;
    defenseBonus = 0;
    name = "";
}
void Colosseum::userBuild(Pokemon& p)
{
    std::cout << "Please name your Pokemon: " << '\n';
    std::cin >> name;
    p.setName(name);
	second = true;
    do{
	if(!second)
        {
            std::cout << "Sorry. The HP must be between 1 and 50:";
        }
    std::cout << "How many hit points will it have? (1-50): " << '\n';
    std::cin >> x;
	second = false;
    }
    while(x > 50 || x < 1);
    p.setHP(x);
    
    

    std::cout << "Split fifty points between attack level and defense level " << '\n';
    do
    {
        if(second)
        {
            std::cout << "Sorry. The attack level must be between 1 and 49:";
        }
    std::cout << "Enter your attack level (1-49): " << '\n';
    std::cin >> x;
    second = true;
    }
    while(x > 49 || x < 1);
    p.setAttack(x);
    max = 50 - x;
    
    
    
    do
    {
        if(!second)
        {
            std::cout << "Sorry. The defense level must be between 1 and 49:" << '\n';
        }
    std::cout << "Enter your defense level (1-" << max << "): " << '\n';
    std::cin >> x;
    second = false;
    }
    while(x > max || x < 1);
    p.setDefense(x);
}

void Colosseum::play(Pokemon& p1, Pokemon& p2)
{
    int x = d2->roll();
    if (x == 1){
    std::cout << p1.getName() << " rolls a " << x << " and will go first" << '\n';
    while(game && round < 10)
    {
        std::cout << "Round " << round << "!" << '\n';
        game = attack(p1,p2);
        round++;
        game = attack(p2,p1);
    }
    }
    else
    {
    std::cout << p1.getName() << " rolls a " << x << " and will go second" << '\n';
        while(game && round < 10)
    {
        std::cout << "Round " << round << "!" << '\n';
        game = attack(p2,p1);
        round++;
        game = attack(p1,p2);
    }
	if(round == 10)
	{
	std::cout << '\n' << "The Game has reached round 10 and is concluded in a draw" << '\n';
 	}
	delete d20;
	delete d6;
	delete d2;
    }
}

bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender)
{
    attackBonus = d20->roll();
    std::cout << attacker.getName() << " rolls an attack bonus of " << attackBonus <<'\n';
    defenseBonus = d20->roll();
    std::cout << defender.getName() << " rolls an attack bonus of " << defenseBonus << '\n';
    
    if((attackBonus + attacker.getAttack()) > (defenseBonus + defender.getDefense()))
    {
        std:: cout << attacker.getName() << " is attacking " << defender.getName() << '\n';
        std:: cout << "The attack hits dealing a 3-D6 damage!" << '\n';
        attack1= d6->roll();
        attack2= d6->roll();
        attack3= d6->roll();
        std::cout << "The rolls are " << attack1 << ", " << attack2 << ", and " << attack3 << "totaling: " << (attack1+attack2+attack3) << "damage!" << '\n';
        defender.setHP((defender.getHP() - (attack1+attack2+attack3)));
        if(defender.getHP() > 0)
        {
            std::cout << defender.getName() << " has " << defender.getHP() << " Hit points left!" << '\n' << '\n';
            return true;
        }
        else
        {
            std::cout << defender.getName() << " has been defeated" << '\n' << '\n';
            return false;
        }
    }
    else
	{
	std:: cout << "The attack missed" << '\n' << '\n';
	return true;
	}
}