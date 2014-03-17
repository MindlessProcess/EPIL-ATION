#include  "Epil.hh"
#include  "Action.hh"
#include  "ActionWrite.hh"

void  set_profile(std::string const &id, epil::Epil *epil)
{
  epil::Profile *profile = new epil::Profile();
  profile->setId(id);

  // creating an ActionWrite --------------------
  epil::ActionWrite *wr_action = new epil::ActionWrite("wr_action");
  std::pair<int, int> my_pair[] = {std::make_pair(6, 13), std::make_pair(4, 2), std::make_pair(28, 11)};
  wr_action->wr_setDst("misc/dst_file.c", new epil::BlockList(std::list<std::pair<int, int> >(my_pair, my_pair + sizeof(my_pair) / sizeof(std::pair<int, int>))));
  wr_action->wr_setSrc("misc/src_file.c", new epil::BlockList(std::make_pair(3, 5)));
  profile->setAction(wr_action);

  // creating another ActionWrite ---------------
  // epil::ActionWrite *wr_action_bis = new epil::ActionWrite("wr_action_bis");
  // wr_action_bis->wr_setDst("misc/dst_file.c", new epil::BlockList(std::make_pair(1, 8)));
  // wr_action_bis->wr_setSrc("misc/src_file.c", new epil::BlockList(std::make_pair(3, 5)));
  // profile->setAction(wr_action_bis);

  // // creating another ActionWrite ---------------
  // epil::ActionWrite *wr_action_ter = new epil::ActionWrite("wr_action_ter");
  // wr_action_ter->wr_setDst("misc/dst_file.c", new epil::BlockList(std::make_pair(1, 8)));
  // wr_action_ter->wr_setSrc("misc/src_file.c", new epil::BlockList(std::make_pair(3, 5)));
  // profile->setAction(wr_action_ter);

  epil::utils::Console::log("Action = <");
  for (std::list<epil::Action*>::iterator it = profile->getActionList().begin(); it != profile->getActionList().end(); ++it)
    {
      epil::utils::Console::log((*it)->getId());
      if (it != profile->getActionList().end() && (it != --profile->getActionList().end()))
	epil::utils::Console::log(", ");
    }
  epil::utils::Console::nlog(">");
  profile->changeActionOrder("wr_action", "wr_action_bis");
  epil::utils::Console::nlog("Action order changed");
  // profile->revertActionOrder();
  // epil::utils::Console::nlog("Action order reversed");
  epil::utils::Console::log("Action = <");
  for (std::list<epil::Action*>::iterator it = profile->getActionList().begin(); it != profile->getActionList().end(); ++it)
    {
      epil::utils::Console::log((*it)->getId());
      if (it != profile->getActionList().end() && (it != --profile->getActionList().end()))
	epil::utils::Console::log(", ");
    }
  epil::utils::Console::nlog(">");
  epil::utils::Console::nlog("");
  // std::cout << "End of printing actions" << std::endl;
  epil->loadProfile(profile);
}

int	main()
{
  // Unit tests on Profile.hh
  {
    epil::Epil  *epil = new epil::Epil();
    set_profile("SIGSEV", epil);
    // set_profile("SIGERR", epil);
    // set_profile("SIGHANDLER", epil);
    // set_profile("SIGSEV", epil);
    // set_profile("SIGFALSE", epil);
    // set_profile("SIGSEV", epil);
    epil->useProfile("SIGSEV");
  }
  std::cout << std::endl;
  return (0);

  // Unit tests on Console.hh
  {
    epil::utils::Console::log("Console.log test");
  }
  std::cout << std::endl;

  // Unit tests on FileSystem.hpp
  {
    std::string file = "README";
    if (epil::utils::FileSystem::isfile(file))
    {
      epil::utils::Console::log(file+" is a file !");
      if (epil::utils::FileSystem::isreadable(file))
      {
        epil::utils::Console::log(file+" is readable !");
        if (epil::utils::FileSystem::iswritable(file))
        {
          epil::utils::Console::log(file+" is writable !");
          if (epil::utils::FileSystem::isexecutable(file))
            epil::utils::Console::log(file+" is executable !");
          else
            epil::utils::Console::log(std::cerr, file+" is not executable !");
        }
        else
          epil::utils::Console::log(std::cerr, file+" is not writable !");
      }
      else
        epil::utils::Console::log(std::cerr, file+" is not readable !");
    }
    else
      epil::utils::Console::log(std::cerr, file+" is not a file !");

    if (epil::utils::FileSystem::isusable(file))
      epil::utils::Console::log(file+" is fully usable !");
    else
      epil::utils::Console::log(std::cerr, file+" is not fully usable !");
  }
}
