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
using namespace	hair;

Profile::Profile()
{
}

Profile::Profile(std::string const &id)
  : _id(id)
{
}

void  Profile::setId(std::string const &id)
{
  this->_id = id;
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

std::string const   &Profile::getId()
{
  if (!this->_id.empty())
    return (this->_id);
  throw new std::exception();
}

void  Profile::changeActionOrder(std::string const &first_id, std::string const &second_id)
{
  ActionWrite *first_action = NULL;
  ActionWrite *second_action = NULL;

  hair::Console::nlog("first_id = <"+first_id+">");
  hair::Console::nlog("second_id = <"+second_id+">");
  for (std::list<Action*>::iterator it = this->_actionList.begin(); it != _actionList.end(); ++it)
  {
    hair::Console::nlog("getId() = <"+(*it)->getId()+">");
    if (!(*it)->getId().compare(first_id))
    {
      if ((first_action = dynamic_cast<ActionWrite*>(*it)) == 0)
	{
	  // if ((first_action = dynamic_cast<epil::ActionCompile*>(*it)) == 0)
	  //   {
	  //     if ((first_action = dynamic_cast<epil::ActionExec*>(*it)) == 0)
	  // 	{
	  hair::Console::nlog("FAIL WITH DYNAMIC_CASTS");
	    // 	}
	    // }
	}
      else
	hair::Console::nlog("IT IS ACTIONWRITE");
      if (second_action != NULL)
        break;
      else
        continue;
    }
    if ((*it)->getId() == second_id)
    {
      // second_action = *it;
      if ((second_action = dynamic_cast<epil::ActionWrite*>(*it)) == 0)
	{
	  // if ((second_action = dynamic_cast<epil::ActionCompile*>(*it)) == 0)
	  //   {
	  //     if ((second_action = dynamic_cast<epil::ActionExec*>(*it)) == 0)
	  // 	{
	  hair::Console::nlog("FAIL WITH DYNAMIC_CASTS");
	    // 	}
	    // }
	}
      else
	hair::Console::nlog("IT IS ACTIONWRITE");
      if (first_action != NULL)
        break;
      else
        continue;
    }
  }
  if (first_action != NULL && second_action != NULL)
  {
    hair::Console::nlog("SWAPPING ORDERS");
    std::iter_swap(first_action, second_action);
  }
  else
    hair::Console::nlog("NOT SWAPPING ORDERS");
}

void  Profile::revertActionOrder()
{
  // this->_actionList.reverse();
}

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
  Console::nlog("====In Profile::apply()=====");
}

Profile::~Profile()
{
  std::cout << "===================" << std::endl;
  std::cout << "In Profile Dtor" << std::endl;
  this->_id.clear();
  // for (std::list<Action*>::iterator it = this->_actionList.begin();
  //   it != this->_actionList.end(); ++it)
  //   delete it;
  std::cout << "Profile successfully cleared" << std::endl;
  std::cout << "===================" << std::endl;
}
