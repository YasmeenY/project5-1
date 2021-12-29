#ifndef PODCAST_HPP
#define PODCAST_HPP

#include "PlaylistItem.hpp"

class Podcast : public PlaylistItem
{
public:
   Podcast(std::string title, double length, std::string genre, 
      std::string nameOfPodcast, std::string host, std::string guest);
   std::string getNameOfPodcast() const;
   std::string getHost() const;
   std::string getGuest() const;
   void setNameOfPodcast(std::string nameOfPodcast);
   void setHost(std::string host);
   void setGuest(std::string guest);
   void display() const override;

private:
   std::string name_of_podcast_;
   std::string host_;
   std::string guest_;
};

#endif