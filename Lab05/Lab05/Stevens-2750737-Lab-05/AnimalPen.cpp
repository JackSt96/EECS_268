/*
 * File:   AnimalPen.cpp
 * Author: Jack
 * Purpose: Use Stack methods
 * Created on September 22, 2015, 12:01 PM
 */

#include "AnimalPen.h"

AnimalPen::AnimalPen()
{

}

AnimalPen::~AnimalPen()
{
  while(!isPenEmpty())
  {
    delete peek();
    pop();
  }
}

bool AnimalPen::isPenEmpty() const
{
    return isEmpty();
}

void AnimalPen::addAnimal(FarmAnimal* animal)
{
  push(animal);
}

void AnimalPen::releaseAnimal()
{
  try{		pop();}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
}

FarmAnimal* AnimalPen::peekAtNextAnimal() const
{
  return peek();
}
