/*
 * File:   NumberFileGenerator.h
 * Author: Jack
 * Purpose: declares the geting numbers methods
 * Created on October 31, 2015, 12:01 PM
 */



#ifndef NUMGEN
#define NUMGEN
#include <string>
#include <fstream>
#include <random>
#include <ctime>

class NumberFileGenerator{

	public:

		static void ascending(std::string file, int amount);

		static void descending(std::string file, int amount);

		static void random(std::string file, int amount, int min, int max);

		static void singleValue(std::string file, int amount, int value);
};

#endif
