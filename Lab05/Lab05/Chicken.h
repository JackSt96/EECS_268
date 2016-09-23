/*
 * File:   Chicken.h
 * Author: Jack
 * Purpose: Declare Chicken methods
 * Created on September 22, 2015, 12:01 PM
 */


#ifndef CHICKEN_H
#define CHICKEN_H

#include "FarmAnimal.h"




class Chicken: public FarmAnimal
{
protected:
  int getEggs() const;
  //Return Eggs
  void setEggs(int eggs);
  //Set m_eggs to eggs
  int m_eggs;
public:
  Chicken();
};

#endif
