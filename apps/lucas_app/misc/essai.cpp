#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
T subcontainer(T _Tcnt, std::size_t pos = 0, std::size_t len = 0)
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

  std::cout << "_Tcnt.size() = <"<<_Tcnt.size()<<">" << std::endl;
  std::cout << "ret_Tcnt.size() = <"<<ret_Tcnt.size()<<">" << std::endl;
  for (unsigned int i = 0; i < ret_Tcnt.size(); ++i)
    {
      *(ret_Tcnt.begin() + i) = *(_Tcnt.begin() + i + pos);
    }
}

template <typename T>
void display_cnt(T _Tcnt)
{
  std::cout << "_Tcnt = <" << _Tcnt.size() << ">, <";
  for (typename T::iterator it = _Tcnt.begin(); it != _Tcnt.end(); ++it)
    std::cout << (*it);
  std::cout << ">" << std::endl;
}

int main()
{
  char str[] = "Hello world";
  std::vector<char> my_vec(str, str + sizeof(str) - sizeof(char));

  std::cout << "subcontainer(my_vec) : " << std::endl;
  display_cnt<std::vector<char> >(my_vec);
  std::cout << "subcontainer(my_vec, 1) : " << std::endl;
  display_cnt<std::vector<char> >(subcontainer<std::vector<char> >(my_vec, 1));
  std::cout << "subcontainer(my_vec, 2, 2) : " << std::endl;
  display_cnt<std::vector<char> >(subcontainer<std::vector<char> >(my_vec, 2, 2));
  std::cout << "subcontainer(my_vec, 4, my_vec.size() + 1) : " << std::endl;
  display_cnt<std::vector<char> >(subcontainer<std::vector<char> >(my_vec, 4, my_vec.size() + 1));
  std::cout << "subcontainer(my_vec, 1, my_vec.size() + 1) : " << std::endl;
  display_cnt<std::vector<char> >(subcontainer<std::vector<char> >(my_vec, 1, my_vec.size() + 1));

  return (0);
}
