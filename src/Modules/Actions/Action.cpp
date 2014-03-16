//
// Action.cpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/sources/System
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:40:00 2014 Lucas Merlette
// Last update Tue Mar 11 11:37:19 2014 Lyoma Guillou
//

#include "Action.hh"

using namespace epil;

void  Action::setId(std::string const &id)
{
  this->_id = id;
}
std::string const &Action::getId() const
{
  return (this->_id);
}
