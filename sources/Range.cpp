#include "Range.hpp"

using namespace	epil

// Errors handling on negative parameters

Range::Range(std::size_t anti)
{
  _anti = (anti < 0) ? -1 : anti;
  _list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(-1, -1));
}

Range::Range(std::pair<std::size_t, std::size_t> pair) _anti(-1)
{
  _anti = -1;
  
  if (std::get<0>(pair) > std::get<1>(pair))
    {
      _list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(std::get<1>(pair), std::get<0>(pair)));
    }
  else
    _list = std::list<std::pair<std::size_t, std::size_t> >(pair);
}

Range::Range(std::pair<std::size_t, std::size_t> pair, std::size_t anti)
{
  _anti = anti;
  if (std::get<0>(pair) > std::get<1>(pair))
    {
      _list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(std::get<1>(pair), std::get<0>(pair)));
    }
  else
    _list = std::list<std::pair<std::size_t, std::size_t> >(pair);
}

Range::Range(std::pair<std::size_t, std::size_t> pair, std::pair<std::size_t, std::size_t> anti_pair)
{
  _anti = -1;
  std::pair<std::size_t, std::size_t>	t_pair;
  std::pair<std::size_t, std::size_t>	t_anti_pair;
  t_pair = (std::get<0>(pair) > std::get<1>(pair)) ? std::make_pair(std::get<1>(pair), std::get<0>(pair)) : pair;
  t_anti_pair = (std::get<0>(anti_pair) > std::get<1>(anti_pair)) ? std::make_pair(std::get<1>(pair), std::get<0>(anti_pair)) : anti_pair;
  if (std::get<0>(t_pair) < std::get<0>(t_anti_pair))
    _list.push_back(std::make_pair(std::get<0>(t_pair), std::get<0>(t_anti_pair)));
  else if (std::get<1>(t_pair) > std::get<1>(t_anti_pair))
    _list.push_back(std::make_pair(std::get<1>(t_pair), std::get<1>(t_anti_pair)));
}
