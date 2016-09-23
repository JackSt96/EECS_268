/* 
 * File:   Pokemon.h
 * Author: Jack
 *
 * Created on September 3, 2015, 12:04 AM
 */
#include <string>

#ifndef POKEMON_H
#define	POKEMON_H

class Pokemon {
public:
    Pokemon();
    
    void reduceHP(int amount);
    
    int getHP();
    
    
    void setHP(int hp);
    
    
    int getAttack();
    
    
    void setAttack(int attack);
    
    
    int getDefense();
    
    
    void setDefense(int defense);
    
    
    int getName();
    
    
    void String setName(string name);
    
    
private:
    int m_hp;
    int m_attackLevel;
    int m_defenseLevel;
    string m_name;
};

#endif	/* POKEMON_H */

