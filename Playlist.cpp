#include "Playlist.hpp"
#include "PlaylistItem.hpp"

Playlist::Playlist()
   : DoublyLinkedList()
{
}

double Playlist::getTotalTime() const
{
   auto *node = getHeadPtr()->getNext();
   double totalTime = 0;
   for (int i = 0; i < getSize(); i++)
   {
      totalTime += node->getItem()->getLength();
      node = node->getNext();
   }
   return totalTime;
}

void Playlist::operator+=(Playlist rhs)
{
   auto node = rhs.getHeadPtr()->getNext();
   for (int i = 0; i < rhs.getSize(); i++)
   {
      insertAtEnd(node->getItem());
      node = node->getNext();
   }
}

void Playlist::operator-=(Playlist rhs)
{
   auto node = rhs.getHeadPtr()->getNext();
   for (int i = 0; i < rhs.getSize(); i++)
   {
      auto position = getIndexOf(node->getItem());
      if (position != -1)
      {
         remove(position);
      }
      node = node->getNext();
   }
}

void Playlist::skip()
{
   if (getSize() < 2)
   {
      return;
   }

   auto *head = getHeadPtr();
   auto *first = head->getNext();
   auto *last = getAtPos(getSize());
   auto *tail = last->getNext();

   head->setNext(first->getNext());
   head->getNext()->setPrevious(head);

   first->setPrevious(last);
   last->setNext(first);
   
   first->setNext(tail);
   tail->setPrevious(first);
}

void Playlist::rewind()
{
   if (getSize() < 2)
   {
      return;
   }

   auto *head = getHeadPtr();
   auto *first = head->getNext();
   auto *last = getAtPos(getSize());
   auto *tail = last->getNext();

   tail->setPrevious(last->getPrevious());
   last->getPrevious()->setNext(tail);
   
   last->setNext(first);
   first->setPrevious(last);

   head->setNext(last);
   last->setPrevious(head);
}

void Playlist::display()
{
   auto node = getHeadPtr()->getNext();
   for (int i = 0; i < getSize(); i++) 
   {
      node->getItem()->display();
      node = node->getNext();
   }
}