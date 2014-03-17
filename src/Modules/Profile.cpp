//
// Profile.cpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/sources/UI
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:40:15 2014 Lucas Merlette
// Last update Mon Feb 24 23:54:21 2014 Lucas Merlette
//

#include  "Profile.hh"

using namespace	epil;
using namespace utils;

Profile::Profile()
{
}

Profile::Profile(std::string const &id)
  : _id(id)
{
}

/**
 * Getters and setters
 */
void  Profile::setId(std::string const &id)
{
  this->_id = id;
}
std::string const   &Profile::getId()
{
  if (!this->_id.empty())
    return (this->_id);
  throw new std::exception();
}

Profile &Profile::setAction(Action *new_action)
{
  this->_actionList.push_back(new_action);

  return (*this);
}
std::list<Action*>  &Profile::getActionList()
{
  return (this->_actionList);
}
//-----

/**
 * Action order functions
 */
void  Profile::changeActionOrder(std::string const &first_id, std::string const &second_id)
{
  ActionWrite *first_action = NULL;
  ActionWrite *second_action = NULL;

  for (std::list<Action*>::iterator it = this->_actionList.begin(); it != _actionList.end(); ++it)
  {
    if (!(*it)->getId().compare(first_id))
    {
      if ((first_action = dynamic_cast<ActionWrite*>(*it)) == 0)
	Console::nlog("FAIL WITH FIRST DYNAMIC_CAST");
      else
	Console::nlog("IT IS ACTIONWRITE");
      if (second_action != NULL)
        break;
      else
        continue;
    }
    if ((*it)->getId() == second_id)
    {
      if ((second_action = dynamic_cast<ActionWrite*>(*it)) == 0)
	Console::nlog("FAIL WITH SECOND DYNAMIC_CAST");
      else
	Console::nlog("IT IS ACTIONWRITE");
      if (first_action != NULL)
        break;
      else
        continue;
    }
  }
  if (first_action != NULL && second_action != NULL)
  {
    Console::nlog("SWAPPING ORDERS");
    std::iter_swap(first_action, second_action);
  }
  else
    Console::nlog("NOT SWAPPING ORDERS");
}
void  Profile::revertActionOrder()
{
  this->_actionList.reverse();
}
//-----

bool	Profile::isComplete()
{
  return (!this->_id.empty() ? true : false);
}

void	Profile::apply()
{
  Console::nlog("====In Profile::apply()=====");
  for (std::list<Action*>::iterator it = this->_actionList.begin(); it != this->_actionList.end(); ++it)
    {
      Console::nlog("action <"+(*it)->getId()+"> apply()");
      (*it)->apply();
    }
  Console::nlog("====Out of Profile::apply()=====");
}

Profile::~Profile()
{
  std::cout << "===================" << std::endl;
  std::cout << "In Profile Dtor" << std::endl;
  this->_id.clear();
  for (std::list<Action*>::iterator it = this->_actionList.begin(); it != this->_actionList.end(); ++it)
    {
      delete *it;
    }
  std::cout << "Profile successfully cleared" << std::endl;
  std::cout << "===================" << std::endl;
}
