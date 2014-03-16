//
// FileSystem.hpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/Modules/Shave
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Sun Mar  2 17:23:00 2014 Lucas Merlette
// Last update Sun Mar  2 18:06:06 2014 Lucas Merlette
//

#ifndef	EPIL_UTILS_FILESYSTEM_HPP_
# define EPIL_UTILS_FILESYSTEM_HPP_

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>

namespace epil
{
  namespace utils
  {
    struct FileSystem
    {
      static inline bool isfile(std::string const &name)
      {
        return (access(name.c_str(), F_OK) == 0);
      }

      static inline bool isdir(std::string const &name)
      {
        struct stat buffer;
        return ((stat(name.c_str(), &buffer) == 0)
          && (((buffer.st_mode) & S_IFMT) == S_IFDIR));
      }

      static inline bool isreadable(std::string const &name)
      {
        return (access(name.c_str(), R_OK) == 0);
      }

      static inline bool iswritable(std::string const &name)
      {
        return (access(name.c_str(), W_OK) == 0);
      }

      static inline bool isexecutable(std::string const &name)
      {
        return (access(name.c_str(), X_OK) == 0);
      }

      static inline bool isusable(std::string const &name)
      {
        return (access(name.c_str(), R_OK | W_OK | X_OK) == 0);
      }
    };
  };
};

#endif /* !EPIL_UTILS_FILESYSTEM_HPP_ */
