/*
 * File:   Chicken.cpp
 * Author: Jack
 * Purpose: Declare Chicken methods
 * Created on September 22, 2015, 12:01 PM
 */


#include "Chicken.h"


Chicken::Chicken()
{
  setName("Chicken");
  setSound("Cluck");
}

int Chicken::getEggs() const
{
  return m_eggs;
}
void Chicken::setEggs(int eggs)
{
  m_eggs = eggs;
}
