/* 
 * File:   Pokemon.cpp
 * Author: Jack
 * Purpose: Handle all of the geting and setting of values for the Pokemon
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

int Pokemon::getHP() const
{
    return (m_hp);
}
    
void Pokemon::setHP(int x)
{
    m_hp = x;
}
    
int Pokemon::getAttack() const
{
    return (m_attackLevel);
}
    
void Pokemon::setAttack(int attack)
{
    m_attackLevel = attack;
}
    
int Pokemon::getDefense() const
{
    return (m_defenseLevel);
}
    
void Pokemon::setDefense(int defense)
{
    m_defenseLevel = defense;
}
std::string Pokemon::setName(std::string name)
{
    m_name = name;
}    

std::string Pokemon::getName() const
{
    return (m_name);
}
