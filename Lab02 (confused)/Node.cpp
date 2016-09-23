/*
 * File:   Node.h
 * Author: Jack
 * Purpose: Declare all Node Members
 * Created on September 15, 2015, 12:01 PM
 */
#include <iostream>


#ifdef NODE_H
#define NODE_H

class Node {


  Node::Node(){
	  m_value = 0;
	  m_next = nullptr;
  }
  //Constructor
  //Sets m_value to zero
  //Sets m_next to nullptr


  void Node::setValue(int val){
	  m_value = val;
  }
  //sets m_value to val



  int Node::getValue() const{
	  return m_value;
  }
  //returns m_value



  void Node::setNext(Node* prev){
	  m_next = prev;
  }
  //sets m_next



  Node* Node::getNext() const{
	  return m_next;
  }
  //returns m_next



};


#endif
