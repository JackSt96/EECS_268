

#ifndef STACK_H
#define STACK_H
#include "Node.h"

template <typename T>
class Stack:public StackInterface
{
public:
    Stack();

    virtual bool isEmpty();

    virtual void push(const T newEntry);

    virtual void pop() throw(PreconditionViolationException);

    virtual T peek() const throw(PreconditionViolationException);

    virtual int size() const;

    virtual void print() const;
private:
    Node<T>* 
}

#include "Stack.hpp"
#endif
