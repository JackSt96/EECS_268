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
void cycle(LinkedList& list, int n)
{
  switch(n)
  {
    case 1: std::cout << "Input a value to add. \n";
			std::cin>> x;
			list.addFront(x);
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:    std::cout << "Enter a value to search for:\n";
      break;
    case 7: loop = false;
      break;
    case 8:
      break;
    default: "Sorry man that wasn't an option. Please enter another option.\n";
  }
}


int main(int argc, char** argv)
{
  LinkedList list;
  while(loop)
  {
  printMenu();
  std::cin >> x;
  cycle(list, x);
  }
}

