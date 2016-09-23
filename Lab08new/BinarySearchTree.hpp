/*
 * File:   BinarySearchTree.hpp
 * Author: Jack
 * Purpose: makes the binary tree
 * Created on October 31, 2015, 12:01 PM
 */


template<typename T>
BinarySearchTree<T>::BinarySearchTree(){
	m_root = nullptr;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other){

	m_root = new Node<T>(*(other.m_root));

}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
	deleteTree(m_root);
}

template<typename T>
BSTI<T>* BinarySearchTree<T>::clone(){

	BinarySearchTree<T>* temp = new BinarySearchTree<T>(*(this));
	return temp;
}

template<typename T>
bool BinarySearchTree<T>::isEmpty() const{

	return(m_root == nullptr);

}

template<typename T>
bool BinarySearchTree<T>::add(T value){//this method calls itself recursively, so we need this
					// wrapper so it can still be accessed from main
	return(add(value, m_root));

}

template<typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree){
	bool tracker = true;
	if(m_root == nullptr){
		Node<T>* n = new Node<T>();
		n->setValue(value);
		m_root = n;
		return true;
	}
	else{
		if(value < (subtree->getValue())){

			if(subtree->getLeft() != nullptr){//call recursively on LST
				tracker = add(value, subtree->getLeft());
			}
			else{
				Node<T>* n = new Node<T>();
				n->setValue(value);
				subtree->setLeft(n);
				return true;
			}
		}
		if(value >= subtree->getValue()){

			if(subtree->getRight() != nullptr){//call recursively on RST
				tracker = add(value, subtree->getRight());
			}
			else{
				Node<T>* n = new Node<T>();
				n->setValue(value);
				subtree->setRight(n);
				return true;
			}
		}
	}
	return tracker;
}

template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree){
	if(subtree == nullptr)
	{
		delete (subtree);
		subtree = nullptr;
		return;
	}
	if(subtree->getLeft() != nullptr){//if there is a left subtree
		deleteTree(subtree->getLeft());
	}
	if(subtree->getRight() != nullptr){//ditto for right
		deleteTree(subtree->getRight());
	}
	//at this point, there are no children of the current node, so we can delete and
	//return to the previous recursive call
	delete (subtree);
	subtree = nullptr;
	return;

}


template<typename T>
void BinarySearchTree<T>::printTree(Order order) const{//We have this method so we can call the other
	if(isEmpty()){				//recursively from main
		std::cout<<"Tree empty\n";
	}
	else{
		printTree(m_root, order);
	}
	std::cout<<"\n";
}


template<typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const{
	if(subtree == nullptr){
		return;
	}
	else{
		if(order == PRE_ORDER){
			std::cout<<(subtree->getValue())<<" ";
			printTree(subtree->getLeft(), PRE_ORDER);
			printTree(subtree->getRight(), PRE_ORDER);
		}
		else if(order == POST_ORDER){
			printTree(subtree->getLeft(), POST_ORDER);
			printTree(subtree->getRight(), POST_ORDER);
			std::cout<<(subtree->getValue())<<" ";
		}
		else{
			printTree(subtree->getLeft(), IN_ORDER);
			std::cout<<(subtree->getValue())<<" ";
			printTree(subtree->getRight(), IN_ORDER);
		}
	}
	return;
}

template<typename T>
bool BinarySearchTree<T>::search(T value)const {
	bool temp;

		temp = search(value, m_root);
		return temp;

}


template<typename T>
bool BinarySearchTree<T>::search(T value, Node<T>* subtree) const {
bool test;
	if(subtree == nullptr){
		return false;
	}
	else if((subtree->getValue())==value){//then, check current root value
		return true;
	}
	if(value < (subtree->getValue())){// try to check the left side
			test = search(value, subtree->getLeft());//this may throw and exception, which will
						//continue upstream and be caught immdeiately above
	}
	else{//check the right if necessary
		if(!((subtree->getValue())< value)){//the value is not in the left, so if it is not >= root,
							//then it isn't here
			return false;
		}
		else{
			test = search(value, subtree->getRight());
		}

	}
	return test;
}


template<typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order) const
{
	std::vector<T> vec;
	treeToVector(m_root, order, vec);
	return vec;
}

template<typename T>
void BinarySearchTree<T>::treeToVector(Node<T>* subtree, Order order, std::vector<T>& vec) const{
	if(subtree==nullptr)
	return;
	switch(order)
	{
	case Order::IN_ORDER:
	treeToVector(subtree->getLeft(), order, vec);
	vec.push_back(subtree->getValue());
	treeToVector(subtree->getRight(), order, vec);
	break;

	case Order::PRE_ORDER:
	vec.push_back(subtree->getValue());
	treeToVector(subtree->getLeft(), order, vec);
	treeToVector(subtree->getRight(), order, vec);
	break;

	case Order::POST_ORDER:
	treeToVector(subtree->getLeft(), order, vec);
	treeToVector(subtree->getRight(), order, vec);
	vec.push_back(subtree->getValue());
	break;
	}
	return;
}
