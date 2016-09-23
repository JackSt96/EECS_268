/*
 * File:   main.cpp
 * Author: Jack
 * Purpose: Handle Project and interact with user.
 * Created on September 22, 2015, 12:01 PM
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include "DoubleLinkedList.h"
#include "Test.h"
//main.cpp

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove front value\n"
		<<	"6) remove back value\n"
		<<	"7) remove specific value\n"
		<<	"8) print list\n"
		<<	"9) Quit\n"
		<< 	"10) Run Tests\n"
		<< 	"Your choice: ";
}


int main()
{
    int x,n;
    bool loop = true;
    DoubleLinkedList<int> list;
    Test Runner(std::cout);
    while (loop)
    {
        printMenu();
        std::cin>>n;
        switch (n)
        {
		case 1: std::cout << "Input a value to add. \n";
				std::cin>> x;
				std::cout << "Adding " << x << " to the list \n";
				list.pushFront(x);
		  break;
		case 2: std::cout << "Input a value to add. \n";
				std::cin>> x;
				std::cout << "Adding " << x << " to the list \n";
				list.pushBack(x);
		  break;
    case 4:  std::cout << "Enter a value to search for:\n";
  				std::cin>> x;
  				std::cout << "Searching for " << x << " in the list \n";
          try{list.insertAhead(x,6);}
  				catch(std::runtime_error& e)
          {
            std::cout << e.what() << std::endl;
          }
        break;
    case 3:  std::cout << "Enter a value to search for:\n";
      		std::cin>> x;
      		std::cout << "Searching for " << x << " in the list \n";
      		list.insertBehind(x,6);
      				std::cout << x << " is in the list \n";

            break;
		case 5: std::cout << "Attempting removal from front of list.\n";
				if(list.removeFront())
					std::cout << "Removal Successful.\n";
				else
					std::cout << "There are no values to remove.\n";
		  break;
		case 6:	std::cout << "Attempting removal from back of list.\n";
				if(list.removeBack())
					std::cout << "Removal Successful.\n";
				else
					std::cout << "There are no values to remove.\n";
		  break;
		case 8:list.printList();
		  break;
		case 7:    std::cout << "Enter a value to search for:\n";
				std::cin>> x;
				std::cout << "Searching for " << x << " in the list \n";
				if (list.remove(x))
					std::cout << x << " is in the list \n";
				else
					std::cout << x << " is not the list \n";
		  break;
		case 9: loop = false;
          list.~DoubleLinkedList();
		  break;
		case 10:Runner.runTests();
		  break;
      		default: "Sorry man that wasn't an option. Please enter another option.\n";
	  }
    }
    return 0;
}
