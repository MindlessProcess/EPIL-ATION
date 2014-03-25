#ifndef APP_UI_UIMANAGER_HH_
# define APP_UI_UIMANAGER_HH_

# include <map>
# include <list>
# include <regex>
# include <string>

# include "UIDisplay.hh"

# include "ContainerOperations.hpp"
# include "StringOperations.hpp"

# include "CommandsExceptions.hpp"

namespace app
{
  namespace ui
  {
    class UIManager
    {
    public:
      UIManager();
      ~UIManager();

      void setUIDisplay();
      UIDisplay	&getUIDisplay();

      void setUIPrompt(std::string const&);
      std::string handleCommand();

    private:
      void _initPtrFuncs();
      void _kernelInvoker(std::vector<std::string> const &command_vector);
      void _uiInvoker(std::vector<std::string> const &command_vector);

      std::string _command;
      UIDisplay _UIDisplay;
      /* Member functions pointers map */
      typedef void (UIManager::*invoker_func)(std::vector<std::string> const &commandVector);
      std::map<std::string, invoker_func> _invokerFuncs;
    };
  };
};

#endif /* !APP_UI_UIMANAGER_HH_ */
