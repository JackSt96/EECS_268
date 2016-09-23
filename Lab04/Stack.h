/*
 * File:   DoubleLinkedList.hpp
 * Author: Jack
 * Purpose: implement members of the DoubleLinkedList class
 * Created on September 22, 2015, 12:01 PM
 */

#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"


template <typename T>
class Stack: public StackInterface<T>
{
    public:
    Stack();

    ~Stack();

    bool isEmpty() const;

    void push(const T newEntry);

    void pop() throw(PreconditionViolationException);

    T peek() const throw(PreconditionViolationException);

    int size() const;

    void print() const;
private:
    Node<T>* m_stack;
};

#include "Stack.hpp"
#endif
