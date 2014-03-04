#include  "Epil.hh"
#include  "Action.hh"
#include  "ActionWrite.hh"

void  set_profile(std::string const &id, epil::Epil *epil)
{
  std::cout << "========In Epil::setProfile()============" << std::endl;
  epil::Profile	*profile = new epil::Profile();
  profile->setId(id);

  // creating an ActionWrite --------------------
  epil::ActionWrite *wr_action = new epil::ActionWrite("wr_action");
  std::cout << "----In file loading--------" << std::endl;
  wr_action->wr_setDst("misc/dst_file.c", new epil::BlockList(std::make_pair(1, 8)));
  wr_action->wr_setSrc("misc/src_file.c", new epil::BlockList(std::make_pair(3, 5)));
  std::cout << "----Out of file loading----" << std::endl << std::endl;
  profile->setAction(wr_action);

  // creating another ActionWrite ---------------
  epil::ActionWrite *wr_action_bis = new epil::ActionWrite("wr_action_bis");
  std::cout << "----In file loading--------" << std::endl;
  wr_action_bis->wr_setDst("misc/dst_file.c", new epil::BlockList(std::make_pair(1, 8)));
  wr_action_bis->wr_setSrc("misc/src_file.c", new epil::BlockList(std::make_pair(3, 5)));
  std::cout << "----Out of file loading----" << std::endl << std::endl;
  profile->setAction(wr_action_bis);

  std::cout << "----Printing actions--------" << std::endl << "Actions = <";
  for (std::list<epil::Action*>::iterator it = profile->getActionList().begin(); it != profile->getActionList().end(); ++it)
  {
    std::cout << (*it)->getId() << ", ";
  }
  std::cout << ">" << std::endl;
  profile->changeActionOrder("my_first_profile", "100394");
  epil::hair::Console::log("Action order changed");
  std::cout << "Action = <";
  for (std::list<epil::Action*>::iterator it = profile->getActionList().begin(); it != profile->getActionList().end(); ++it)
  {
    std::cout << (*it)->getId() << ", ";
  }
  std::cout << ">" << std::endl;
  // std::cout << "End of printing actions" << std::endl;

  epil->loadProfile(profile);
  std::cout << "========Out of Epil::setProfile()========" << std::endl;
  std::cout << std::endl;
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
  std::cout << std::endl;

  // Unit tests on wr_functions
  // {
  //   epil::Epil  *epil = new epil::Epil();
  //   epil->wr_setDst("misc/dst_file.c", epil::BlockList(std::make_pair(1, 8), std::make_pair(2, 7)));
  //   epil->wr_setSrc("misc/src_file.c", epil::BlockList(std::make_pair(4, 6)));

  //   epil->wr_run();
  // }

  {
    Workspace workspace;
    workspace.set_wd(".");
  }
  // std::cout << std::endl;

  // Unit tests on Console.hh
  {
    epil::hair::Console::log("Console.log test");
  }
  std::cout << std::endl;

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
