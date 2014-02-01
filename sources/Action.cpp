#include "Action.hpp"

using namespace epil;

Action::Action() : _type(NIL), _state(false) {}
Action::Action(AType type) : _type, _state(false) {}
Action::Action(AType type, std::string action) : _type(type), _state(false), _action(action) {}
Action::Action(Action &other) : _type(other._type), _state(other._state), _action(other._action) {}
Action::~Action() {}

AType		Action::getType() const { return _type; }
bool		Action::getSet() const { return _state; }
std::string	Action::getAction() const { return _action; }

void		Action::setType(e_AType type) { _type = type; }
void		Action::setAction(std::string action { _action = action; }

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

bool		Action::apply()
{
  switch _type
    {
    case NIL:
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
