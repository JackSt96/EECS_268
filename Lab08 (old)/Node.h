/**

*/


#ifndef NODE
#define NODE
template<typename T>

class Node{

	public:


		Node();


		Node(const Node<T>& other);


		T getValue() const;


		Node<T>* getLeft() const;


		Node<T>* getRight() const;


		void setValue(T value);


		void setLeft(Node<T>* left);


		void setRight(Node<T>* right);

	private:

		Node<T>* m_left;
		Node<T>* m_right;
		T m_value;

};

#include "Node.hpp"
#endif
