//
// ActionCompile.hh for Epil in /home/seiza/Documents/Git/epil-ation/headers/System
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Mar  4 15:10:20 2014 Lyoma Guillou
// Last update Sat Mar  8 18:46:51 2014 Lyoma Guillou
//

#ifndef		EPIL_SYSTEM_ACTIONCOMPILE_HH_
# define	EPIL_SYSTEM_ACTIONCOMPILE_HH_

# include	"Action.hh"

namespace	epil
{
  class		ActionCompile : public Action
  {
  public:
    ActionCompile(std::string const &id, std::string const &makeCmd = "make re", std::string const &path = ".");
    ActionCompile(std::string const &id, std::string const &cmd, std::string const &flag, std::string const &name, std::string const &obj, std::string const &path = ".");
    ~ActionCompile();

    virtual void	apply();

  private:
    std::string	_path;
    std::string	_cmd;

    ActionCompile();

    void	_format_path();
  };
};

#endif		/* !EPIL_SYSTEM_ACTIONCOMPILE_HH_ */
