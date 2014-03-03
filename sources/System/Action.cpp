//
// Action.cpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/sources/System
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:40:00 2014 Lucas Merlette
// Last update Sun Mar  2 17:17:19 2014 Lyoma Guillou
//

#include "Action.hh"

#include <iostream>

using namespace epil;

// template <typename T>
// Action<T>::Action(T id, AType type)
//   : _id(id), _type(type)
// {
// }

template <typename T>
void Action<T>::setId(T id)
{
  this->_id = id;
}
template <typename T>
T const Action<T>::getId() const
{
  return (this->_id);
}