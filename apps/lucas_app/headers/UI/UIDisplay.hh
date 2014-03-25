#ifndef APP_UI_UIDISPLAY_HH_
# define APP_UI_UIDISPLAY_HH_

# include <iostream>
# include <string>

# include "Console.hpp"

namespace app
{
  namespace ui
  {
    class UIDisplay
    {
    public:
      UIDisplay();
      ~UIDisplay();

      void setPrompt(std::string const &prompt);
      std::string const &getPrompt() const;
      std::string waitForCommand();

    private:
      std::string _prompt;
    };
  };
};

#endif /* !APP_UI_UIDISPLAY_HH_ */
