/*
 * File:   main.cpp
 * Author: Jack
 * Purpose: main driver
 * Created on November 16, 2015, 12:01 PM
 */


#include "MazeReader.h"
#include "MazeCreationException.h"
#include <iostream>
#include <string>
#include "MazeWalker.h"
#include "Test.h"


int main(int argc, char** argv){



	Search mySearch;
	std::string choice(argv[1]);
	if(choice == "-test")
	{
		Test test;
		test.runTests();
		return 0;
	}
	if(argc<3){
		std::cout<<"Invalid number of arguments\nEnter: [executable] [filename.ext] [-bfs or -dfs]\n";
		return -1;
	}
	if(choice=="-bfs"){
		mySearch = Search::BFS;
	}
	else if(choice == "-dfs"){
		mySearch = Search::DFS;
	}
	else{
		std::cout<<"Invalid search choice.  Enter -dfs or -bfs\n";
		return -1;
	}

	std::string myFile(argv[1]);
	MazeReader* myMazeReader = new MazeReader(myFile);
	std::cout<<"Success!\n";

	const char* const* theMaze = myMazeReader->getMaze();
	MazeWalker* workHorse = new MazeWalker
		(theMaze, myMazeReader->getStartRow(), myMazeReader->getStartCol(), myMazeReader->getRows(), myMazeReader->getCols(), mySearch);
	if(workHorse->walkMaze()){
		std::cout<<"Exit Found!\n";
	}
	else{
		std::cout<<"No way out!\n";
	}
	delete workHorse;
	delete myMazeReader;
	theMaze = nullptr;
	workHorse = nullptr;
	myMazeReader = nullptr;

return 0;
}
