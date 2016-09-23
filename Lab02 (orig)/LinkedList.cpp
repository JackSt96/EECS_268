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

  bool LinkedList::isEmpty() const
  {
    
  }
//returns true if the list is empty, false otherwise.

  int LinkedList::size() const
  {

  }
//returns the number of elements in the list.


  bool LinkedList::search(T value) const
  {

  }
//returns true is the value is in the list, false otherwise.

  void LinkedList::printList() const
  {

  }
//prints the list to the console. "List empty" if it is empty

  void LinkedList::addBack(int value)
  {

  }
//One new element added to the end of the list.

  void LinkedList::addFront(int value)
  {
    Node* temp = nullptr;
    Node* last = nullptr;

//    if(isEmpty())
    {

    }
  }
//One new element added to the front of the list.

  bool LinkedList::removeBack(){

  }
//One element is removed from the back of the list.
//Returns true if the back element was removed, false if the list is empty.

  bool LinkedList::removeFront(){

  }
//One element is removed from the front of the list.
//returns True if the front element was removed, false if the list is empty.
