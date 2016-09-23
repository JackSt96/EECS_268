/**
*	@file Node.h
* 	@author Clayton Fasenmyer
*	@date 2015.09.19
*
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	public:
		Node();
		void setValue(int val);
		int getValue() const;
		void setNext(Node* prev);
		Node* getNext() const;
	private:
		int m_value;
		Node* m_next;
};
#endif
