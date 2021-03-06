#include  <epil/Profile.hh>

using namespace	epil;
using namespace utils;

Profile::Profile()
  : _id("")
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
  return (this->_id);
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
// bool  Profile::changeActionOrder(std::string const &first_id, std::string const &second_id)
// {
//   Action *first_action = NULL;
//   Action *second_action = NULL;

//   for (std::list<Action*>::iterator it = this->_actionList.begin(); it != _actionList.end(); ++it)
//     {
//       if (!(*it)->getId().compare(first_id))
// 	{
// 	  if ((first_action = dynamic_cast<ActionWrite*>(*it)) == NULL)
// 	    if ((first_action = dynamic_cast<ActionCompile*>(*it)) == NULL)
// 	      if ((first_action = dynamic_cast<ActionExec*>(*it)) == NULL)
// 	  	return (false);
// 	  if (second_action != NULL)
// 	    break;
// 	  else
// 	    continue;
// 	}
//       if (!(*it)->getId().compare(second_id))
// 	{
// 	  if ((second_action = dynamic_cast<ActionWrite*>(*it)) == NULL)
// 	    if ((second_action = dynamic_cast<ActionCompile*>(*it)) == NULL)
// 	      if ((second_action = dynamic_cast<ActionExec*>(*it)) == NULL)
// 	  	return (false);
// 	  if (first_action != NULL)
// 	    break;
// 	  else
// 	    continue;
// 	}
//     }
//   if (first_action == NULL || second_action == NULL)
//     return (false);
//   std::iter_swap(first_action, second_action);
//   return (true);
// }
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
  for (std::list<Action*>::iterator it = this->_actionList.begin(); it != this->_actionList.end(); ++it)
    {
      (*it)->apply();
    }
}

Profile::~Profile()
{
  this->_id.clear();
  for (std::list<Action*>::iterator it = this->_actionList.begin(); it != this->_actionList.end(); ++it)
    {
      delete *it;
    }
}
