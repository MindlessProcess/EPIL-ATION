//
// Action.hh for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/System
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:33:51 2014 Lucas Merlette
// Last update Mon Feb 24 23:35:51 2014 Lucas Merlette
//

#ifndef		EPIL_SYSTEM_ACTION_HH_
# define	EPIL_SYSTEM_ACTION_HH_

namespace	epil
{
  enum		AType
  {
    NULL,
    MODIFY,
    COMPILE,
    EXEC
  };
  
  class		Action
  {  
    AType	_type;
    bool	_state;
    bool	(*_fnc)();
    std::string	_action;

    Action();
  public:
    Action(AType type);
    Action(AType type, std::string action);
    Action(Action &);
    ~Action();

    AType	getType() const;
    bool	getState() const;
    std::string	getAction() const;

    void	setType(AType type);
    void	setAction(std::string action);

    bool	apply();

    Action	&operator=(Action &);
  };
};

#endif		/* !EPIL_SYSTEM_ACTION_HH_ */
