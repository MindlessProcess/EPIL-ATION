#ifndef KOMODO_MODULES_UTILS_CONTAINEROPERATIONS_HPP_
# define KOMODO_MODULES_UTILS_CONTAINEROPERATIONS_HPP_

# include <iostream>
# include <string>
# include <stdexcept>

// # include <vector>
// # include <list>
// # include <algorithm>
// # include <iterator>
// # include <sstream>

namespace epil
{
  namespace utils
  {
    struct ContainerOperations
    {
      /**
       * STL Container subcontainer function (std::string.substr() STL Container equivalent)
       */
      template <typename T>
      static inline T subcontainer(T _Tcnt, std::size_t pos = 0, std::size_t len = 0)
      {
	T ret_Tcnt(0);

	if (pos == _Tcnt.size())
	  return (ret_Tcnt);
	else if (pos > _Tcnt.size())
	  throw std::out_of_range("OUT OF RANGE");
	if (!len || len > _Tcnt.size() || pos + len > _Tcnt.size())
	  ret_Tcnt.resize(_Tcnt.size() - pos);
	else if (pos + len > _Tcnt.size())
	  ret_Tcnt.resize(_Tcnt.size() - pos);
	else
	  ret_Tcnt.resize(len);

	// std::cout << "_Tcnt.size() = <"<<_Tcnt.size()<<">" << std::endl;
	// std::cout << "ret_Tcnt.size() = <"<<ret_Tcnt.size()<<">" << std::endl;
	for (unsigned int i = 0; i < ret_Tcnt.size(); ++i)
	  *(ret_Tcnt.begin() + i) = *(_Tcnt.begin() + i + pos);

	return (ret_Tcnt);
      }

      /**
       * STL Container display
       */
      template <typename T>
      static inline void display_container(T _Tcnt, std::string sep = "")
      {
	// std::cout << "_Tcnt = <" << _Tcnt.size() << ">, <";
	for (typename T::iterator it = _Tcnt.begin(); it != _Tcnt.end(); ++it)
	  {
	    std::cout << (*it);
	    if (it != _Tcnt.end() && it != --_Tcnt.end())
	      std::cout << sep;
	  }
	// std::cout << ">" << std::endl;
      }
    };
  };
};

#endif /* !KOMODO_MODULES_UTILS_CONTAINEROPERATIONS_HPP_ */
