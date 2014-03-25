#include "UIManager.hh"

using namespace app;
using namespace ui;

UIManager::UIManager()
{
  this->setUIDisplay();
  this->_initPtrFuncs();
}

void UIManager::setUIDisplay()
{
  this->_UIDisplay = UIDisplay();
}
UIDisplay &UIManager::getUIDisplay()
{
  return (this->_UIDisplay);
}

void UIManager::setUIPrompt(std::string const &prompt)
{
  this->_UIDisplay.setPrompt(prompt);
}

std::string UIManager::handleCommand()
{
  std::string command = this->_UIDisplay.waitForCommand();
  if (std::regex_match(command, std::regex("(.+)(\\.)(.+)((\\.)(.+))*")))
    {
      std::vector<std::string> commandVector = utils::StringOperations::split<std::vector<std::string> >(command, '.');
      if (this->_invokerFuncs[commandVector[0]] == NULL)
	{
	  std::cerr << "Unknown command <"+command+">, please try again" << std::endl;
	  throw exceptions::unknown_command(command);
	}
      (this->*_invokerFuncs[commandVector[0]])(utils::ContainerOperations::subcontainer<std::vector<std::string> >(commandVector, 1));
    }
  else if (command.compare("exit"))
    {
      std::cerr << "Unknown command <"+command+">, please try again" << std::endl;
    }

  return (command);
}

void UIManager::_initPtrFuncs()
{
  this->_invokerFuncs["ui"]	= &UIManager::_uiInvoker;
  this->_invokerFuncs["kernel"] = &UIManager::_kernelInvoker;
}

void UIManager::_kernelInvoker(std::vector<std::string> const &command)
{
  if (!command[0].compare("exit") || !command[0].compare("quit"))
    {
      Console::nlog("Leaving lucas_app...");
      exit(EXIT_SUCCESS);
    }
}
void UIManager::_uiInvoker(std::vector<std::string> const &command)
{
  if (!command[0].compare("prompt"))
    {
      if (!command[1].compare("help"))
  	{
  	  Console::nlog("UI Prompt commands :");
  	  Console::nlog(" new [command] : changes current prompt for [command]");
  	  Console::nlog(" append [command] : appends [command] to current prompt");
  	  Console::nlog(" delete : deletes current prompt and prints an empty one");
  	}
      else if (!command[1].substr(0, 3).compare("new"))
	{
	  std::vector<std::string> new_command = utils::StringOperations::split<std::vector<std::string> >(command[1], ' ');
	  if (new_command.size() != 2)
	    std::cerr << "Error : ui.prompt.new must take one argument" << std::endl;
	  else
	    this->setUIPrompt(new_command[1]);
	}
      else if (!command[1].substr(0, 6).compare("append"))
	{
	  std::vector<std::string> append_command = utils::StringOperations::split<std::vector<std::string> >(command[1], ' ');
	  if (append_command.size() != 2)
	    std::cerr << "Error : ui.prompt.append must take one argument" << std::endl;
	  else
	    this->setUIPrompt(this->_UIDisplay.getPrompt()+append_command[1]);
	}
      else if (!command[1].substr(0, 6).compare("delete"))
	this->setUIPrompt("");
    }
}

UIManager::~UIManager()
{
}
