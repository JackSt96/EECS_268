/**
*	@file LinkedList.cpp
* 	@author Clayton Fasenmyer
*	@date 2015.09.19
*
*/

#include "Node.h"
#include "LinkedList.h"

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
	if(m_front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int LinkedList::size() const
{
	int count = 0;
	Node* tempNode;
	tempNode = (Node*)malloc(sizeof(Node));
	tempNode = m_front;
	while(tempNode != NULL)
	{
		count++;
		tempNode = tempNode->getNext();
	}
	return count;
}
bool LinkedList::search(int value) const
{
	bool found = false;
	Node* tempNode;
	tempNode = (Node*)malloc(sizeof(Node));
	tempNode = m_front;
	while(tempNode != NULL)
	{
		if(tempNode->getValue() == value)
		{
			found = true;
			break;
		}
		tempNode = tempNode->getNext();
	}
	return found;
	
}
void LinkedList::printList() const
{
	if(m_front != NULL)
	{
		Node* tempNode;
		tempNode = (Node*)malloc(sizeof(Node));
		tempNode = m_front;
		while(tempNode != NULL)
		{
			std::cout << tempNode->getValue() << " ";
			tempNode = tempNode->getNext();
		}
		std::cout << "\n";
	}
}
void LinkedList::addBack(int value)
{
	Node* tempNode1;
	tempNode1 = (Node*)malloc(sizeof(Node));
	if(m_front != NULL)
	{
		tempNode1 = m_front;
		while(tempNode1->getNext() != NULL)
		{
			tempNode1 = tempNode1->getNext();
		} 
		Node* tempNode;
		tempNode = (Node*)malloc(sizeof(Node));
		tempNode->setValue(value);
		tempNode->setNext(NULL);
		tempNode1->setNext(tempNode);
	}
	else
	{
		tempNode1->setValue(value);
		m_front = tempNode1;
	}
		
}
void LinkedList::addFront(int value)
{
	Node* tempNode;
	tempNode = (Node*)malloc(sizeof(Node));
	tempNode->setNext(m_front);
	tempNode->setValue(value);
	m_front = tempNode;
}
bool LinkedList::removeBack()
{
	if(m_front != NULL)
	{
		Node* tempNode;
		tempNode = (Node*)malloc(sizeof(Node));
		tempNode = m_front;
		Node* oldTemp;
		oldTemp = (Node*)malloc(sizeof(Node));
		while(tempNode->getNext() != NULL)
		{
			oldTemp = tempNode;
			tempNode = tempNode->getNext();
		}
		if(tempNode == m_front)
			m_front = nullptr;
		oldTemp->setNext(NULL);
		free(tempNode);
		return true;
	}
	else
		return false;
}
bool LinkedList::removeFront()
{
	if(m_front != NULL)
	{
		Node* tempNode;
		tempNode = (Node*)malloc(sizeof(Node));
		tempNode = m_front;
		m_front = tempNode->getNext();
		free(tempNode);
		return true;
	}
	else
		return false;
}



