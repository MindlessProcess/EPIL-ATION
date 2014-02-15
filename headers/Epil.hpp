#ifndef EPIL_HPP__
# define  EPIL_HPP__

# include	<iostream>
# include	<string>
# include	<list>

# include	"Profile.hpp"

class Epil
{
public:
  Epil();
  ~Epil();

  void  loadProfile(Profile*);
  void  useProfile(std::string const&);
private:
  std::list<Profile*>	_profileList;
};

#endif  /* !EPIL_HPP__ */
