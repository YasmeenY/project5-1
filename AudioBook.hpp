#ifndef AUDIOBOOK_HPP
#define AUDIOBOOK_HPP

#include "PlaylistItem.hpp"

class AudioBook : public PlaylistItem
{
public:
   AudioBook(std::string title, double length, std::string genre, 
      std::string author, std::string speaker);
   std::string getAuthor() const;
   std::string getSpeaker() const;
   void setAuthor(std::string author);
   void setSpeaker(std::string speaker);
   void display() const override;

private:
   std::string author_;
   std::string speaker_;
};

#endif