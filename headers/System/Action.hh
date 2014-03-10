//
// Action.hh for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/System
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:33:51 2014 Lucas Merlette
// Last update Tue Mar  4 16:12:47 2014 Lyoma Guillou
//

#ifndef		EPIL_SYSTEM_ACTION_HH_
# define	EPIL_SYSTEM_ACTION_HH_

# include <iostream>
# include <string>

# include "Console.hpp"

namespace	epil
{
  class		Action
  {
  public:
    Action(std::string const &id) :_id(id) {}
    virtual ~Action() {}

    void    setId(std::string const &);
    std::string const & getId() const;

    virtual void apply() = 0;

    // virtual void apply() = 0;

    /*
    * ActionWrite
    */
    // void wr_setDst(std::string const&, epil::BlockList*); //DST_FILE, BLOCK
    // void wr_setSrc(std::string const&, epil::BlockList*); //SRC_FILE, BLOCK


  protected:
    std::string _id;
  };
};

#endif		/* !EPIL_SYSTEM_ACTION_HH_ */
