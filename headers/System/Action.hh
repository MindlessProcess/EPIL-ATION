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

  class IAction
  {
  public:
    virtual ~IAction() {}
  };

  template <typename T>
  class		Action : public IAction
  {
  public:
    Action(T id, AType type)
    : _id(id), _type(type)
    {
    }
    ~Action() {}

    void setId(T);
    T const getId() const;

  private:
    T _id;
    AType _type;
    Action  *_action;


    Action();
    // ~Action();
  };

  template <typename T>
  class		Write : public Action<T>
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

  template <typename T>
  class		Compile : public Action<T>
  {
  public:
  private:
    

    Compile();
    ~Compile();
  };

  template <typename T>
  class		Exec : public Action<T>
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
