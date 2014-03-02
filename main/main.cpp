#include	"Epil.hh"

void	set_profile(std::string const &id, epil::Epil *epil)
{
  epil::Profile	*profile= new epil::Profile();
  profile->setId(id);
  epil->loadProfile(profile);
}

int	main()
{
  epil::Epil	*epil = new epil::Epil();
  set_profile("SIGSEV", epil);
  set_profile("SIGERR", epil);
  set_profile("SIGHANDLER", epil);
  set_profile("SIGSEV", epil);
  set_profile("SIGFALSE", epil);
  set_profile("SIGSEV", epil);
  epil->useProfile("SIGSEV");

  epil->wr_setDst("misc/dst_file.c", epil::BlockList(std::make_pair(1, 8)));
  epil->wr_setSrc("misc/src_file.c", epil::BlockList(std::make_pair(4, 6)));
}
