/*
 * File:   Node.h
 * Author: Jack
 * Purpose: Declare all Node Members
 * Created on September 22, 2015, 12:01 PM
 */
#ifndef NODE_H
#define NODE_H


template<typename T>
class Node
{
public:
	Node();
	void setValue(T anItem);
	void setNext(Node<T>* nextNodePtr);
	void setPrevious(Node<T>* previousNodePtr);
	T getValue() const ;
	Node<T>* getNext() const ;
	Node<T>* getPrevious() const ;
private:
	T m_value; // A data item
	Node<T>* m_next; // Pointer to next node
	Node<T>* m_previous;

}; // end Node


#include "Node.hpp"
#endif
