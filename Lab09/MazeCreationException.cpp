/*
 * File:   MazeCreationException.cpp
 * Author: Jack
 * Purpose: Exception handler
 * Created on November 16, 2015, 12:01 PM
 */

#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* message): std::runtime_error(message){};
