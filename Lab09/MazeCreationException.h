/*
 * File:   MazeCreationException.h
 * Author: Jack
 * Purpose: declare the name of the exceptions
 * Created on November 16, 2015, 12:01 PM
 */

#ifndef MEX
#define MEX
#include <exception>
#include <stdexcept>
class MazeCreationException: public std::runtime_error{
	public:
	MazeCreationException(const char* message);

};

#endif
