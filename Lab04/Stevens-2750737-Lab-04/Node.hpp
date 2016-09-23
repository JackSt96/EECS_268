/*
 * File:   Node.hpp
 * Author: Jack
 * Purpose: Implement Node Members
 * Created on September 22, 2015, 12:01 PM
 */
#include "Node.h"
#ifndef NODE_HPP
#define NODE_HPP


template<typename T>
Node<T>::Node()
{
	m_value = T();
	m_next = nullptr; // Pointer to next node
	m_previous = nullptr;
} // end default constructor


template<typename T>
void Node<T>::setValue(T anItem)
{
	m_value = anItem;
} // end setItem


template<typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	m_next = nextNodePtr;
} // end setNext


template<typename T>
T Node<T>::getValue() const {
return m_value;
} // end getvalue


template<typename T>
Node<T>* Node<T>::getNext() const {
return m_next;
} // end getNext


template<typename T>
Node<T>* Node<T>::getPrevious() const {
	return m_previous;
} // end getNext


template<typename T>
void Node<T>::setPrevious(Node<T>* previousNodePtr)
{
	m_previous = previousNodePtr;
} // end setNext


#endif
