/**
*	@file Stack.hpp
* @author Jack Stevens
*	@date 2015.10.01
*
*/
#include "Stack.h"

template <typename T>
Stack<T>::Stack()
{
	m_top = nullptr;
	m_size = 0;
}


template <typename T>
Stack<T>::~Stack()
{
	Node<T>* m_delete = m_top;
	while(m_top != nullptr)
	{
		m_top = m_delete -> getNext();
		delete m_delete;
		m_delete = m_top;
	}
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	if(m_top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
void Stack<T>::push(const T newEntry)
{
	Node<T>* m_push = new Node<T>();
	m_push -> setValue(newEntry);
	m_push -> setNext(m_top);
	m_top = m_push;
	m_size++;
}

template <typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
	if(!isEmpty())
	{

		Node<T>* topDelete;
		topDelete = m_top;
		m_top = topDelete -> getNext();
		delete topDelete;
		m_size--;
	}
	else
	{
		throw(PreconditionViolationException("Pop called on empty stack"));
	}
}

template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
	if(!isEmpty())
	{
		return m_top -> getValue();
	}
	else
	{
		throw(PreconditionViolationException("Peek called on empty stack."));
	}
}

template <typename T>
int Stack<T>::size() const
{
	return m_size;
}

template <typename T>
void Stack<T>::print() const
{
	if(!isEmpty())
	{
		Node<T>* m_print;
		m_print = m_top;
		while(m_print != nullptr)
		{
			std::cout << m_print -> getValue() << " ";
			m_print = m_print -> getNext();
		}
	}
	else
	{
		std::cout << "";
	}
}
