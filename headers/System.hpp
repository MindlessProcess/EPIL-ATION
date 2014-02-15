#ifndef	__SYSTEM_HPP__
# define	__SYSTEM_HPP__

# include	<iostream>
# include	<list>
# include	"Action.hpp"

namespace epil
{
  class	System
  {
  public:
    System();
    ~System();

    void	setAction(Action) throw();
    void	setActionList(std::list<Action*>);

    Action&		getAction() const;
    std::list<Action*>&	getActionList() const;

    void	reWrite(std::string&, std::string&);
    void	reWrite(std::string&, std::string&, int, int = -1);
    void	reWrite(std::string&, std::string&, Range, int = -1);
    void	reWrite(std::string&, std::string&, std::list<int>, int = -1);
    void	reWrite(std::string&, std::string&, std::list<Range>, int = -1);
    void	reWrite(std::string&);
    void	reCompile();
    void	reExecute();
  private:
    std::list<Action*>	_actionList;
    std::list<Action*>	_tempAL;
  };
}

#endif	/* !__SYSTEM_HPP__ */
