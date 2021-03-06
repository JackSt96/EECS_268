/*
 * File:   main.cpp
 * Author: Jack
 * Purpose: driver for the lab
 * Created on October 31, 2015, 12:01 PM
 */
#include <iostream>
#include <fstream>
#include "Node.h"
#include "Test.h"
#include "BSTI.h"
#include "BinarySearchTree.h"
#include <ctime>
#include <random>
#include <cassert>

void populate(BinarySearchTree<int>* myTree, int numVals){
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distr(-320000, 320000);
	int temp = 0;
	for(int i = 0; i<numVals; i++){
		temp = distr(generator);
		std::cout<<"Adding "<<temp<<" to original tree\n";
		assert(myTree->add(temp));
	}
	std::cout<<"\n";
}

void printMenu(){

	std::cout<<"Input a selection\n"
		 <<"1) Add more values to original tree\n"
		 <<"2) Copy the original tree\n"
		 <<"3) Delete the original tree (one time only)\n"
		 <<"4) Print original tree\n"
		 <<"5) Print copy\n"
		 <<"6) Search original tree\n"
		 <<"7) Search copy\n"
		 <<"8) Run tests\n"
		 <<"9) Exit\n"
		 <<"Your Choice: \n";

}

int main(int argc, char** argv){
	Test test;
	int choice = 0;
	int innerChoice;
	bool notDone = true;
	BSTI<int>* copy = nullptr;
	BinarySearchTree<int>* myTree = new BinarySearchTree<int>();

	std::cout<<"Arg count: "<<argc<<"\n";

	if((argc > 1)){ //if arguments are present
		std::string mode = (argv[1]);
		if(mode.compare("-test")==0){
			test.runTests();
		}
		else if(argv[1]>0){
		std::cout<<"Node count: "<<argv[1]<<"\n\n";
		std::cout<<"Filling original array with "<<(argv[1])<<" values.\n";
		std::cout<<std::atoi(argv[1])<<"\n";
		populate(myTree, std::atoi(argv[1]));
		}
	}
	else{
			std::cout<<"Node count: 0\n\n";
		}

	/////////////////////////////////////////////////////////////////////////////////////

	while(notDone){
		printMenu();
		std::cin>>choice;
		while(choice<=0){
			std::cout<<"Invalid choice.  Enter a number (1-8): \n";
			printMenu();
			std::cin>>choice;
		}
		std::cout<<"You chose: "<<choice<<"\n";
		switch(choice){

			case 1: if(myTree == nullptr){
					std::cout<<"This tree doesn't exist.  Cannot add.\n";
				}
				else{
					std::cout<<"Input a value to add to the original: ";
					std::cin>>innerChoice;
					std::cout<<"Adding "<<innerChoice<<" to the original tree.\n";
					myTree->add(innerChoice);
				} break;

			case 2: if(myTree == nullptr){
					std::cout<<"This tree doesn't exist.  Cannot copy.\n";
				}
				else{
					std::cout<<"Original tree copied into 'copy'\n";
					copy = (BinarySearchTree<int>*)myTree->clone();
				} break;

			case 3: if(myTree == nullptr){
					std::cout<<"This tree doesn't exist.  Cannot delete.\n";
				}
				else{
					delete myTree;
					myTree = nullptr;
					std::cout<<"Original tree deleted.\n";
				} break;

			case 4: if((myTree == nullptr)||(myTree->isEmpty())){
					std::cout<<"This tree doesn't exist.  Cannot print.\n";
				}
				else{
					innerChoice = -5; //hackity hack
					while((innerChoice < 0) || (innerChoice > 2)){
						std::cout<<"Print options:\n"
							 <<"0 - pre-order\n"
							 <<"1 - in-order\n"
							 <<"2 - post-order\n"
							 <<"Choice: ";
						std::cin>>innerChoice;
						if((innerChoice < 0)||(innerChoice > 2)){std::cout<<"Invalid choice\n";}
					}
					std::cout<<"You chose: "<<innerChoice<<"\n";
					if(innerChoice==0){myTree->printTree(PRE_ORDER);}
					else if(innerChoice==1){myTree->printTree(IN_ORDER);}
					else{ myTree->printTree(POST_ORDER);}
				} break;

			case 5: if((copy == nullptr)||(copy->isEmpty())){
					std::cout<<"This tree doesn't exist.  Cannot print.\n";
				}
				else{
					innerChoice = -5; //hackity hack
					while((innerChoice < 0) || (innerChoice > 2)){
						std::cout<<"Print options:\n"
							 <<"0 - pre-order\n"
							 <<"1 - in-order\n"
							 <<"2 - post-order\n"
							 <<"Choice: ";
						std::cin>>innerChoice;
						if((innerChoice < 0)||(innerChoice > 2)){std::cout<<"Invalid choice\n";}
					}
					std::cout<<"You chose: "<<innerChoice<<"\n";
					if(innerChoice==0){copy->printTree(PRE_ORDER);}
					else if(innerChoice==1){copy->printTree(IN_ORDER);}
					else{ copy->printTree(POST_ORDER);}
				} break;

			case 6: if((myTree == nullptr)||(myTree->isEmpty())){
					std::cout<<"This tree doesn't exist.  Cannot search.\n";
				}
				else{
					std::cout<<"Enter a value to search for: \n";
					std::cin>>innerChoice;
					int temp;
					try{
						temp = (myTree->search(innerChoice));
						std::cout<<temp<<" was found in the tree.\n";
					}
					catch(std::exception& e){
						std::cout<<e.what();
					}
				} break;

			case 7: if((copy == nullptr)||(copy->isEmpty())){
					std::cout<<"This tree doesn't exist.  Cannot search.\n";
				}
				else{
					std::cout<<"Enter a value to search for: \n";
					std::cin>>innerChoice;
					int temp;
					try{
						temp = (copy->search(innerChoice));
						std::cout<<temp<<" was found in the tree.\n";
					}
					catch(std::exception& e){
						std::cout<<e.what();
					}
				}break;
			case 8:
			test.runTests();
			break;
			case 9: notDone = false; break;

			default: break;

		}
		std::cout<<"\n";
	}
	std::cout<<"Exiting...\n\n\n";
	delete copy;
	delete myTree;

return 0;
}
