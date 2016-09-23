/* 
 * File:   Pokemon.cpp
 * Author: Jack
 * 
 * Created on September 3, 2015, 12:04 AM
 */
#include <string>
#include "Pokemon.h"

Pokemon::Pokemon() {
    m_hp = 0;
    m_attackLevel = 0;
    m_defenseLevel = 0;
    m_name = "";
}

Pokemon::Pokemon(const Pokemon& orig) {
}


int Pokemon::getHP() const
{
    return (m_hp);
}
    
void Pokemon::setHP(int x) const
{
    m_hp = x;
}
    
int Pokemon::getAttack() const
{
    return (m_attackLevel);
}
    
void Pokemon::setAttack(int attack) const
{
    m_attackLevel = attack;
}
    
int Pokemon::getDefense() const
{
    return (m_defenseLevel);
}
    
void Pokemon::setDefense(int defense) const
{
    m_defenseLevel = defense;
}
void Pokemon::setName(string name) const
{
    m_name = name;
}    

string Pokemon::getName() const
{
    return (m_name);
}


Pokemon::~Pokemon() {
}