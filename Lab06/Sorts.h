

#ifndef SORTS_H
#define SORTS_H
#include <random>
#include <cstdlib>
#include <functional>
#include <ctime>
#include <chrono>
#include <cassert>

template <typename T>
class Sorts
{
	public:
	
//	static void printArray(T arr[], int size);
	//Print Sort
	
	static void swap(T arr[], int a, int b);
	
	static void bubbleSort(T arr[], int size);
	//sorts arr using bubble sort algorithm discussed in class
	
	static void bogoSort(T arr[], int size);
	//sorts arr using bogo sort algorithm discussed in class
	
	static void insertionSort(T arr[], int size);
	//sorts arr using insertion sort algorithm discussed in class
	
	static void selectionSort(T arr[], int size);
	//sorts arr using selection sort
	
	static bool isSorted(T arr[], int size);
	//returns true is arr is in ascending order, false otherwise
	
	static void shuffle(T arr[], int size, std::default_random_engine& generator);
	//For each index in the array, swap it the value at another random index
	
	static int* createTestArray(int size, int min, int max);
	//creates a new array of the specified size and contains random values that fall within the range specified by min and max (inclusive)
	//not responsible for deleting the array
	
	static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);
	//arr is a vaild array of T of size elements, and the < operator is overloaded for T. sort must be capable of sorting arr in ascending order, or an assert will end the program.
	//after running, arr is sorted in ascending order
	//returns the time, in seconds, the sort required to sort arr.
	
	private:
	char print;
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;
};
#include "Sorts.hpp"
#endif