/*
 * File:   main.cpp
 * Author: Jack
 * Purpose:
 * Created on September 15, 2015, 12:01 PM
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Stack.h"
#include "StackInterface.h"
#include "Test.h"
#include "PreconditionViolationException.h"

int x, n;
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

/*void cycle(Stack<T>& list, int n, Test& Runner)
{
  switch(n)
	  {
		case 1: std::cout << "Input a value to add. \n";
				std::cin>> x;
				std::cout << "Adding " << x << " to the list \n";
				list.push(x);
		  break;
		case 2: std::cout << "Attempting removal from front of list.\n";
				list.peek();
					std::cout << "Removal Successful.\n";
		  break;
		case 3:	std::cout << "Attempting removal from back of list.\n";
				list.pop();
					std::cout << "Removal Successful.\n";
		  break;
		case 4:list.print();
		  break;
		case 5: loop = false;
				list.~LinkedList();
		  break;
		case 6: Runner.runTests();
		  break;
		default: "Sorry man that wasn't an option. Please enter another option.\n";
	  }
}*/

int main()
{
  while(loop)
  {
  Test Runner(std::cout);
  StackInterface<int>* ptr = new Stack<int>();
  printMenu();
  std::cin >> n;
	switch(n)
		  {
			case 1: std::cout << "What is going in stack 1?: \n";
					std::cin>> x;
					std::cout << "Adding " << x << " to the list \n";
					ptr->push(x);
			  break;
			case 2: std::cout << "Attempting show first item in stack.\n";
					ptr->peek();
						std::cout << "Removal Successful.\n";
			  break;
			case 4:	std::cout << "Attempting removal from back of list.\n";
					ptr->pop();
						std::cout << "Removal Successful.\n";
			  break;
			case 3:ptr->print();
			  break;
			case 5: loop = false;
			//		list.~LinkedList();
			  break;
			case 6: Runner.runTests();
			  break;
			default: "Sorry man that wasn't an option. Please enter another option.\n";
		  }
  }
  return 0;
}
