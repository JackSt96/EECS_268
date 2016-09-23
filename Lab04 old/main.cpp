/*
 * File:   main.cpp
 * Author: Jack
 * Purpose:
 * Created on September 15, 2015, 12:01 PM
 */

#include <iostream>
#include <string>
#include <cstdlib>


int x;
bool loop = true;

void printMenu()
{
	std::cout << 	"\n\nSelect an action:\n"
    <<  "1) Add to stack\n"
    <<  "2) See what is at the top of stack\n"
    <<  "3) Print all stack\n"
    <<  "4) Pop stack\n"
    <<  "5) Quit\n"
    <<  "6) Run Tests\n"
    <<  "Enter choice:\n";
}

void cycle(LinkedList& list, int n, Test& Runner)
{
  switch(n)
	  {
		case 1: std::cout << "Input a value to add. \n";
				std::cin>> x;
				std::cout << "Adding " << x << " to the list \n";
				list.addFront(x);
		  break;
		case 2: std::cout << "Attempting removal from front of list.\n";
				if(list.removeFront())
					std::cout << "Removal Successful.\n";
				else
					std::cout << "There are no values to remove.\n";
		  break;
		case 3:	std::cout << "Attempting removal from back of list.\n";
				if(list.removeBack())
					std::cout << "Removal Successful.\n";
				else
					std::cout << "There are no values to remove.\n";
		  break;
		case 4:list.printList();
		  break;
		case 5: loop = false;
				list.~LinkedList();
		  break;
		case 6: Runner.runTests();
		  break;
		default: "Sorry man that wasn't an option. Please enter another option.\n";
	  }
}

int main(int argc, char** argv)
{
  while(loop)
  {
  printMenu();
  std::cin >> x;
  cycle(list, x, Runner);
  }
  return 0;
}
