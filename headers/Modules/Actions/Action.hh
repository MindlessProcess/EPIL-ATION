#ifndef		EPIL_MODULES_ACTIONS_ACTION_HH_
# define	EPIL_MODULES_ACTIONS_ACTION_HH_

# include <iostream>
# include <string>

namespace	epil
{
  class		Action
  {
  public:
    Action(std::string const &id) :_id(id) {}
    virtual ~Action() {}

    std::string const & getId() const;
    void		setId(std::string const &);

    virtual void apply() = 0;

  protected:
    std::string _id;
  };
};

#endif		/* !EPIL_MODULES_ACTIONS_ACTION_HH_ */
