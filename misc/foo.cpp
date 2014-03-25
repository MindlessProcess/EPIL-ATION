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
  switch (signum)
    {
    case SIGSEGV:
      my_epil->useProfile("SIGSEGV");
      break;
    case SIGINT:
      my_epil->useProfile("Debug");
      break;
    }
  exit(EXIT_SUCCESS);
}

void		set_profile(std::string const &id, epil::Epil *my_epil)
{
  epil::Profile		*profile = new epil::Profile();
  epil::ActionCompile	*cc_action;
  epil::ActionExec	*ex_action;
  std::string		str;

  profile->setId(id);
  if ("SIGSEGV" == id)
    {
      ex_action = new epil::ActionExec("valgr", "valgrind ./a.out");
      profile->setAction(ex_action);
    }
  else
    {
      str = std::string("gdb ");
      str = str + exe_name;
      cc_action = new epil::ActionCompile("remake", "make re DEBUG=-ggdb3", "`find ~/ -name epil-ation`");
      ex_action = new epil::ActionExec("debug", str);

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
  std::cout << "2: Segfault behavior (valgrind)" << std::endl;
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
