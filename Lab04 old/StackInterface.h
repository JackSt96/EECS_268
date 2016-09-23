/*
 * File:   StackInterface.h
 * Author: Jack
 * Purpose:
 * Created on September 30, 2015, 2:01 PM
 */
class StackInterface{

public:
    virtual ~StackInterface() {};
    virtual bool isEmpty() const = 0;
    //returns true if the stack is empty, false otherwise

    virtual void push(const T newEntry) = 0;
    //Entry added to top of stack

    virtual void pop() throw(PreconditionViolationException) = 0;
    //assumes the stack is not empty
    //top of the stack is removed
    //throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.

    virtual T peek() const throw(PreconditionViolationException) = 0;
    //assumes the stack is not empty
    //returns the value at the top of the stack
    //throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case.

    virtual int size() const = 0;
    //returns the size of the stack

    virtual void print() const = 0;
    //prints the contents of the stack or prints the empty string if it is empty
    //Example: If you push 5, push 10, and push 15 note that the printing of the stack should print "15 10 5"
 }
