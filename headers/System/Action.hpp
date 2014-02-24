#ifndef ACTION_HPP_
# define ACTION_HPP_

namespace	epil
{
  enum AType
  {
    NULL,
    MODIFY,
    COMPILE,
    EXEC
  };
  
  class	Action
  {  
    AType		_type;
    bool		_state;
    bool		(*_fnc)();
    std::string		_action;

    Action();
  public:
    Action(AType type);
    Action(AType type, std::string action);
    Action(Action &);
    ~Action();

    AType		getType() const;
    bool		getState() const;
    std::string		getAction() const;

    void		setType(AType type);
    void		setAction(std::string action);

    bool		apply();

    Action &		operator=(Action &);
  };

};

#endif /* !ACTION_HPP_ */
