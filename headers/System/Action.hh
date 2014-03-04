//
// Action.hh for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/System
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:33:51 2014 Lucas Merlette
// Last update Tue Mar  4 16:12:47 2014 Lyoma Guillou
//

#ifndef		EPIL_SYSTEM_ACTION_HH_
# define	EPIL_SYSTEM_ACTION_HH_

namespace	epil
{
  enum		AType
  {
    NIL,
    MODIFY,
    COMPILE,
    EXEC
  };

  class		Action
  {
  public:
    Action(AType type, std::string const &id);

    void		setId(std::string const &);
    std::string const &	getId() const;

    virtual void	apply() = 0;

  private:
    AType _type;
    std::string _id;

    Action();
    ~Action();
  };
};

#endif		/* !EPIL_SYSTEM_ACTION_HH_ */
