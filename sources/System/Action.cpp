#include "Action.hpp"

#include <iostream>

using namespace epil;

static const bool	modify()
{
  // write... 
}

static const bool	compile()
{
  // access();
  // exec();
}

static const bool	exec()
{
  // fork()
  // setpgid()
}

Action::Action() : _type(NIL), _state(false), _fnc(NULL) {}
Action::Action(AType type) : _type, _state(false), _fnc(NULL) {}
Action::Action(AType type, std::string action) : _type(type), _state(false), _action(action)
{
  _fnc = NULL;
  if (_type != NIL)
    {
      if (_type == MODIFY)
	_fnc = &modify;
      else if (_type == COMPILE)
	_fnc = &compile;
      else
	_fnc = &exec;
    }
}

Action::Action(Action &other) : _type(other._type), _state(other._state), _action(other._action)
{
  _fnc = other._fnc;
}

Action::~Action() {}

AType		Action::getType() const { return _type; }
bool		Action::getSet() const { return _state; }
std::string	Action::getAction() const { return _action; }

void		Action::setType(e_AType type) { _type = type; }
void		Action::setAction(std::string action { _action = action; }

bool		Action::apply()
{
  switch _type
    {
    case NIL:
      std::cerr << "No Action has been set" << std::endl;
      return false;
    case MODIFY:

    case COMPILE:

    case EXEC:

    }
}

Action &	Action::operator=(Action &other)
{
  _type = other._type;
  _state = other._state;
  _action = other._action;
  return *this;
}
