/*
 * File:   FarmAnimal.h
 * Author: Jack
 * Purpose: Declare FarmAnimal methods
 * Created on September 22, 2015, 12:01 PM
 */


#include <string>
#include <cstdlib>
#include "FarmAnimal.h"


FarmAnimal::FarmAnimal()
{

  m_name = "";
  m_sound = "";


}


std::string FarmAnimal::getName() const
{
  return m_name;
}

void FarmAnimal::setName(std::string name)
{
    m_name = name;
}


std::string FarmAnimal::getSound() const
{

    return m_sound;

}
void FarmAnimal::setSound(std::string sound)
{
  m_sound = sound;
}
