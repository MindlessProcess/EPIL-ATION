#include "UIManager.hh"

int main(int ac, char **av)
{
  app::ui::UIManager *my_app = new app::ui::UIManager();

  if (ac >= 2)
    my_app->setUIPrompt(av[1]);

  std::string command;
  while (command.compare("exit"))
    {
      command.clear();
      try
	{
	  command = my_app->handleCommand();
	}
      catch (app::exceptions::unknown_command const &e)
	{
	  app::ui::Console::nlog(std::cerr, e.what());
	}
      app::ui::Console::nlog("Command received = <"+command+">");
    }
}
