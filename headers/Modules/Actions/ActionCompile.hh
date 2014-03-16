//
// ActionCompile.hh for Epil in /home/seiza/Documents/Git/epil-ation/headers/System
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Mar  4 15:10:20 2014 Lyoma Guillou
// Last update Tue Mar 11 11:38:34 2014 Lyoma Guillou
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
    ActionCompile(std::string const &id, std::string const &cmd, std::string const &flag, std::string const &obj, std::string const &name = "", std::string const &path = ".");
    ~ActionCompile();

    void	apply();

  private:
    std::string	_path;
    std::string	_cmd;

    inline bool	_isWorkingDir();
    inline bool	_isValidPath();
    inline bool	_changeDir();

    void	_format_path();
  };
};

#endif		/* !EPIL_SYSTEM_ACTIONCOMPILE_HH_ */
