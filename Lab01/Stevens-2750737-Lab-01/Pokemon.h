/* 
 * File:   Pokemon.h
 * Author: Jack
 * Purpose: Declare all Pokemon Members
 * Created on September 3, 2015, 12:04 AM
 */
#include <string>

#ifndef POKEMON_H
#define	POKEMON_H

class Pokemon {
public:

//Constructor for Pokemon Class

    Pokemon();
    
//Reduce the HP of the Pokemon

    void reduceHP(int amount);

//return the HP of the Pokemon
    
    int getHP() const; 

//Set the HP of the pokemon
    
    
    void setHP(int hp);

//Get the Attack Value of the Pokemon
    
    
    int getAttack() const;

//Set the Attack Vlue of the Pokemon
    
    
    void setAttack(int attack);

//Return the Defense Value of the Pokemon
    
    
    int getDefense() const;

//Set the Defense Value of the Pokemon
    
    
    void setDefense(int defense);

//Return the string of the name of the Pokemon
    
    
    std::string getName() const;

//Set the name of the string of the Pokemon
    
    
    std::string setName(std::string name);
    
private:
    int m_hp;
    int m_attackLevel;
    int m_defenseLevel;

    std::string m_name;
};

#endif	/* POKEMON_H */

