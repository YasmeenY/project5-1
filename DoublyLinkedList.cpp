#include "DoublyLinkedList.hpp"

template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList()
{
   head_ = new DoubleNode<ItemType>();
   tail_ = new DoubleNode<ItemType>();
   head_->setNext(tail_);
   head_->setPrevious(nullptr);
   head_->setItem(ItemType());
   tail_->setNext(nullptr);
   tail_->setPrevious(head_);
   tail_->setItem(ItemType());
   size_ = 0;
}

template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList &other)
   : DoublyLinkedList()
{
   for (auto position = other.head_->getNext(); position != other.tail_; position = position->getNext())
   {
      insertAtBeginning(position->getItem());
   }
}

template <typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
   clear();
   delete head_;
   delete tail_;
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::insertAtEnd(const ItemType &item)
{
   DoubleNode<ItemType> *node = new DoubleNode<ItemType>();
   node->setItem(item);
   node->setPrevious(tail_->getPrevious());
   node->setNext(tail_);
   tail_->getPrevious()->setNext(node);
   tail_->setPrevious(node);
   size_++;
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::insertAtBeginning(const ItemType &item)
{
   DoubleNode<ItemType> *node = new DoubleNode<ItemType>();
   node->setItem(item);

   DoubleNode<ItemType> *firstNode = head_->getNext();
   node->setNext(firstNode);
   node->setPrevious(head_);
   head_->setNext(node);
   firstNode->setPrevious(node);
   size_++;
}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position)
{
    if (position == 1)
   {
      insertAtBeginning(item);
      return true;
   }

   auto tmp = getAtPos(position);

   if (tmp == nullptr)
   {
      return false;
   }
   else if (tmp == tail_)
   {
      insertAtEnd(item);
   }
   else
   {
      DoubleNode<ItemType> *node = new DoubleNode<ItemType>();
      node->setItem(item);
      node->setNext(tmp);
      node->setPrevious(tmp->getPrevious());
      tmp->getPrevious()->setNext(node);
      tmp->setPrevious(node);
      size_++;
   }
   return true;
}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position)
{
   auto node = getAtPos(position);
   if (node == nullptr)
   {
      return false;
   }
   
   auto prevNode = node->getPrevious();
   auto nextNode = node->getNext();
   prevNode->setNext(nextNode);
   nextNode->setPrevious(prevNode);
   size_--;
   delete node;
   
   return true;
}

template <typename ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
   return size_;
}

template <typename ItemType>
DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getHeadPtr() const
{
   return head_;
}

template <typename ItemType>
DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getAtPos(const int &pos) const
{
   auto tmp = head_;
   int i = 0;
   while (i < pos && tmp != nullptr)
   {
      tmp = tmp->getNext();
      i++;
   }
   return tmp;
}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
   return head_->getNext() == tail_;
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    DoubleNode<ItemType> *current = head_;
    current = current->getNext();
    while (current != tail_) {
        DoubleNode<ItemType> *temp = current;
        current = current->getNext();
        delete temp;
    }
}

template <typename ItemType>
int DoublyLinkedList<ItemType>::getIndexOf(const ItemType &item) const
{
   auto tmp = head_->getNext();
   int i = 1;
   while (tmp != tail_)
   {
      if (tmp->getItem() == item)
      {
         return i;
      }
      tmp = tmp->getNext();
      i++;
   }
   return -1;
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::display() const
{
   auto tmp = head_->getNext();
   while (tmp != tail_)
   {
      tmp->getItem().display();
      tmp = tmp->getNext();
   }
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
   auto tmp = tail_->getPrevious();
   while (tmp != head_)
   {
      tmp->getItem().display();
      tmp = tmp->getPrevious();
   }
}

template <typename ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list)
{
   if (isEmpty())
   {
      return a_list;
   }

   if (a_list.isEmpty())
   {
      return *this;
   }

   DoublyLinkedList<ItemType> result;
   DoubleNode<ItemType> *node1 = this->head_->getNext();
   DoubleNode<ItemType> *node2 = a_list.head_->getNext();
   while (node1 != this->tail_ && node2 != a_list.tail_)
   {
      result.insertAtEnd(node1->getItem());
      result.insertAtEnd(node2->getItem());
   }
   while (node1 != this->tail_)
   {
      result.insertAtEnd(node1->getItem());
      node1 = node1->getNext();
   }
   while (node2 != a_list.tail_)
   {
      result.insertAtEnd(node2->getItem());
      node2 = node2->getNext();
   }

   return result;
}