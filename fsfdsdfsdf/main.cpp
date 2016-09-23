/**
*	@file main.cpp
* 	@author Clayton Fasenmyer
*	@date 2015.09.19
*
*/

#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Test.h"

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

int main()
{
	LinkedList l1;
	int selection;
	int value;
	Test myTester(std::cout);
	while (selection != 7)
	{
		value = 0;
		//std::cout << "Size: " << l1.size() << std::endl;
		//std::cout << "empty: " << l1.isEmpty() << std::endl;
		printMenu();
		std::cin >> selection;
		std::cout << "You chose: " << selection << std::endl;
		switch(selection)
		{
			case 1:
				//addfront
				std::cout << "Input a value to add: ";
				std::cin >> value;
				std::cout << "Adding " << value << " to the list\n";
				l1.addFront(value);
				break;
			case 2:
				//addback
				std::cout << "Input a value to add: ";
				std::cin >> value;
				std::cout << "Adding " << value << " to the list\n";
				l1.addBack(value);
				break;
			case 3:
				//removefront
				std::cout << "Attempting removal from front of list.\n";
				if(l1.removeFront())
					std::cout << "Removal Successful.\n";
				else
					std::cout << "There are no values to remove.\n";
				break;
			case 4:
				//removeback
				std::cout << "Attempting removal from back of list.\n";
				if(l1.removeBack())
					std::cout << "Removal Successful.\n";
				else
					std::cout << "There are no values to remove.\n";
				break;
			case 5:
				//printlist
				std::cout << "Printing list:\n";
				l1.printList();
				break;
			case 6:
				//search
				std::cout << "Input a value to search for: ";
				std::cin >> value;
				std::cout << "You chose: " << value << "\n";
				if(l1.search(value))
				{
					std::cout << value << " is in the list.\n";
				}
				else
				{
					std::cout << value << " is not in the list.\n";
				}
				break;
			case 7:
				//exit
				l1.~LinkedList();
				std::cout << "Exiting...";
				break;
			case 8:
				//run tests
				myTester.runTests();
				break;
			default:
				std::cout << "Invalid choice.";
				break;
		}
	}
	return(0);
}


