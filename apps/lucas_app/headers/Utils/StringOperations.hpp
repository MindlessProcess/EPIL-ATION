#ifndef APP_MODULES_UTILS_TYPESYSTEM_HPP_
# define APP_MODULES_UTILS_TYPESYSTEM_HPP_

# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <iterator>
# include <sstream>

# include "Console.hpp"

namespace app
{
  namespace utils
  {
    struct StringOperations
    {
      template <typename T>
      static inline T split(std::string const &str, char delim = ' ')
      {
	T __Tcnt;

	split(str, __Tcnt, delim);
	return (__Tcnt);
      }

      template <typename T>
      static inline void split(std::string const &str, T &__Tcnt, char delim)
      {
	std::stringstream ss(str);
	std::string item;

	while (std::getline(ss, item, delim))
	  {
	    if (!item.empty())
	    __Tcnt.push_back(item);
	  }
      }
      static inline std::vector<std::string> stringToVector(std::string const &str)
      {
	std::istringstream iss(str);
	std::vector<std::string> result;

	std::copy(std::istream_iterator<std::string>(iss),
		  std::istream_iterator<std::string>(),
		  std::back_inserter<std::vector<std::string> >(result));

	return (result);
      }

      static inline std::list<std::string> stringToList(std::string const &str)
      {
	std::istringstream iss(str);
	std::list<std::string> result;

	std::copy(std::istream_iterator<std::string>(iss),
		  std::istream_iterator<std::string>(),
		  std::back_inserter<std::list<std::string> >(result));

	return (result);
      }

      template <typename T>
      static inline std::string containerToString(T _Tcnt)
      {
	std::string ret_str;

	for (typename T::iterator it = _Tcnt.begin(); it != _Tcnt.end(); ++it)
	  {
	    ret_str += (*it);
	  }
	return (ret_str);
      }

      static inline std::string const &removeBeltQuotes(std::string const &str)
      {
	std::string ret_str = str;

	if (ret_str[0] == '\"' && ret_str[ret_str.size() - 1] == '\"')
	  {
	    ret_str.erase(0, 1);
	    ret_str.erase(ret_str.size() - 1, 1);
	  }

	return (str);
      }
    };
  };
};

#endif /* !APP_MODULES_UTILS_TYPESYSTEM_HPP_ */
