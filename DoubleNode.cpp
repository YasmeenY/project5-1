#include "DoubleNode.hpp"

template <typename ItemType>
DoubleNode<ItemType>::DoubleNode() : item_(ItemType()), next_(nullptr), prev_(nullptr) {}

template <typename ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType &an_item) : item_(an_item), next_(nullptr), prev_(nullptr) {}

template <typename ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType &an_item, DoubleNode<ItemType> *next_node_ptr, DoubleNode<ItemType> *prev_node_ptr)
    : item_(an_item), next_(next_node_ptr), prev_(prev_node_ptr) {}

template <typename ItemType>
void DoubleNode<ItemType>::setItem(const ItemType &anItem)
{
   item_ = anItem;
}

template <typename ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
   return item_;
}

template <typename ItemType>
DoubleNode<ItemType> *DoubleNode<ItemType>::getNext() const 
{ 
   return next_; 
}

template <typename ItemType>
DoubleNode<ItemType> *DoubleNode<ItemType>::getPrevious() const 
{ 
   return prev_; 
}

template <typename ItemType>
void DoubleNode<ItemType>::setPrevious(DoubleNode<ItemType> *previousNodePtr)
{
   prev_ = previousNodePtr;
}

template <typename ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType> *nextNodePtr)
{
   next_ = nextNodePtr;
}