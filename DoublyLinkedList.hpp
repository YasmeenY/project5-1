#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "DoubleNode.hpp"

template <typename ItemType>
class DoublyLinkedList
{
public:
   DoublyLinkedList();
   DoublyLinkedList(const DoublyLinkedList &other);
   ~DoublyLinkedList();
   bool insert(const ItemType &item, const int &position); //inserts item at position in caller list
   void insertAtBeginning(const ItemType &item); //inserts item at beginning
   void insertAtEnd(const ItemType &item); //inserts item at the end
   bool remove(const int &position); //removes the node at position
   int getSize() const; // returns the number of the nodes in the calling list
   DoubleNode<ItemType> *getHeadPtr() const; // returns a copy of the headPtr
   DoubleNode<ItemType> *getAtPos(const int &pos) const; // returns a pointer to the node located at pos
   bool isEmpty() const; // returns whether the calling list is empty
   void clear(); // clears the list
   int getIndexOf(const ItemType &item) const; // returns the position of the given item in the list, -1 otherwise
   void display() const; // prints the contents of the calling list in order
   void displayBackwards() const; // prints the contents of the calling list in reverse order
   DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType> &a_list);
   // returns the interleaved list of the calling and parameter lists

private:
    DoubleNode<ItemType> *head_;
    DoubleNode<ItemType> *tail_;
    unsigned size_;
};

#include "DoublyLinkedList.cpp"

#endif