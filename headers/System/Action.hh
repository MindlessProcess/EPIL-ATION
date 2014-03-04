//
// Action.hh for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/System
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:33:51 2014 Lucas Merlette
// Last update Sun Mar  2 18:10:11 2014 Lyoma Guillou
//

#ifndef		EPIL_SYSTEM_ACTION_HH_
# define	EPIL_SYSTEM_ACTION_HH_

# include	<list>
# include	<utility>
# include	<iostream>
# include	<fstream>

// # include	"BlockList.hpp"

namespace	epil
{
  enum		AType
  {
    NIL,
    MODIFY,
    COMPILE,
    EXEC
  };

  class		Action
  {
  public:
    Action(AType type, std::string const &id);
    ~Action();

    void setId(std::string const&);
    std::string const &getId() const;

  private:
    AType _type;
    std::string _id;
    // Action  *_action;


    Action();
  };

  class		Write : public Action
  {
  public:
    Write(std::string src, std::string dst/*, BlockList srcBlock, BlockList dstBlock*/);
  private:
    std::ifstream	_src;
    std::ofstream	_dst;
    // BlockList		_srcBlock;
    // BlockList		_dstBlock;

    Write();
    ~Write();
  };

  class		Compile : public Action
  {
  public:
  private:
    

    Compile();
    ~Compile();
  };

  class		Exec : public Action
  {
  public:
  private:
    std::string		_cmd;
    std::string		_opt;

    Exec();
    ~Exec();

  };

};

#endif		/* !EPIL_SYSTEM_ACTION_HH_ */
