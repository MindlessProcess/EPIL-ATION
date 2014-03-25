#ifndef APP_EXCEPTIONS_COMMANDSEXCEPTIONS_HPP_
# define APP_EXCEPTIONS_COMMANDSEXCEPTIONS_HPP_

#include <sstream>
#include <exception>

namespace app
{
  namespace exceptions
  {
    class unknown_command : public std::exception
    {
    public:
      unknown_command(std::string const &msg)
      {
	std::ostringstream oss;

	oss << "Unknown command <" << msg << ">";
	this->_msg = oss.str();
      }
      virtual ~unknown_command() throw() {}

      virtual char const *what() const throw()
      {
	return (this->_msg.c_str());
      }

    private:
      std::string _msg;
    };
  }
};

#endif /* !APP_EXCEPTIONS_COMMANDSEXCEPTIONS_HPP_ */
