/*
 * File:   DoubleLinkedList.hpp
 * Author: Jack
 * Purpose: implement members of the DoubleLinkedList class
 * Created on September 22, 2015, 12:01 PM
 */
#include "DoubleLinkedList.h"
#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    m_size = 0;
    m_front = nullptr;
    m_back = nullptr;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
  while(size() != 0)
	{
		removeFront();
	}
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() const
  {
    if(m_front != nullptr)
	{
		return false;
	}
	else{
		return true;
	}
  }


template<typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	Node<T>* tempFront;
  tempFront = (Node<T>*)malloc(sizeof(Node<T>));
  if(m_front != nullptr)
	{
  	tempFront->setValue(value);
  	tempFront->setNext(m_front);
  	m_front = tempFront;
  	m_back = tempFront;
	}
	else
	{
  tempFront->setValue(value);
  tempFront->setNext(m_front);
  m_front = tempFront;
	}
    std::cout<<"Value Inserted"<<std::endl;

    m_size++;
}

/*
 * Insertion of element at a particular position
 */

template<typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
	Node<T>* tempBack;
    tempBack = (Node<T>*)malloc(sizeof(Node<T>));
    if (m_front != nullptr)
    {
		tempBack = m_front;
		while(tempBack->getNext() != nullptr)
		{
			tempBack = tempBack -> getNext();
		}
		Node<T>* tempBack2;
      tempBack2 = (Node<T>*)malloc(sizeof(Node<T>));
		tempBack2->setValue(value);
		tempBack2->setNext(nullptr);
		tempBack2->setPrevious(tempBack);
		tempBack->setNext(tempBack2);
		m_back = tempBack;
        return;
    }
	else{
		tempBack->setValue(value);
		tempBack->setNext(nullptr);
		tempBack->setPrevious(nullptr);
		m_front = tempBack;
	}
    std::cout<<"Value Inserted"<<std::endl;
}

/*
 * Deletion of element from the list
 */

template<typename T>
bool DoubleLinkedList<T>::removeBack()
 {
	if(m_front != nullptr)
	{
		Node<T>* tempRemove;
      tempRemove = (Node<T>*)malloc(sizeof(Node<T>));
		tempRemove = m_front;
		Node<T>* switcher;
      switcher = (Node<T>*)malloc(sizeof(Node<T>));
		while(tempRemove->getNext() != nullptr)
		{
			switcher = tempRemove;
			tempRemove = tempRemove->getNext();
		}
		m_back = tempRemove->getPrevious();
		if(tempRemove == m_front)
			m_front = nullptr;
		switcher->setNext(nullptr);
		delete tempRemove;
		return true;
	}
	else
		return false;
}



template<typename T>
bool DoubleLinkedList<T>::removeFront(){
	if(m_front != nullptr)
	{
		Node<T>* tempRemove;
      tempRemove = (Node<T>*)malloc(sizeof(Node<T>));
		tempRemove = m_front;
		tempRemove->setPrevious(nullptr);
		m_front = tempRemove->getNext();
		delete tempRemove;
		return true;
	}
	else
		return false;
  }



template<typename T>
bool DoubleLinkedList<T>::remove(T value)
{
  if(m_front != nullptr)
	{
	Node<T>* tempRemove;
    tempRemove = (Node<T>*)malloc(sizeof(Node<T>));
	Node<T>* tempRemove2;
    tempRemove2 = (Node<T>*)malloc(sizeof(Node<T>));
     /*first element deletion*/
    if (m_front->getValue() == value)
    {
		tempRemove = m_front;
		tempRemove->setPrevious(nullptr);
		m_front = tempRemove->getNext();
		delete tempRemove;
        std::cout<<"Value Deleted"<<std::endl;
        return true;
    }
    if(m_front->getNext() == nullptr)
    return false;
    tempRemove = m_front;
    while (tempRemove->getNext()->getNext() != NULL)
    {
        if (tempRemove->getNext()->getValue() == value)
        {
            tempRemove2 = tempRemove->getNext();
            tempRemove->setNext(tempRemove2->getNext());
            tempRemove2->getNext()->setPrevious(tempRemove);
            std::cout<<"Value Deleted"<<std::endl;
			         delete tempRemove2;
            return true;
        }
        tempRemove = tempRemove->getNext();
    }
     /*last element deleted*/
    if (tempRemove->getNext()->getValue() == value)
    {
		tempRemove2 = tempRemove->getNext();
        delete tempRemove2;
        tempRemove->setNext(nullptr);
        std::cout<<"Value Deleted"<<std::endl;
        return true;
    }
  }
  else
    std::cout<<"Value "<<value<<" not found"<<std::endl;
	return false;
}



template<typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error)
{
  if(m_front != nullptr)
	{
  Node<T>* tempAhead;
    tempAhead = (Node<T>*)malloc(sizeof(Node<T>));
    if (m_front->getValue() == listValue)
    {
      tempAhead->setValue(newValue);
      tempAhead->setNext(m_front);
      m_front = tempAhead;
      return;
    }
    if(m_front->getNext() == nullptr)
    {
      throw(std::runtime_error("Not in list"));
    return;
    }
    tempAhead = m_front;
    Node<T>* tempAhead2;
      tempAhead2 = (Node<T>*)malloc(sizeof(Node<T>));
    while (tempAhead->getNext()->getNext() != NULL)
    {
        if (tempAhead->getNext()->getValue() == listValue)
        {
            tempAhead2 -> setValue(newValue);
            tempAhead2 -> setNext(tempAhead->getNext());
            tempAhead2 ->setPrevious(tempAhead);
            tempAhead ->setNext(tempAhead2);
            return;
        }
        tempAhead = tempAhead->getNext();
    }
     /*last element deleted*/
    if (tempAhead->getNext()->getValue() == listValue)
    {
      tempAhead2->setValue(newValue);
      tempAhead2->setNext(tempAhead->getNext());
      tempAhead2->setPrevious(tempAhead);
      tempAhead->setNext(tempAhead2);
      m_back = tempAhead;
      return;
    }
  }
  throw(std::runtime_error("Not in list"));
    std::cout<<"Value "<< listValue<<" not found"<<std::endl;
}


template<typename T>
    int DoubleLinkedList<T>::size() const
{
    int size = 0;
    Node<T>* temp;
    temp = (Node<T>*)malloc(sizeof(Node<T>));
    temp = m_front;
    while(temp != nullptr)
    {
      size++;
      temp = temp->getNext();
    }
    delete temp;
    return size;
}

template<typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const
{
  if(m_front != nullptr)
	{
  Node<T>* temp;
    temp = (Node<T>*)malloc(sizeof(Node<T>));
    if (m_front->getValue() == value)
    {
      return m_front;
    }
    if(m_front->getNext() == nullptr)
    return nullptr;
    temp = m_front;
    Node<T>* temp2;
      temp2 = (Node<T>*)malloc(sizeof(Node<T>));
    while (temp->getNext()->getNext() != NULL)
    {
        if (temp->getNext()->getValue() == value)
        {
            temp2 = temp->getNext();
            return temp2;
        }
        temp = temp->getNext();
    }
     /*last element deleted*/
     if (temp->getNext()->getValue() == value)
     {
         temp2 = temp->getNext();
         return temp2;
     }
  }
  return nullptr;
}


template<typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error)
{
  if(m_front != nullptr)
  {
  Node<T>* tempBehind;
    tempBehind = (Node<T>*)malloc(sizeof(Node<T>));
    if (m_front->getValue() == listValue)
    {
      tempBehind->setValue(newValue);
      tempBehind->setPrevious(m_front);
      tempBehind->setNext(m_front->getNext());
      m_front -> setNext(tempBehind);
      return;
    }
    if(m_front->getNext() == nullptr)
    {
      throw(std::runtime_error("Not in list"));
    return;
    }
    tempBehind = m_front;
    Node<T>* tempBehind2;
      tempBehind2 = (Node<T>*)malloc(sizeof(Node<T>));
      while (tempBehind->getNext()->getNext() != NULL)
      {
          if (tempBehind->getNext()->getValue() == listValue)
          {
            tempBehind = tempBehind->getNext();
            tempBehind2 -> setValue(newValue);
            tempBehind2 -> setNext(tempBehind->getNext());
            tempBehind2 ->setPrevious(tempBehind);
            tempBehind ->setNext(tempBehind2);
              return;
          }
          tempBehind = tempBehind->getNext();
      }
      if (tempBehind->getNext()->getValue() == listValue)
      {
        tempBehind = tempBehind->getNext();
        tempBehind2->setValue(newValue);
        tempBehind2->setNext(tempBehind->getNext());
        tempBehind2->setPrevious(tempBehind);
        tempBehind->setNext(tempBehind2);
        m_back = tempBehind;
        return;
      }
  }
  std::cout<<"Value "<< listValue<<" not found"<<std::endl;
        throw(std::runtime_error("Not in list"));
}


/*
 * Display elements of Doubly Link List
 */
template<typename T>
void DoubleLinkedList<T>::printList()
{
	Node<T>* tempPrint;
    tempPrint = (Node<T>*)malloc(sizeof(Node<T>));
    if (m_front != nullptr)
    {
        tempPrint = m_front;
        while(tempPrint != nullptr)
		      {
			         std::cout << tempPrint->getValue() << " ";
			            tempPrint = tempPrint->getNext();
		}
    }
}
#endif
