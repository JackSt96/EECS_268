/*
 * File:   DoubleLinkedList.h
 * Author: Jack
 * Purpose: Declare all double linked list  Members
 * Created on September 22, 2015, 12:01 PM
 */
#include "Node.h"
#include <iostream>
#include <string>
#include <cstdlib>
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template<typename T>
class DoubleLinkedList
{
    public:
//        void create_list(int value);
    Node<T>* find(T value) const;
    int size() const;


    void pushFront(T value);


    void pushBack(T value);


    bool remove(T value);


    bool removeFront();


    bool removeBack();


    void search_element(int value);


    void insertAhead(T listValue, T newValue) throw (std::runtime_error); //throw (std::runtime_error)


    void insertBehind(T listValue, T newValue) throw (std::runtime_error); //throw (std::runtime_error)


    void printList();


    bool isEmpty() const;
		//returns true if the list is empty, false otherwise.
    DoubleLinkedList();
    ~DoubleLinkedList();


  private:
		Node<T>* m_front;
		Node<T>* m_back;
		int m_size;
};


#include "DoubleLinkedList.hpp"
#endif
