/*
 * File:   LinkedList.h
 * Author: Jack
 * Purpose: Declare all LinkedList Members
 * Created on September 15, 2015, 12:01 PM
 */
 #include "Node.h"

 #ifndef LINKEDLIST_H
 #define LINKEDLIST_H

 class LinkedList{

  public:
   LinkedList();
   //constructor
   //sets m_front to nullptr and m_size to zero
   
   ~LinkedList();

   bool isEmpty() const;
   //returns true if the list is empty, false otherwise.

   int size() const;
   //returns the number of elements in the list.


//   bool search(T value) const;
   //returns true is the value is in the list, false otherwise.

   void printList() const;
   //prints the list to the console. "List empty" if it is empty

   void addBack(int value);
   //One new element added to the end of the list.

   void addFront(int value);
   //One new element added to the front of the list.

   bool removeBack();
   //One element is removed from the back of the list.
   //Returns true if the back element was removed, false if the list is empty.

   bool removeFront();
   //One element is removed from the front of the list.
   //returns True if the front element was removed, false if the list is empty.
   
 private:
   Node* m_front;
   int m_size;

 };


 #endif
