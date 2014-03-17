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

# include <fstream>

# include "Console.hpp"

namespace epil
{
  namespace utils
  {
    struct FileSystem
    {
      static inline bool isdir(std::string const &name)
      {
        struct stat buffer;
        return ((stat(name.c_str(), &buffer) == 0)
          && (((buffer.st_mode) & S_IFMT) == S_IFDIR));
      }
      static inline bool isfile(std::string const &name)
      {
        return (access(name.c_str(), F_OK) == 0);
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

      static inline bool write_until(size_t line_number, std::ifstream &infile, std::ofstream &outfile)
      {
        if (!infile.is_open() || !outfile.is_open() || !line_number || (infile.seekg(0, infile.end) && (int)line_number > infile.tellg()))
        {
          Console::nlog("This is FALSE !");
          return (false);
        }
        infile.seekg(0, infile.beg);

        char line[256];

        for (size_t cur_line = 0; cur_line < line_number && infile.good() && outfile.good(); ++cur_line)
        {
          infile.getline(line, 256);
          outfile.write(line, strlen(line));
          if (infile.seekg(infile.tellg() - static_cast<std::streampos>(1)) && infile.get() == '\n')
            outfile.write("\n", strlen("\n"));
          Console::nlog("line #"+std::to_string(cur_line)+" = "+line);
        }
        Console::nlog("This is TRUE !");
        return (true);
      }
    };
  };
};

#endif /* !EPIL_UTILS_FILESYSTEM_HPP_ */
