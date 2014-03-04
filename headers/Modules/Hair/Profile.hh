//
// Profile.hh for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/UI
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:37:33 2014 Lucas Merlette
// Last update Mon Mar  3 13:00:48 2014 Lucas Merlette
//

#ifndef		EPIL_UI_PROFILE_HH_
# define	EPIL_UI_PROFILE_HH_

# include	<iostream>
# include	<string>
# include <list>

// # include <boost/variant.hpp>

# include "Action.hh"
# include "ActionWrite.hh"

namespace	epil
{
  class		Profile
  {
  public:
    Profile();
    Profile(std::string const &id);
    ~Profile();

    void	setId(std::string const &id);
    std::string const	&getId();

    bool  isComplete();

    Profile &setAction(Action*);
    template <typename T>
    Action *setAction(std::string const &id)
    {
      this->_actionList.push_back(new T(id));
      return (this->_actionList.back());
      // return (dynamic_cast<ActionWrite*>(this->_actionList.back()));
    }
    std::list<Action*>  &getActionList();

    /**
     * Action order functions
     */
    void  changeActionOrder(std::string const&, std::string const&);
    void  changeActionOrder(std::pair<std::string, std::string> const&);

    void  revertActionOrder();
  private:
    std::string	_id;

    // Defining VT (Variant Type) as a template type possibly being one of these types :
    // typedef boost::variant<int, std::string const&> VT;
    std::list<Action*>	_actionList;
  };
};

#endif		/* !EPIL_UI_PROFILE_HH_ */
