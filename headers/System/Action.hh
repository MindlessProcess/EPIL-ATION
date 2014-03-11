//
// Action.hh for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/System
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:33:51 2014 Lucas Merlette
// Last update Tue Mar 11 11:36:49 2014 Lyoma Guillou
//

#ifndef		EPIL_SYSTEM_ACTION_HH_
# define	EPIL_SYSTEM_ACTION_HH_

# include <iostream>
# include <string>

namespace	epil
{
  class		Action
  {
  public:
    Action(std::string const &id) :_id(id) {}
    virtual ~Action() {}

    std::string const & getId() const;
    void		setId(std::string const &);

    virtual void apply() = 0;

  protected:
    std::string _id;
  };
};

#endif		/* !EPIL_SYSTEM_ACTION_HH_ */
