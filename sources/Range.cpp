#include "Range.hpp"

using namespace	epil

yRange::Range(std::size_t anti)
{
  _anti = (0 > anti) ? -1 : anti;
  _list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(-1, -1));
}

Range::Range(std::pair<std::size_t, std::size_t> pair)
{
  _anti = -1;
  _list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(-1, -1));
  if (0 <= std::get<0>(pair) && 0 <= std::get<1>(pair))
    {
      if (std::get<0>(pair) > std::get<1>(pair))
	_list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(std::get<1>(pair), std::get<0>(pair)));
      else
	_list = std::list<std::pair<std::size_t, std::size_t> >(pair);
    }
}

Range::Range(std::pair<std::size_t, std::size_t> pair, std::size_t anti)
{
  _anti = (0 > anti) ? -1 : anti;
  _list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(-1, -1));
  if (0 <= std::get<0>(pair) && 0 <= std::get<1>(pair))
    {
      if (std::get<0>(pair) > std::get<1>(pair))
	_list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(std::get<1>(pair), std::get<0>(pair)));
      else
	_list = std::list<std::pair<std::size_t, std::size_t> >(pair);
    }
}

Range::Range(std::pair<std::size_t, std::size_t> pair, std::pair<std::size_t, std::size_t> anti_pair)
{
  _anti = -1;
  if (0 <= std::get<0>(pair) && 0 <= std::get<1>(pair) && 0 <= std::get<0>(anti_pair) && 0 <= std::get<1>(anti_pair))
    {
      std::pair<std::size_t, std::size_t>	t_pair;
      std::pair<std::size_t, std::size_t>	t_anti_pair;
      t_pair = (std::get<0>(pair) > std::get<1>(pair)) ? std::make_pair(std::get<1>(pair), std::get<0>(pair)) : pair;
      t_anti_pair = (std::get<0>(anti_pair) > std::get<1>(anti_pair)) ? std::make_pair(std::get<1>(pair), std::get<0>(anti_pair)) : anti_pair;
      if (std::get<0>(t_pair) < std::get<0>(t_anti_pair))
	_list.push_back(std::make_pair(std::get<0>(t_pair), std::get<0>(t_anti_pair)));
      if (std::get<1>(t_pair) > std::get<1>(t_anti_pair))
	_list.push_back(std::make_pair(std::get<1>(t_pair), std::get<1>(t_anti_pair)));
    }
  if (_list.empty())
    _list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(-1, -1));
}

Range::Range(std::list<std::pair<std::size_t, std::size_t> > list)
{
  std::list<std::pair<std::size_t, std::size_t> >		tl;
  std::list<std::pair<std::size_t, std::size_t> >::iterator	it;
  std::pair<std::size_t, std::size_t>				tp;

  _anti = -1;
  if (!list.empty())
    {
      for (it = list.begin(); it != list.end(); ++it)
	{
	  tp = *it;
	  if (0 <= std::get<0>(tp) && 0 <= std::get<1>(tp))
	    {
	      if (std::get<0>(tp) > std::get<1>(tp))
		tl.push_back(std::make_pair(std::get<1>(tp), std::get<0>(tp)));
	      else
		tl.push_back(tp);
	    }
	}
      _list = tl;
    }
  else
    _list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(-1, -1));
}

Range::Range(std::list<std::pair<std::size_t, std::size_t> > list, std::size_t anti)
{
  std::list<std::pair<std::size_t, std::size_t> >		tl;
  std::list<std::pair<std::size_t, std::size_t> >::iterator	it;
  std::pair<std::size_t, std::size_t>				tp;

  _anti = (0 > anti) ? -1 : anti;
  if (!list.empty())
    {
      for (it = list.begin(); it != list.end(); ++it)
	{
	  tp = *it;
	  if (0 <= std::get<0>(tp) && 0 <= std::get<1>(tp))
	    {
	      if (std::get<0>(tp) > std::get<1>(tp))
		tl.push_back(std::make_pair(std::get<1>(tp), std::get<0>(tp)));
	      else
		tl.push_back(tp);
	    }
	}
      _list = list;
    }
  else
    _list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(-1, -1));
}

Range::Range(std::list<std::pair<std::size_t, std::size_t> > list, std::pair<std::size_t, std::size_t> anti_pair)
{
  std::list<std::pair<std::size_t, std::size_t> >		tl;
  std::list<std::pair<std::size_t, std::size_t> >::iterator	it;
  std::pair<std::size_t, std::size_t>				tp;
  std::pair<std::size_t, std::size_t>				ta;

  _anti = -1;
  if (!list.empty())
    {
      ta = std::make_pair(-1, -1);
      if (0 <= std::get<0>(anti_pair) && 0 <= std::get<1>(anti_pair))
	ta = (std::get<0>(anti_pair) > std::get<1>(anti_pair)) ? std::make_pair(std::get<1>(anti_pair), std::get<0>(anti_pair)) : anti_pair;
      for (it = list.begin(); it != list.end(); ++it)
	{
	  tp = *it;
	  if (0 <= std::get<0>(tp) && 0 <= std::get<1>(tp))
	    {
	      tp = (std::get<0>(tp) > std::get<1>(tp)) ? std::make_pair(std::get<1>(tp), std::get<0>(tp)) : tp;
	      if (std::get<1>(ta) >= std::get<1>(tp) || std::get<0>(ta) <= std::get<0>(tp))
		{
		  if (std::get<0>(tp) < std::get<0>(ta))
		    tl.push_back(std::make_pair(std::get<0>(tp), std::get<0>(ta)));
		  if (std::get<1>(tp) > std::get<1>(ta))
		    tl.push_back(std::make_pair(std::get<1>(ta), std::get<1>(tp)));
		}
	      else
		tl.push_back(tp);
	    }
	}
      _list = tl;
    }
  else
    _list = std::list<std::pair<std::size_t, std::size_t> >(std::make_pair(-1, -1));
}

Range::Range(std::list<std::pair<std::size_t, std::size_t> > list, std::list<std::pair<std::size_t, std::size_t> > alist)
{
y
}
