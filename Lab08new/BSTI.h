/*
 * File:   BSTI.h
 * Author: Jack
 * Purpose: manages the tree methods
 * Created on October 31, 2015, 12:01 PM
 */


#ifndef BST_I
#define BST_I
#include "Node.h"
#include <vector>

enum Order{PRE_ORDER, IN_ORDER, POST_ORDER};

template<typename T>
class BSTI{

  public:
      virtual ~BSTI(){};
      //precondition: A BSTI exists
      //postcondition: Deletes the entire tree
      virtual BSTI<T>* clone() = 0;
      //precondition: this is in a valid state
      //postcondition: Creates a deep copy of this
      //returns: Returns a pointer to a deep copy of this
      virtual bool isEmpty() const = 0;
      //precondition: none
      //postcondition: none
      //returns: true if no nodes in the tree, otherwise returns false.
      virtual bool add(T value) = 0;
      //precondition: value is a valid T
      //postcondition: a new Node<T> is created an inserted into the tree based
      //returns: false if the value couldn't be added (i.e. duplicate values not allowed)
      virtual bool search(T value) const = 0;
      //precondition: The type T is comparable by the == operator
      //returns: true if the value is in the tree, false otherwise

      virtual void printTree(Order order) const = 0;
      //postcondition: the contents of the tree are printed to the console in the specified order
      virtual std::vector<T> treeToVector(Order order) const = 0;
      //returns a vector with the contents of the tree in the specified order is returned`


};

#endif
