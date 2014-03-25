#ifndef APP_UI_CONSOLE_HPP_
# define APP_UI_CONSOLE_HPP_

# include <iostream>

namespace app
{
  namespace ui
  {
    class Console
    {
    public:
      /**
       * log functions : print infos without a new line
       */
      template <typename T>
      static inline void log(T v_type)
      {
	std::cout << v_type;
      }
      template <typename T>
      static inline void log(std::ostream &stream, T v_type)
      {
	stream << v_type;
      }

      /**
       * nlog functions : print infos with a new line
       */
      template <typename T>
      static inline void nlog(T v_type)
      {
	std::cout << v_type << std::endl;
      }
      template <typename T>
      static inline void nlog(std::ostream &stream, T v_type)
      {
	stream << v_type << std::endl;
      }
    };
  };
};

#endif /* !APP_UI_CONSOLE_HPP_ */ 
