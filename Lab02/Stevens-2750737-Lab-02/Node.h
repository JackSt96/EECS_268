/*
 * File:   Node.h
 * Author: Jack
 * Purpose: Declare all Node Members
 * Created on September 15, 2015, 12:01 PM
 */
#include <iostream>


#ifndef NODE_H
#define NODE_H

class Node {
  public:


  Node();
  //Constructor
  //Sets m_value to zero
  //Sets m_next to nullptr


  void setValue(int val);
  //sets m_value to val



  int getValue() const;
  //returns m_value



  void setNext(Node* prev);
  //sets m_next



  Node* getNext() const;
  //returns m_next


  private:
  int m_value;
  //the value in the node

  Node* m_next;
  //a pointer to another node

};


#endif
