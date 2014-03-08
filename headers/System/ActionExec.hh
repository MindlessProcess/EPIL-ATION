//
// ActionExec.hh for Epil in /home/seiza/Documents/Git/epil-ation/headers/System
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Mar  4 15:09:11 2014 Lyoma Guillou
// Last update Sat Mar  8 14:19:21 2014 Lyoma Guillou
//

#ifndef		EPIL_SYSTEM_ACTIONEXEC_HH_
# define	EPIL_SYSTEM_ACTIONEXEC_HH_

# include	"Action.hh"

namespace	epil
{
  class		ActionExec : public Action
  {
  public:
    ActionExec(std::string const &id, std::string const &cmd, std::string const &opt = "");
    ~ActionExec();

    // [fork]ing and [setpgid]ing
    virtual void	apply();

  private:
    std::string		_cmd;
    char		**_arg;

    ActionExec();
  };

};

#endif		/* !EPIL_SYSTEM_ACTIONEXEC_HH_ */
