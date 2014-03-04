//
// ActionExec.hh for Epl in /home/seiza/Documents/Git/epil-ation/headers/System
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Mar  4 15:09:11 2014 Lyoma Guillou
// Last update Tue Mar  4 15:09:51 2014 Lyoma Guillou
//

#ifndef		EPIL_SYSTEM_ACTIONEXEC_HH_
# define	EPIL_SYSTEM_ACTIONEXEC_HH_

# include	<list>
# include	<utility>
# include	<iostream>
# include	<fstream>

namespace	epil
{
  class		ActionExec : public Action
  {
  public:
  private:
    std::string		_cmd;
    std::string		_opt;

    ActionExec();
    ~ActionExec();

  };

};

#endif		/* !EPIL_SYSTEM_ACTIONEXEC_HH_ */
