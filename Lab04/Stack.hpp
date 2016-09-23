
/*
 * File:   DoubleLinkedList.hpp
 * Author: Jack
 * Purpose: implement members of the DoubleLinkedList class
 * Created on September 22, 2015, 12:01 PM
 */


#ifndef STACK_HPP
#define STACK_HPP
#include "Stack.h"
#include <iostream>
#include <cstdlib>

template<typename T>
Stack<T>::Stack()
{
    m_stack = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
  while(size() != 0)
  {
    pop();
  }
}


template<typename T>
bool Stack<T>::isEmpty() const
{
	if(m_stack != nullptr)
	{
		return false;
	}
	else{
		throw(PreconditionViolationException("Not in list"));
	}
}

template<typename T>
void Stack<T>::push(const T newEntry)
{
	Node<T>* tempFront = new Node<T>();
  tempFront->setValue(newEntry);
  tempFront->setNext(m_stack);
  m_stack = tempFront;
}

template<typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
	if(m_stack != nullptr){
		Node<T>* tempRemove = new Node<T>();
		tempRemove = m_stack;
    tempRemove->setPrevious(nullptr);
		m_stack = tempRemove->getNext();
		delete tempRemove;
	}
	else{
		throw(PreconditionViolationException("Not in list"));
	}
}

template<typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
  if(m_stack != nullptr){
	return (m_stack->getValue());
}
else
  throw(PreconditionViolationException("Not in list"));
}

template<typename T>
int Stack<T>::size() const
{
    int size = 0;
    Node<T>* temp  = new Node<T>();
    temp = m_stack;
    while(temp != nullptr)
    {
      size++;
      temp = temp->getNext();
    }
    delete temp;
    return size;
}

template<typename T>
void Stack<T>::print() const
{
	Node<T>* tempPrint  = nullptr;
    if (m_stack != nullptr)
    {
        tempPrint = m_stack;
        while(tempPrint != nullptr)
		      {
			         std::cout << tempPrint->getValue() << " ";
			            tempPrint = tempPrint->getNext();
		}
    }
//	delete tempPrint;
}


#endif
