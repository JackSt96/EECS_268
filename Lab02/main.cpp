/*
 * File:   main.cpp
 * Author: Jack
 * Purpose:
 * Created on September 15, 2015, 12:01 PM
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "LinkedList.h"
#include "Test.h"

  int x;
  bool loop = true;

void printMenu()
{
	std::cout << "\n\nSelect from the following menu:\n"
			<< "1) Add to the front of the list\n"
			<< "2) Add to the end of the list\n"
			<< "3) Remove from front of the list\n"
			<< "4) Remove from back of the list\n"
			<< "5) Print the list\n"
			<< "6) Search for value\n"
			<< "7) Exit\n"
			<< "8) Run tests\n"
			<< "Enter your choice: ";
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
		case 2: std::cout << "Input a value to add. \n";
				std::cin>> x;
				std::cout << "Adding " << x << " to the list \n";
				list.addBack(x);
		  break;
		case 3: std::cout << "Attempting removal from front of list.\n";
				if(list.removeFront())
					std::cout << "Removal Successful.\n";
				else
					std::cout << "There are no values to remove.\n";
		  break;
		case 4:	std::cout << "Attempting removal from back of list.\n";
				if(list.removeBack())
					std::cout << "Removal Successful.\n";
				else
					std::cout << "There are no values to remove.\n";
		  break;
		case 5:list.printList();
		  break;
		case 6:    std::cout << "Enter a value to search for:\n";
				std::cin>> x;
				std::cout << "Searching for " << x << " in the list \n";
				if (list.search(x))
					std::cout << x << " is in the list \n";
				else
					std::cout << x << " is not the list \n";
		  break;
		case 7: loop = false;
				list.~LinkedList();
		  break;
		case 8: Runner.runTests();
		  break;
		default: "Sorry man that wasn't an option. Please enter another option.\n";
	  }
}


int main(int argc, char** argv)
{
  Test Runner(std::cout);
  LinkedList list;
  while(loop)
  {
  printMenu();
  std::cin >> x;
  cycle(list, x, Runner);
  }
}
