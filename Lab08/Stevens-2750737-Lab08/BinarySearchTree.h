/*
 * File:   BinarySearchTree.h
 * Author: Jack
 * Purpose: declares the tree methods
 * Created on October 31, 2015, 12:01 PM
 */

#ifndef BTREE
#define BTREE
#include "BSTI.h"
#include <iostream>


template<typename T>
class BinarySearchTree: public BSTI<T>{

  private:

    Node<T>* m_root;
    //A pointer that is always looking at the root of the tree. Unlike our old friend, m_top, this pointer won't be moving around as nodes are added.

    bool add(T value, Node<T>* subtree);
    //adds the value to the correct branch (left or right) of the subtree
    //returns true if add operation was successful

    void deleteTree(Node<T>* subTree);
    //deletes the left subtree, right subtree, and root node of the subtree passed in

    bool search(T value, Node<T>* subtree) const;
    //returns: true if the value is in the tree, false otherwise

    void printTree(Node<T>* subtree, Order order) const;
    //prints the tree in PRE_ORDER or IN_ORDER or POST_ORDER using the subtree and the "order".

    void treeToVector(Node<T>* subtree, Order order, std::vector<T>& vec) const;
    //recursive helper function to load the vector, vec, in the specified order

  public:

    BinarySearchTree();
    //Constructor
    //Sets m_root to nullptr

    BinarySearchTree(const BinarySearchTree<T>& other);
    //Copy Constructor
    //Creates a deep copy of the other BST.
    //Hint: This method should be called in the clone() method

    ~BinarySearchTree();
    //Destructor
    //Calls private method, deleteTree(Node<T>* subTree) and passes in m_root as the starting point for deletion
    //Why don't we just pass a parameter into the destructor? C++ does not allow destructor to have parameters, but it can all other methods and pass parameters to them

    BSTI<T>* clone();
    //Creates a deep copy of this
    //Returns a pointer to a deep copy of this
    //Hint: This method uses your copy constructor

    bool isEmpty() const;
    //precondition: none
    //postcondition: none
    //returns: true if no nodes in the tree, otherwise returns false.

    bool add(T value);
    //adds the value to the tree
    //returns true if add operation was successful
    //Note: this public method will depend on calling a private method of the same name

    bool search(T value) const;
    //precondition: The type T is compa;rable by the == operator
    //returns: true if the value is in the tree, false otherwise
    //For a brief explanation as to why we have two version of some methods, please see the example below

    void printTree(Order order) const;
    //postcondition: the contents of the tree are printed to the console in the specified order

    std::vector<T> treeToVector(Order order) const;
    //returns a vector with the contents of the tree in the specified order is returned

};

  #include "BinarySearchTree.hpp"
  #endif
