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

# include <boost/variant.hpp>

# include "Action.hh"

namespace	epil
{
  class		Profile
  {
  public:
    Profile();
    Profile(std::string const&);
    ~Profile();

    void	setId(std::string const&);
    bool	isComplete();

    template <typename T>
    void  setAction(T id, AType actionType)
    {
      // std::list<int> *my_list = new std::list<int>();
      // (void)my_list;
      // Action<T> *new_action   = new Action<T>(id, actionType);
      // (void)new_action;
      // (void)id;
      // (void)actionType;
      this->_actionList.push_back(new Action<T>(id, actionType));
    }

    /**
     * Action order functions
     */
    template <typename ID1, typename ID2>
    void  changeActionOrder(ID1, ID2);
    template <typename ID1, typename ID2>
    void  changeActionOrder(std::pair<ID1, ID2> const&);

    void  revertActionOrder();

    std::string const	&getId();
    // std::list<Action*>  &getActionList();
  private:
    std::string	_id;

    // Defining VT (Variant Type) as a template type possibly being one of these types :
    // typedef boost::variant<int, std::string const&> VT;
    std::list<IAction*>	_actionList;
  };
};

#endif		/* !EPIL_UI_PROFILE_HH_ */
