/*
 * File:   SortDriver.h
 * Author: Jack
 * Purpose: declares the sort methods
 * Created on October 31, 2015, 12:01 PM
 */

#ifndef SORTDRIVER_H
#define SORTDRIVER_H
#include <fstream>
#include <iostream>
#include "Sorts.h"
#include <cstdlib>
#include <string>
#include <functional>

class SortDriver
{

public:
	static void printHelpMenu();

	static void run(int argc, char** argv);
	//preconditionsarguments is a valid 2-D array and the arguments contained within are valid.
	//The argc and argv should be passed directly from main
	//A file is created containing the timing information of the chosen sort(s) on the supplied file.

private:
	static bool isFileAccessible(std::string fileName);
	//preconditionsThe input file was created by a NumberFileGenerator.
	//returns True if the file exists, false otherwise.
	static bool isSortValid(std::string sortParameter);
	//preconditionsNone.
	//post conditions None.
	//returns True if the sort parameter matches a valid one (see help menu).
	static bool areParametersValid(std::string sortName, std::string inputFileName);
	//preconditionsNone.
	//post conditions None.
	//returns True is the file specified by inputFileName exists and the sort parameter is valid, false otherwise.
	static int getFileCount(std::ifstream& inputFile);
	//preconditionsThe input file was created with the Number File Generator
	//post conditions The first line of the file is read in, containing the count.
	//returns Returns how many numbers are in the file.
	static int* createArray(std::ifstream& inputFile, int size);
	//preconditionsThe input file was created with the Number File Generator, the size was read in, and that size if correct.
	//post conditions The remainder of input file numbers are read in. File is NOT closed.
	//returns A pointer to a new array containing the values from the input file.
	static void copyArray(int original[], int copy[], int size);
	//preconditionsOriginal and copy are valid arrays of the correct size.
	//post conditions All values from original are copied into copy.
	//returns None.


};

#endif
