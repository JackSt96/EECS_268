/*
 * File:   AnimalPen.h
 * Author: Jack
 * Purpose: Declare AnimalPen methods
 * Created on September 22, 2015, 12:01 PM
 */


#ifndef ANIMALPEN_H
#define ANIMALPEN_H
#include "Node.h"
#include "Stack.h"
#include <cstdlib>
#include "FarmAnimal.h"
#include "PreconditionViolationException.h"



class AnimalPen: public Stack<FarmAnimal*>
{
    public:
    AnimalPen();
    //constructor
    virtual ~AnimalPen();
    //destructor
    bool isPenEmpty() const;
    //check the stack to see what's in there
    void addAnimal(FarmAnimal* animal);
    //add to the stack
    void releaseAnimal();
    //pop
    FarmAnimal* peekAtNextAnimal() const;
    //peek

private:
    int m_size;

//    Node<FarmAnimal>* m_Penis;
};

#endif
