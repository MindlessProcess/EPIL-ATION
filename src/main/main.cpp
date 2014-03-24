#include	<signal.h>

#include	<string>
#include	<iostream>

#include	<epil/Epil.hh>
#include	<epil/Action.hh>

static std::string	exe_name;
static epil::Epil	*my_epil;

void		sig_handler(int signum)
{
  switch (signum)
    {
    case SIGSEGV:
      my_epil->useProfile("SIGSEGV");
      break;
    case SIGINT:
      my_epil->useProfile("Debug");
      break;
    default:
      break;
    }
}

void		set_profile(std::string const &id, epil::Epil *my_epil)
{
  epil::Profile		*profile = new epil::Profile();
  epil::ActionWrite	*wr_action;
  epil::ActionCompile	*cc_action;
  epil::ActionExec	*ex_action;
  std::string		str;

  profile->setId(id);
  if ("SIGSEGV" == id)
    {
      wr_action = new epil::ActionWrite("correct");

      std::pair<int, int>	my_dst[]=
      	{
      	  std::make_pair(24, 25),
      	  std::make_pair(27, 57),
      	  std::make_pair(81, 82)
      	};
      wr_action->wr_setElem(epil::filetype::DST, "src/main/main.cpp", new epil::BlockList(std::list<std::pair<int, int> >(my_dst, my_dst + sizeof(my_dst) / sizeof(std::pair<int, int>))));

      std::pair<int, int>	my_src[]=
      	{
      	  std::make_pair(25, 27),
      	  std::make_pair(29, 43),
      	  std::make_pair(67, 68)
      	};
      wr_action->wr_setElem(epil::filetype::SRC, "misc/foo.cpp", new epil::BlockList(std::list<std::pair<int, int> >(my_src, my_src + sizeof(my_src) / sizeof(std::pair<int, int>))));

      profile->setAction(wr_action);
    }
  else
    {
      str = std::string("gdb ");
      str = str + exe_name;
      cc_action = new epil::ActionCompile("remake", "make re DEBUG=-ggdb3", "`find ~/ -name epil-ation`");
      ex_action = new epil::ActionExec("debug", str.c_str());

      profile->setAction(cc_action);
      profile->setAction(ex_action);
    }
  my_epil->loadProfile(profile);
}

int		main(int ac, char **av)
{
  std::string	arg;
  std::string	run;

  (void) ac;
  my_epil = new epil::Epil();
  exe_name = std::string(av[0]);

  std::cout << "Please select the implementation you want to execute" << std::endl;
  std::cout << "1: Sigint will remake and launch gdb" << std::endl;
  std::cout << "2: Segfault behavior will edit main.cpp" << std::endl;
  std::cin >> arg;
  if ("1" == arg || "2" == arg)
    {
      std::cout << exe_name << " option:" << arg << std::endl;
      set_profile(("2" == arg) ? "SIGSEGV" : "Debug", my_epil);
      std::cout << "Profile " << (("2" == arg) ? "SIGSEGV" : "Debug");
      std::cout << " is now loaded." << std::endl;

      signal(SIGINT, sig_handler);
      signal(SIGSEGV, sig_handler);

      do
	{
	  std::cout << "Enter 'run' to now execute the Profile" << std::endl;
	  std::cout << "Or have fun trying to 'kill' it ;)" << std::endl;
	  std::cin >> run;
	} while ("run" != run && "quit" != run && "exit" != run);
      if ("run" == run)
	{
	  std::cout << "Now running..." << std::endl;
	  raise(("2" == arg) ? SIGSEGV : SIGINT);
	}
    }
}
