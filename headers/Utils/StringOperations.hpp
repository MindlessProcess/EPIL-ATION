#ifndef KOMODO_MODULES_UTILS_TYPESYSTEM_HPP_
# define KOMODO_MODULES_UTILS_TYPESYSTEM_HPP_

# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <iterator>
# include <sstream>

# include "Console.hpp"
# include "ContainerOperations.hpp"

namespace epil
{
  namespace utils
  {
    struct StringOperations
    {
      static inline std::vector<std::string> stringToVector(std::string const &str)
      {
	std::istringstream iss(str);
	std::vector<std::string> result;
	utils::Console::nlog("====In stringToVector()====");
	utils::Console::nlog("iss.str() = <"+iss.str()+">");
	std::istream_iterator<std::string> iit(iss);
	while (iit != std::istream_iterator<std::string>())
	  {
	    utils::Console::nlog("iit = <"+*iit+">");
	    ++iit;
	  }
	utils::Console::nlog("iss.str() = <"+iss.str()+">");

	std::copy(std::istream_iterator<std::string>(iss),
		  std::istream_iterator<std::string>(),
		  std::back_inserter<std::vector<std::string> >(result));

	ContainerOperations::display_container<std::vector<std::string> >(result);
	utils::Console::nlog("====Out of stringToVector()====");
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
      static inline std::string containerToString(T _Tcnt, std::string const &__del = "")
      {
	std::string ret_str;

	for (typename T::iterator it = _Tcnt.begin(); it != _Tcnt.end(); ++it)
	  {
	    ret_str += (*it);
	    if (it != _Tcnt.end() && it != --_Tcnt.end())
	      ret_str += __del;
	    std::cout << "ret_str = " << ret_str << std::endl;
	  }
	return (ret_str);
      }

      static inline std::string const &removeBeltQuotes(std::string const &str)
      {
	std::string ret_str = str;
	std::cout << "str = <" + str + ">" << std::endl;

	std::cout << "str[0] = '" << str[0] << "'" << std::endl;
	std::cout << "str[str.size()] = '" << str[str.size() - 1] << "'" << std::endl;
	if (ret_str[0] == '\"' && ret_str[ret_str.size() - 1] == '\"')
	  {
	    ret_str.erase(0, 1);
	    ret_str.erase(ret_str.size() - 1, 1);
	  }

	// std::cout << "find('\"') : <"<<str.find('\"')<<">" << std::endl;
	// ret_str.erase(str.find('\"'), 1);
	// // ret_str.erase(0, 0);
	std::cout << "ret_str = <" + ret_str + ">" << std::endl;
	return (str);
      }
    };
  };
};

#endif /* !KOMODO_MODULES_UTILS_TYPESYSTEM_HPP_ */
