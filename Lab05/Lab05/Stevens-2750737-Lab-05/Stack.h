/**
*	@file Stack.h
* @author Nick Bukaty
*	@date 2015.10.01
*
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

#include "Node.h"
#include "PreconditionViolationException.h"
#include "StackInterface.h"

template <typename T>
class Stack : public StackInterface<T>
{
public:
  /**
	*  @pre there are values on the stack
	*  @post Delete all elements in the stack
	*  @return nothing
	*/
  ~Stack();
  /**
  	*	@pre nothing
  	*	@post set to null ptr
  	*	@return nothing
  	*/
  Stack();

  /**
	*  @pre m_front != nullptr
	*  @post check if empty or not
	*  @return true if empty, false otherwise
	*/
  virtual bool isEmpty() const;

  /**
	*  @pre none
	*  @post entry added to top of stack
	*  @return void
	*/
  virtual void push(const T newEntry);

  /**
	*  @pre assumes stack is not empty
	*  @post top of stack is removed
	*  @return throws PreconditionViolationException when a pop is attempted on an empty stack. No return in this case
	*/
  virtual void pop() throw(PreconditionViolationException);

  /**
	*  @pre assumes the stack is not empty
	*  @post returns value at the top of the stack
	*  @return throws a PreconditionViolationException when a pop is attemptedon an empty stack. Does not return a value in this case
	*/
  virtual T peek() const throw(PreconditionViolationException);

  /**
  *  @pre none
  *  @post none
  *  @return size of the stack
  */
  virtual int size() const;

  /**
	*  @pre check if stack is empty
	*  @post prints the contents of the stack or prints the empty string if it is empty
	*  @return none
	*/
  virtual void print() const;
private:
	Node<T>* m_top;//a pointer to look at the top node
	int m_size;
};
#include "Stack.hpp"
#endif
