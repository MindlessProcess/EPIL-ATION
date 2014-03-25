#ifndef APP_MODULES_UTILS_FILESYSTEM_HPP_
# define APP_MODULES_UTILS_FILESYSTEM_HPP_

namespace app
{
  namespace utils
  {
    struct FileSystem
    {
      static inline bool isdir(std::string const &fs)
      {
	struct stat buffer;
	return ((stat(fs.c_str(), &buffer) == 0)
		&& ((buffer.st_mode & S_IFMT) == S_IFDIR));
      }

      static inline bool isfile(std::string const &fs)
      {
	return (access(fs.c_str(), F_OK) == 0);
      }

      static inline bool isreadable(std::string const &fs)
      {
	return (access(fs.c_str(), R_OK) == 0);
      }

      static inline bool iswritable(std::string const &fs)
      {
	return (access(fs.c_str(), W_OK) == 0);
      }

      static inline bool isexecutable(std::string const &fs)
      {
	return (access(fs.c_str(), X_OK) == 0);
      }

      static inline bool isusable(std::string const &fs)
      {
	return (access(fs.c_str(), R_OK | W_OK | X_OK) == 0);
      }
    };
  };
};

#endif /* !APP_MODULES_UTILS_FILESYSTEM_HPP_ */
