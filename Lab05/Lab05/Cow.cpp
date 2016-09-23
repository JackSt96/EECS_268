/*
 * File:   Cow.cpp
 * Author: Jack
 * Purpose: Declare Cow methods
 * Created on September 22, 2015, 12:01 PM
 */



#include "Cow.h"

Cow::Cow()
{
  setName("Cow");
  setSound("Moo");
}

double Cow::getMilkProduced() const
{
  return m_milkProduced;
}

void Cow::setMilkProduced(double gallons)
{
  if(gallons>0)
  {
  m_milkProduced = gallons;
  }
  else
  m_milkProduced = 0;
}
