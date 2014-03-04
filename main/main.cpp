#include	"Epil.hh"
#include  "Action.hh"

void	set_profile(std::string const &id, epil::Epil *epil)
{
  epil::Profile	*profile= new epil::Profile();
  profile->setId(id);
  profile->setAction(epil::MODIFY, "my_first_profile");
     // .wr_setDst("misc/dst_file.c", new epil::BlockList(std::make_pair(1, 8)))
     // .wr_setSrc("misc/src_file.c", new epil::BlockList(std::make_pair(3, 5)));
  profile->setAction(epil::MODIFY, "100394");

  std::cout << "ID = " << profile->getActionList().back()->getId() << std::endl;

  // std::cout << "BEGIN: " << (*(profile->getActionList().begin()))->name << std::endl;
  // for (std::list<epil::IAction*>::iterator it = profile->getActionList().begin(); it != profile->getActionList().end(); ++it)
  // {
  //   std::cout << "HH" << std::endl;
  //   std::cout << "action: <" << (*it)->name << ">" << std::endl;
  // }

  epil->loadProfile(profile);
}

int	main()
{
  // Unit tests on Profile.hh
  {
    epil::Epil  *epil = new epil::Epil();
    set_profile("SIGSEV", epil);
    set_profile("SIGERR", epil);
    set_profile("SIGHANDLER", epil);
    set_profile("SIGSEV", epil);
    set_profile("SIGFALSE", epil);
    set_profile("SIGSEV", epil);
    epil->useProfile("SIGSEV");
  }

  // Unit tests on wr_functions
  {
    epil::Epil  *epil = new epil::Epil();
    epil->wr_setDst("misc/dst_file.c", epil::BlockList(std::make_pair(1, 8), std::make_pair(2, 7)));
    epil->wr_setSrc("misc/src_file.c", epil::BlockList(std::make_pair(4, 6)));

    epil->wr_run();
  }

  {
    Workspace workspace;
    workspace.set_wd(".");
  }

  // Unit tests on Console.hh
  {
    epil::hair::Console::log("HELLO");
  }

  // Unit tests on FileSystem.hpp
  {
    std::string file = "README";
    if (epil::shave::FileSystem::isfile(file))
    {
      epil::hair::Console::log(file+" is a file !");
      if (epil::shave::FileSystem::isreadable(file))
      {
        epil::hair::Console::log(file+" is readable !");
        if (epil::shave::FileSystem::iswritable(file))
        {
          epil::hair::Console::log(file+" is writable !");
          if (epil::shave::FileSystem::isexecutable(file))
            epil::hair::Console::log(file+" is executable !");
          else
            epil::hair::Console::log(std::cerr, file+" is not executable !");
        }
        else
          epil::hair::Console::log(std::cerr, file+" is not writable !");
      }
      else
        epil::hair::Console::log(std::cerr, file+" is not readable !");
    }
    else
      epil::hair::Console::log(std::cerr, file+" is not a file !");

    if (epil::shave::FileSystem::isusable(file))
      epil::hair::Console::log(file+" is fully usable !");
    else
      epil::hair::Console::log(std::cerr, file+" is not fully usable !");
  }
}
