#include <epil/Action.hh>

using namespace epil;

void  Action::setId(std::string const &id)
{
  this->_id = id;
}
std::string const &Action::getId() const
{
  return (this->_id);
}
