/*
 * File:   main.cpp
 * Author: Jack
 * Purpose:
 * Created on September 15, 2015, 12:01 PM
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>
#include <chrono>
#include <functional>
#include <cassert>
#include "Test.h"
#include "Sorts.h"


int n, min, max, size;
char print;
char loop = 'n';

void printMenu()
{
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
            << "5) Run Tests\n"
               << "6) exit\n"
			<< "Enter choice: \n";
}
void printArray(int array[], int size) {

  for (int i=0; i<size-1; i++)
  {  std::cout << array[i] << ", ";}
  std::cout << array[(size-1)] << "]\n";
}

int main()
{
  Sorts<int>* sorter = new Sorts<int>();
  Test Runner(std::cout);
  while(loop == 'n')
  {
  printMenu();
  	std::cin >> n;
  
  
	std::cout << "Input a size for the random array: \n";
	std::cin>> size;
	std::cout << "Input a lower bound on the range of random numbers: \n";
	std::cin>> min;
	std::cout << "Input an upper bound on the range of random numbers: \n";
	std::cin>> max;
	int* temp = sorter->createTestArray(size, min, max);
	std::cout << "Do you want to print the unsorted array? (y/n): ";
	std::cin>> print;
	if(print == 'y')
	{
		std::cout << "Here is the unsorted array: \n [";
		printArray(temp,size);
	}
				

			
	switch(n)
		  {
			case 1:
			{
				std::cout << "Sorting with bubble sort...\n";
				sorter->bubbleSort(temp, size);
				std::cout << "Do you want to print the sorted array? (y/n): ";
				std::cin>> print;
				if(print == 'y')
				{
					std::cout << "Here is the sorted array: \n [";
					printArray(temp,size);
				}
				std::cout << size << " numbers were sorted in "<< Sorts<int>::sortTimer(Sorts<int>::insertionSort, temp, size) <<" seconds.\n";
			  break;
			}
			case 2:
			{
				std::cout << "Sorting with Insertion sort...\n";
				sorter->insertionSort(temp, size);
				std::cout << "Do you want to print the sorted array? (y/n): ";
				std::cin>> print;
				if(print == 'y')
				{
					std::cout << "Here is the sorted array: \n [";
					printArray(temp,size);
				}
				std::cout << size << " numbers were sorted in "<< Sorts<int>::sortTimer(Sorts<int>::insertionSort, temp, size) <<" seconds.\n";
			  break;
			}
			case 3:
			{
				std::cout << "Sorting with Selection sort...\n";
				sorter->selectionSort(temp, size);
				std::cout << "Do you want to print the sorted array? (y/n): ";
				std::cin>> print;
				if(print == 'y')
				{
					std::cout << "Here is the sorted array: \n [";
					printArray(temp,size);
				}
				std::cout << size << " numbers were sorted in "<< Sorts<int>::sortTimer(Sorts<int>::selectionSort, temp, size) <<" seconds.\n";
			  break;
			}
			case 4:
			{
				std::cout << "Sorting with bogo sort...\n";
				sorter->bogoSort(temp, size);
				std::cout << "Do you want to print the sorted array? (y/n): ";
				std::cin>> print;
				if(print == 'y')
				{
					std::cout << "Here is the sorted array: \n [";
					printArray(temp,size);
				}
				std::cout << size << " numbers were sorted in "<< Sorts<int>::sortTimer(Sorts<int>::bogoSort, temp, size) <<" seconds.\n";
			  break;
			}
			case 5:
			{
				Runner.runTests();
			  break;
			}
        case 6:
        {
                loop = 'y';
          break;
        }
			default:
				std::cout << "Sorry man that wasn't an option. Please enter another option.\n";
		}
		delete [] temp;
	}
	std::cout<<"Exiting......\n\n\n";
	delete sorter;
}
