#include "UIDisplay.hh"

using namespace app;
using namespace ui;

UIDisplay::UIDisplay()
  : _prompt("$> ")
{
}

void UIDisplay::setPrompt(std::string const &prompt)
{
  this->_prompt = prompt;
}
std::string const &UIDisplay::getPrompt() const
{
  return (this->_prompt);
}

std::string UIDisplay::waitForCommand()
{
  std::string buffer;

  Console::log(this->getPrompt());
  std::getline(std::cin, buffer);
  return (buffer);
}

UIDisplay::~UIDisplay()
{
}


