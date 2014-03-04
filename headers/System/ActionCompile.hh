//
// ActionCompile.hh for Epil in /home/seiza/Documents/Git/epil-ation/headers/System
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Mar  4 15:10:20 2014 Lyoma Guillou
// Last update Tue Mar  4 17:10:03 2014 Lyoma Guillou
//

#ifndef		EPIL_SYSTEM_ACTIONCOMPILE_HH_
# define	EPIL_SYSTEM_ACTIONCOMPILE_HH_

# include	"Action.hh"

namespace	epil
{
  class		ActionCompile : public Action
  {
  public:
    // compile methods by using the makefile path or compiler
    // the constructors must be able to parse the arguments into a shell command
    // then store it in this->_cmd
    ActionCompile(std::string const &id, std::string const &makefilePath, std::string const &makeCmd);
    ActionCompile(std::string const &id, std::string const &cmd, std::string const &obj, std::string const &flag, std::string const &name);

    // implement the application of this Action
    // hint: system(this->_cmd)
    void	apply();
  private:
    std::string	_cmd;

    ActionCompile();
    ~ActionCompile();
  };
};

#endif		/* !EPIL_SYSTEM_ACTIONCOMPILE_HH_ */
