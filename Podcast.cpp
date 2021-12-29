#include "Podcast.hpp"

#include <iostream>

Podcast::Podcast(std::string title, double length, std::string genre, 
   std::string nameOfPodcast, std::string host, std::string guest)
   : PlaylistItem(std::move(title), length, std::move(genre))
   , name_of_podcast_(std::move(nameOfPodcast))
   , host_(std::move(host))
   , guest_(std::move(guest))
{
}
std::string Podcast::getNameOfPodcast() const
{
   return name_of_podcast_;
}

std::string Podcast::getHost() const
{
   return host_;
}

std::string Podcast::getGuest() const
{
   return guest_;
}

void Podcast::setNameOfPodcast(std::string nameOfPodcast)
{
   name_of_podcast_ = std::move(nameOfPodcast);
}

void Podcast::setHost(std::string host)
{
   host_ = std::move(host);
}

void Podcast::setGuest(std::string guest)
{
   guest_ = std::move(guest);
}

void Podcast::display() const
{
   std::cout << getTitle() << std::endl;
   std::cout << "Podcast: " << name_of_podcast_ << std::endl;
   std::cout << "Host: " << host_ << std::endl;
   std::cout << "Guest: " << guest_ << std::endl;
   std::cout << "Genre: " << getGenre() << std::endl;
   std::cout << "Length: " << getLength() << std::endl;
   std::cout << std::endl;
}