/*
 * File:   Cow.h
 * Author: Jack
 * Purpose: Declare Cow methods
 * Created on September 22, 2015, 12:01 PM
 */



#ifndef COW_H
#define COW_H

#include "FarmAnimal.h"



class Cow: public FarmAnimal
{
protected:
    double m_milkProduced;
    //value for cow milk
public:
    Cow();
    //constructor for cow
    double getMilkProduced() const;
    //returns milk produced
    void setMilkProduced(double gallons);
    //sets the ammount of milk produced, value cannot be negative
};

#endif
