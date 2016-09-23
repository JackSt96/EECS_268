/*
 * File:   CyberChicken.h
 * Author: Jack
 * Purpose: Declare CyberChicken methods
 * Created on September 22, 2015, 12:01 PM
 */

#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H

#include "Chicken.h"


class CyberChicken: public Chicken
{

public:
  CyberChicken();
  //sets m_name to "Cyber Chicken" and m_sound to "Resistance is futile"
  int getCyberEggs() const;
  //gets the inherited member variable, m_eggs
  void setCyberEggs(int eggs);
  //sets the inherited member variable, m_eggs
};

#endif
