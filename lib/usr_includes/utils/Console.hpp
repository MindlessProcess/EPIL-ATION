#ifndef EPIL_UTILS_CONSOLE_HH_
# define EPIL_UTILS_CONSOLE_HH_

# include <iostream>

namespace epil
{
  namespace utils
  {
    class Console
    {
    public:
      Console();
      ~Console();

      template <typename T>
      static inline void log(T v_type)
      {
        std::cout << v_type;
      }
      template <typename T>
      static inline void log(std::ostream &is, T v_type)
      {
        is << v_type;
      }

      template <typename T>
      static inline void nlog(T v_type)
      {
        std::cout << v_type << std::endl;
      }
      template <typename T>
      static inline void nlog(std::ostream &is, T v_type)
      {
        is << v_type << std::endl;
      }
    };
  };
};

#endif /* !EPIL_UTILS_CONSOLE_HH_ */
