#ifndef	EPIL_UTILS_FILESYSTEM_HPP_
# define EPIL_UTILS_FILESYSTEM_HPP_

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>

# include <fstream>

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
        return ((stat(name.c_str(), &buffer) == 0) && (((buffer.st_mode) & S_IFMT) == S_IFDIR));
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

      static inline bool add_extension(std::string &dst_str, std::string const &src_str)
      {
	size_t size;

	if ((size = dst_str.find('.')) == std::string::npos)
	  return (false);
        // std::string new_string(dst_str.substr(0, size)+src_str+dst_str.substr(size));
        dst_str = std::string(dst_str.substr(0, size)+src_str+dst_str.substr(size));

        return (true);
      }

      static inline std::streampos write_until(std::streampos line_pos, std::ifstream &infile, std::ofstream &outfile)
      {
        std::streampos orig_pos = infile.tellg();
        char stream_line[STREAM_GETLINE_SIZE];
        int cur_line;

        if (!infile.is_open() || !outfile.is_open() || (infile.seekg(0, infile.end) && line_pos > infile.tellg()))
          return (0);
        else if (!line_pos)
          line_pos = infile.tellg() + static_cast<std::streampos>(1);
        infile.seekg(orig_pos);
        for (cur_line = 1; cur_line < line_pos && infile.good() && outfile.good(); ++cur_line)
          {
            infile.getline(stream_line, STREAM_GETLINE_SIZE);
            outfile.write(stream_line, strlen(stream_line));
            if (infile.seekg(infile.tellg() - static_cast<std::streampos>(1)) && infile.get() == '\n')
              outfile.write("\n", 1);
          }

        return (--cur_line);
      }

      static inline std::streampos ifstream_goto(std::streampos line_pos, std::ifstream &infile)
      {
        std::streampos orig_pos = infile.tellg();

        if (!infile.is_open() || !line_pos || (infile.seekg(0, infile.end) && line_pos > infile.tellg()))
          return (0);
        infile.seekg(orig_pos);

        char stream_line[STREAM_GETLINE_SIZE];
        int cur_line = 1;
        for (cur_line = 1; cur_line < line_pos && infile.good(); ++cur_line)
          {
            infile.getline(stream_line, STREAM_GETLINE_SIZE);
          }

        return (--cur_line);
      }
    };
  };
};

#endif /* !EPIL_UTILS_FILESYSTEM_HPP_ */
