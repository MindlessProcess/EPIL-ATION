#ifndef PROFILE_HPP__
# define  PROFILE_HPP__

# include	<iostream>
# include	<string>

class Profile
{
public:
  Profile();
  Profile(std::string const&);
  ~Profile();

  void  setId(std::string const&);
  bool	isComplete();
  // void  setAction(AType);

  std::string const   &getId();
  // std::list<Action*>  &getActionList();
private:
  std::string		_id;
  // std::list<Action*>	_actionList;
};

#endif  /* !PROFILE_HPP__ */
