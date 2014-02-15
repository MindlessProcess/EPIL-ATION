#include	"Epil.hpp"

void	set_profile(std::string const &id, Epil *epil)
{
  Profile	*profile= new Profile();
  profile->setId(id);
  epil->loadProfile(profile);
}

int	main()
{
  Epil	*epil = new Epil();
  set_profile("SIGSEV", epil);
  set_profile("SIGERR", epil);
  set_profile("SIGHANDLER", epil);
  set_profile("SIGSEV", epil);
  set_profile("SIGFALSE", epil);
  set_profile("SIGSEV", epil);
  epil->useProfile("SIGSEV");
}
