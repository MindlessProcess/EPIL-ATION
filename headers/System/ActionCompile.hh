//
// ActionCompile.hh for Epil in /home/seiza/Documents/Git/epil-ation/headers/System
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Mar  4 15:10:20 2014 Lyoma Guillou
// Last update Tue Mar  4 15:14:16 2014 Lyoma Guillou
//

#ifndef		EPIL_SYSTEM_ACTIONCOMPILE_HH_
# define	EPIL_SYSTEM_ACTIONCOMPILE_HH_

# include	<list>
# include	<utility>
# include	<iostream>
# include	<fstream>

namespace	epil
{
  class		ActionCompile : public Action
  {
  public:
    // _cmd is the command to be used in the shell
    std::string	_cmd;

    // compile methods by using the makefile path or compiler
    // the constructors must be able to parse the arguments into a shell command
    // then store it in this->_cmd
    ActionCompile(std::string makefilePath, std::string makeCmd);
    ActionCompile(std::string cmd, std::string obj, std::string flag, std::string name);

    // implement the application of this Action
    // hint: system(this->_cmd)
    void	apply();
  private:
    
    ActionCompile();
    ~ActionCompile();
  };
};

#endif		/* !EPIL_SYSTEM_ACTIONCOMPILE_HH_ */
