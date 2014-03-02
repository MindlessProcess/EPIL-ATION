//
// Profile.hh for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/UI
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:37:33 2014 Lucas Merlette
// Last update Mon Feb 24 23:38:42 2014 Lucas Merlette
//

#ifndef		EPIL_UI_PROFILE_HH_
# define	EPIL_UI_PROFILE_HH_

# include	<iostream>
# include	<string>

namespace	epil
{
  class		Profile
  {
  public:
    Profile();
    Profile(std::string const&);
    ~Profile();

    void	setId(std::string const&);
    bool	isComplete();
    // void  setAction(AType);

    std::string const	&getId();
    // std::list<Action*>  &getActionList();
  private:
    std::string	_id;
    // std::list<Action*>	_actionList;
  };
};

#endif		/* !EPIL_UI_PROFILE_HH_ */
