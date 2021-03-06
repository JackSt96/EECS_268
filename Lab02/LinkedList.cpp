/*
 * File:   Colosseum.cpp
 * Author: Jack
 * Purpose: Handle all the fights, building, and playing of the Pokemon.
 * Created on September 3, 2015, 12:01 AM
 */

#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>


LinkedList::LinkedList()
{
  m_front = nullptr;
  m_size = 0;
}
LinkedList::~LinkedList()
{
	while(size() != 0)
	{
		removeFront();
	}
}

bool LinkedList::isEmpty() const
  {
    if(m_front != nullptr)
	{
		return false;
	}
	else{
		return true;
	}
  }
//returns true if the list is empty, false otherwise.

int LinkedList::size() const
  {
	int size = 0;
	Node* temp;
  temp = (Node*)malloc(sizeof(Node));
	temp = m_front;
	while(temp != nullptr)
	{
		size++;
		temp = temp->getNext();
	}
	return size;
  }
//returns the number of elements in the list.


bool LinkedList::search(int value) const
  {
	bool found = false;
	Node* tempFound;
  tempFound = (Node*)malloc(sizeof(Node));
	tempFound = m_front;
	while(tempFound != nullptr)
	{
		if(tempFound->getValue() == value)
		{
			found = true;
			break;
		}
		tempFound = tempFound->getNext();
	}
	return found;
  }
//returns true is the value is in the list, false otherwise.

void LinkedList::printList() const
  {
	if(m_front != nullptr)
	{
		Node* tempPrint;
    tempPrint = (Node*)malloc(sizeof(Node));
		tempPrint = m_front;
		while(tempPrint != nullptr)
		{
			std::cout << tempPrint->getValue() << ' ';
			tempPrint = tempPrint->getNext();
		}
    std::cout << "\n";
	}
}
//prints the list to the console. "List empty" if it is empty

void LinkedList::addBack(int value)
  {
	Node* tempBack;
	tempBack = (Node*)malloc(sizeof(Node));
	if(m_front != nullptr)
	{
		tempBack = m_front;
		while(tempBack->getNext() != nullptr)
		{
			tempBack = tempBack -> getNext();
		}
		Node* tempBack2;
	  tempBack2 = (Node*)malloc(sizeof(Node));
		tempBack2->setValue(value);
		tempBack2->setNext(nullptr);
		tempBack->setNext(tempBack2);
	}
	else{
		tempBack->setValue(value);
		m_front = tempBack;
	}
  }
//One new element added to the end of the list.

void LinkedList::addFront(int value)
  {

	Node* tempFront;
	tempFront = (Node*)malloc(sizeof(Node));
	tempFront->setNext(m_front);
	tempFront->setValue(value);
	m_front = tempFront;
  }
//One new element added to the front of the list.

bool LinkedList::removeBack(){
	if(m_front != nullptr)
	{
		Node* tempRemove;
    tempRemove = (Node*)malloc(sizeof(Node));
		tempRemove = m_front;
		Node* switcher;
		while(tempRemove->getNext() != nullptr)
		{
			switcher = tempRemove;
			tempRemove = tempRemove->getNext();
		}
		if(tempRemove == m_front)
			m_front = nullptr;
		switcher->setNext(nullptr);
		delete tempRemove;
		return true;
	}
	else
		return false;
  }
//One element is removed from the back of the list.
//Returns true if the back element was removed, false if the list is empty.

bool LinkedList::removeFront(){
	if(m_front != nullptr)
	{
		Node* tempRemove;
    tempRemove = (Node*)malloc(sizeof(Node));
		tempRemove = m_front;
		m_front = tempRemove->getNext();
		delete tempRemove;
		return true;
	}
	else
		return false;
  }
//One element is removed from the front of the list.
//returns True if the front element was removed, false if the list is empty.
