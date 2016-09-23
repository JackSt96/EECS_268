/*
 * File:   NumberFileDriver.h
 * Author: Jack
 * Purpose: declares the geting numbers methods
 * Created on October 31, 2015, 12:01 PM
 */


#ifndef NUMDRV
#define NUMDRV
#include <string>
#include <iostream>
#include <string>
#include "NumberFileGenerator.h"
#include <cstdlib>
#include <fstream>

class NumberFileDriver{

	public:

		static void run(int argc, char** argv);
/*
preconditionsarguments is a valid 2-D array and the arguments contained within are valid.
The argc and argv should be passed directly from main
post conditions If the arguments are valid, a number file is created following those specifications.Otherwise, the help menu is printed and no files are created.
returns None.
*/
		static void printHelpMenu();

	private:

		static bool isValidOption(std::string option);
/*
preconditionsNone.
post conditions Prints a menus to help the user use the NumberFileGenerator
returns True is the option passed in is valid. Valid options are: "-a", "-d", "-r", and "-s".	This is case sensitive.
*/


};

#endif
