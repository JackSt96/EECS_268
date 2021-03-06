/*
 * File:   main.cpp
 * Author: Jack
 * Purpose:
 * Created on September 15, 2015, 12:01 PM
 */
#include <iostream>
#include "SortDriver.h"
#include <string>
#include "NumberFileDriver.h"
#include "Test.h"

int main(int argc, char** argv){
  Test test(std::cout);
	if(argc<5){
		std::cout<<"Invalid number of arguments\n";
		NumberFileDriver::printHelpMenu();
	}
	
	std::string mode = (argv[1]);
	if(mode.compare("-create")==0){

		NumberFileDriver::run(argc, argv);

	}
	else if(mode.compare("-sort")==0){

		SortDriver::run(argc, argv);

	}
	//Check for test flag
	else if (mode == "-test")
	{
		test.runTests();
	}
	else{

		std::cout<<"Invalid parameters.  Check the order of your options\n";
		NumberFileDriver::printHelpMenu();
		SortDriver::printHelpMenu();

	}

return 0;

}
