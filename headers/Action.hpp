#ifndef ACTION_H_
# define ACTION_H_

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
    std::string		_action;
    bool		(*_fnc)();

  public:
    Action();
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

    Action & operator=(Action &);
  };

};

#endif /* !ACTION_H_ */
