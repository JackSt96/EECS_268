/**
*	@file LinkedList.h
* 	@author Clayton Fasenmyer
*	@date 2015.09.19
*
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		bool isEmpty() const;
		int size() const;
		bool search(int value) const;
		void printList() const;
		void addBack(int value);
		void addFront(int value);
		bool removeBack();
		bool removeFront();
		
	private:
		Node* m_front;
		int m_size;
};
#endif
