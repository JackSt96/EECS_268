/*
 * File:   CyberChicken.cpp
 * Author: Jack
 * Purpose: Declare CyberChicken methods
 * Created on September 22, 2015, 12:01 PM
 */


#include "CyberChicken.h"


CyberChicken::CyberChicken()
{
  setName("CyberChicken");
  setSound("Resistance is futile");
}
//sets m_name to "Cyber Chicken" and m_sound to "Resistance is futile"
int CyberChicken::getCyberEggs() const
{
  return getEggs();
}
//gets the inherited member variable, m_eggs
void CyberChicken::setCyberEggs(int eggs)
{
  setEggs(eggs);
}
//sets the inherited member variable, m_eggs
