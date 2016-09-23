/*
 * File:   main.cpp
 * Author: Jack
 * Purpose:
 * Created on September 15, 2015, 12:01 PM
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Cow.h"
#include "Node.h"
#include "FarmAnimal.h"
#include "CyberChicken.h"
#include "AnimalPen.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"
using namespace std;

int x, n;
double y;
char loop = 'n';
double milk = 0;
int eggs = 0;
bool co,ch,cy = false;

void printMenu()
{
	std::cout << 	"\n\nSelect an action:\n"
    <<  "1) Cow (produces milk)\n"
    <<  "2) Chicken (cannot lay eggs)\n"
    <<  "3) Chicken (cannot lay eggs)\n"
		<<  "--------------------------------------------------- \n";
}

void goodbyeMessage(const FarmAnimal& animal){

	cout << "Upon release the "<< animal.getName()<< " said "<< animal.getSound() << "\n";

}

int main()
{
	AnimalPen* Pen = new AnimalPen();
  while(loop == 'n')
  {
  printMenu();
  std::cin >> n;
	switch(n)
		  {
			case 1:
			{
			//	FarmAnimal* cow3 = new Cow();
				Cow* cow1 = new Cow();// = static_cast<Cow*>(cow3);
					std::cout << "How many gallons of milk did this cow produce?:\n";
					std::cin>> y;
					cow1->setMilkProduced(y);
					Pen->addAnimal(cow1);
					std::cout << "Done adding animals? (y/n):  \n";
					std::cin>> loop;
					//delete cow1;
			  break;
			}
			case 2:
			{
				Chicken* chick = new Chicken();
					std::cout << "choice: Add an eggless chicken to the pen? OK. You're the boss.\n";
					Pen->addAnimal(chick);
					std::cout << "Done adding animals? (y/n):  \n";
					std::cin>> loop;
					//delete chick;
			  break;
			}
			case 3:
			{
				CyberChicken* cyChick = new CyberChicken();
					std::cout << "choice: How many eggs did this cyber chicken produce?:\n";
					std::cin>> x;
					cyChick->setCyberEggs(x);
					Pen->addAnimal(cyChick);
					std::cout << "Done adding animals? (y/n):  \n";
					std::cin>> loop;
					//delete cyChick;
			  break;
			}
			default:
				std::cout << "Sorry man that wasn't an option. Please enter another option.\n";
		  }
  }
	while(Pen-> isPenEmpty() != true)
	{
		FarmAnimal* animal = nullptr;
		animal = Pen->peekAtNextAnimal();
		std::string name = animal->getName();

		if (name == "Cow") {
			Cow* cow2 = static_cast<Cow*>(animal);
			std::cout << "This cow produced "<< cow2->getMilkProduced() << " gallons of milk\n";
			milk = milk + cow2->getMilkProduced();
			goodbyeMessage(*cow2);
			Pen->releaseAnimal();
			delete cow2;
			}
		if (name == "Chicken") {
			std::cout<< "Chicken unable to lay eggs. Perhaps cybornetic implants will help?\n";
			goodbyeMessage(*(Pen->peekAtNextAnimal()));
					Pen->releaseAnimal();
					std::cout << "Chicken Destructor called\n";
		}
		if (name == "CyberChicken") {
			CyberChicken* cyChick2 = static_cast<CyberChicken*>(animal);
			std::cout << "This Cyber Chicken laid "<< cyChick2->getCyberEggs() << "cyber eggs. Humanity is in trouble\n";
			eggs = eggs + cyChick2->getCyberEggs();
			goodbyeMessage(*(Pen->peekAtNextAnimal()));
					Pen->releaseAnimal();
			std::cout << "CyberChicken Destructor called\n";
			std::cout << "Chicken Destructor called\n";
			delete cyChick2;
		}

	}

	cout << "\nYour farm produced " << milk << " gallons of milk and " <<  eggs <<  " eggs.\n";
	delete Pen;
  return 0;
}
