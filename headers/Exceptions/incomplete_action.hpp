#ifndef EPIL_EXCEPTIONS_INCOMPLETE_ACTION_HPP_
# define EPIL_EXCEPTIONS_INCOMPLETE_ACTION_HPP_

#include <iostream>
#include <sstream>
#include <exception>

namespace epil
{
  namespace exceptions
  {
    class incomplete_action : public std::exception
    {
    public:
      incomplete_action(std::string const &msg)
      {
	std::ostringstream oss;
	oss << "====Runtime error====" << std::endl << "Exception of incomplete_action type caught : " << msg;
	this->msg = oss.str();
      }
      virtual ~incomplete_action() throw() {}

      virtual const char *what() const throw()
      {
	return (this->msg.c_str());
      }

    private:
      std::string msg;
    };
  };
};

#endif /* EPIL_EXCEPTIONS_INCOMPLETE_ACTION_HPP_ */
