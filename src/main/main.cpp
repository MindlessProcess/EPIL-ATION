#include	<signal.h>

#include	<string>
#include	<iostream>

#include	"Epil.hh"
#include	"Action.hh"
#include	"ActionWrite.hh"
#include	"ActionCompile.hh"
#include	"ActionExec.hh"

static std::string	exe_name;
static epil::Epil	*my_epil;

void		sig_handler(int signum)
{
  std::cout << "In sig_handler: " << signum << std::endl;
  std::cout << "SIGSEGV: " << SIGSEGV << std::endl;
  std::cout << "SIGINT: " << SIGINT << std::endl;
  switch (signum)
    {
    case SIGSEGV:
      std::cout << "In SIGSEV switch" << std::endl;
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
  if (id == "SIGSEGV")
    {
      wr_action = new epil::ActionWrite("correct");

      std::pair<int, int>	my_dst[]=
      	{
      	  std::make_pair(25, 26),
      	  std::make_pair(31, 59),
      	  std::make_pair(82, 83)
      	};
      wr_action->wr_setElem(epil::filetype::DST,
			    "src/main/main.cpp",
			    new epil::BlockList(std::list<std::pair<int, int> >(my_dst, my_dst + sizeof(my_dst) / sizeof(std::pair<int, int>))));

      std::pair<int, int>	my_src[]=
      	{
      	  std::make_pair(25, 27),
      	  std::make_pair(29, 43),
      	  std::make_pair(66, 67)
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

  (void) ac;
  my_epil = new epil::Epil();
  exe_name = std::string(av[0]);

  std::cout << "Please select the implementation you want to execute" << std::endl;
  std::cout << "1: Sigint will remake and launch gdb" << std::endl;
  std::cout << "2: Segfault behavior will edit main.cpp" << std::endl;
  std::cin >> arg;
  if ("1" == arg || "2" == arg)
    {
      signal(SIGINT, sig_handler);
      signal(SIGSEGV, sig_handler);

      std::cout << exe_name << " option:" << arg << std::endl;
      set_profile(("2" == arg) ? "SIGSEGV" : "Debug", my_epil);
      std::cout << "Profile " << (("2" == arg) ? "SIGSEGV" : "Debug");
      std::cout << " is now loaded." << std::endl;
      do
	{
	  std::cout << "Enter 'run' to now execute the Profile" << std::endl;
	  std::cout << "Or have fun trying to 'kill' it ;)" << std::endl;
	  std::cin >> arg;
	  std::cout << "You chose : " << arg << std::endl;
	} while ("run" != arg && "quit" != arg);
      if ("run" == arg)
	{
	  std::cout << "Now running..." << std::endl;
	  raise(("2" == arg) ? SIGSEGV : SIGINT);
	}
    }
}
