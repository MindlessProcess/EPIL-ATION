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
# define STREAM_GETLINE_SIZE 256

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

    static inline bool write_until(std::streampos line_pos, std::ifstream &infile, std::ofstream &outfile)
    {
      Console::nlog("====In write_until()====");
      Console::nlog("line_pos = "+std::to_string(line_pos));
      std::streampos orig_pos = infile.tellg();
      if (!infile.is_open() || !outfile.is_open() || (infile.seekg(0, infile.end) && line_pos > infile.tellg()))
      {
        Console::nlog("This is FALSE !");
        return (false);
      }
      else if (!line_pos)
        line_pos = infile.tellg() + static_cast<std::streampos>(1);
      Console::nlog("line_pos = "+std::to_string(line_pos));
 
      infile.seekg(orig_pos);
      char stream_line[STREAM_GETLINE_SIZE];
      for (int cur_line = 0; cur_line < line_pos && infile.good() && outfile.good(); ++cur_line)
      {
        infile.getline(stream_line, STREAM_GETLINE_SIZE);
        outfile.write(stream_line, strlen(stream_line));
        if (infile.seekg(infile.tellg() - static_cast<std::streampos>(1)) && infile.get() == '\n')
          outfile.write("\n", 1);
        Console::nlog("stream_line #"+std::to_string(cur_line)+" = "+stream_line);
      }

      Console::nlog("This is TRUE !");
      Console::nlog("====Out of write_until()====");
      return (true);
    }

    static inline bool ifstream_goto(std::streampos line_pos, std::ifstream &infile)
    {
      Console::nlog("====In ifstream_goto()====");
      std::streampos orig_pos = infile.tellg();
      if (!infile.is_open() || !line_pos || (infile.seekg(0, infile.end) && line_pos > infile.tellg()))
      {
        Console::nlog("This is FALSE !");
        return (false);
      }

      infile.seekg(orig_pos);
      char stream_line[STREAM_GETLINE_SIZE];
      for (int cur_line = 0; cur_line < line_pos && infile.good(); ++cur_line)
      {
        infile.getline(stream_line, STREAM_GETLINE_SIZE);
        Console::nlog("stream_line #"+std::to_string(cur_line)+" = "+stream_line);
      }

      Console::nlog("This is TRUE !");
      Console::nlog("====Out of ifstream_goto()====");
      return (true);
    }
    // static inline bool ofstream_goto(std::streampos line_pos, std::ofstream &outfile)
    // {
    //   if (!outfile.is_open() || !outfile.is_open() || !line_pos || (outfile.seekp(0, outfile.end) && line_pos > outfile.tellp()))
    //   {
    //     Console::nlog("This is FALSE !");
    //     return (false);
    //   }

    //   outfile.seekp(0, outfile.beg);
    //   char stream_line[STREAM_GETLINE_SIZE];
    //   for (int cur_line = 0; cur_line < line_pos && outfile.good(); ++cur_line)
    //   {
    //     outfile.getline(stream_line, STREAM_GETLINE_SIZE);
    //     Console::nlog("stream_line #"+std::to_string(cur_line)+" = "+stream_line);
    //   }

    //   Console::nlog("This is TRUE !");
    //   return (true);
    // }
  };
};
};

#endif /* !EPIL_UTILS_FILESYSTEM_HPP_ */
