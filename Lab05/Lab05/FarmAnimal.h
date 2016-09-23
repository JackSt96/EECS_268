/*
 * File:   FarmAnimal.h
 * Author: Jack
 * Purpose: Declare FarmAnimal methods
 * Created on September 22, 2015, 12:01 PM
 */



#ifndef FARMANIMAL_H
#define FARMANIMAL_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "PreconditionViolationException.h"



class FarmAnimal
{
  protected:
  std::string m_name;
  //name for each animal
  std::string m_sound;
  //sound for each animal
  public:
  FarmAnimal();
  //constructor for name and sound of each animal
  std::string getName() const;
  //return m_name
  void setName(std::string name);
  //set m_name
  std::string getSound() const;
  //return m_name
  void setSound(std::string sound);
  //return m_sound
};

#endif
