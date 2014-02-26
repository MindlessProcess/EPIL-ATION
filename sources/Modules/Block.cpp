//
// Block.cpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/sources/Modules
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:39:40 2014 Lucas Merlette
// Last update Tue Feb 25 02:04:45 2014 Lucas Merlette
//

#include	"Block.hh"

using namespace	epil;

Block::Block(int anti)
{
  _anti = (0 > anti) ? -1 : anti;
}

// Block::Block(std::pair<int, int> pair)
// {
//   _anti = -1;
//   if (0 <= std::get<0>(pair) && 0 <= std::get<1>(pair))
//     {
//       if (std::get<0>(pair) > std::get<1>(pair))
// 	_list.push_back(std::make_pair(std::get<1>(pair), std::get<0>(pair)));
//       else
// 	_list.push_back(pair);
//     }
// }

Block::Block(std::pair<int, int> pair, int anti)
{
  _anti = (0 > anti) ? -1 : anti;
  if (0 <= std::get<0>(pair) && 0 <= std::get<1>(pair))
    {
      if (std::get<0>(pair) > std::get<1>(pair))
	_list.push_back(std::make_pair(std::get<1>(pair), std::get<0>(pair)));
      else
	_list.push_back(pair);
    }
}

Block::Block(std::pair<int, int> pair, std::pair<int, int> anti_pair, int anti)
{
  _anti = (0 > anti) ? -1 : anti;
  if (0 <= std::get<0>(pair) && 0 <= std::get<1>(pair) && 0 <= std::get<0>(anti_pair) && 0 <= std::get<1>(anti_pair))
    {
      std::pair<int, int>	t_pair;
      std::pair<int, int>	t_anti_pair;
      t_pair = (std::get<0>(pair) > std::get<1>(pair)) ? std::make_pair(std::get<1>(pair), std::get<0>(pair)) : pair;
      t_anti_pair = (std::get<0>(anti_pair) > std::get<1>(anti_pair)) ? std::make_pair(std::get<1>(pair), std::get<0>(anti_pair)) : anti_pair;
      if (std::get<0>(t_pair) < std::get<0>(t_anti_pair))
	_list.push_back(std::make_pair(std::get<0>(t_pair), std::get<0>(t_anti_pair)));
      if (std::get<1>(t_pair) > std::get<1>(t_anti_pair))
	_list.push_back(std::make_pair(std::get<1>(t_anti_pair), std::get<1>(t_pair)));
    }
}

// Block::Block(std::list<std::pair<int, int> > list)
// {
//   std::list<std::pair<int, int> >		tl;
//   std::list<std::pair<int, int> >::iterator	it;
//   std::pair<int, int>				tp;

//   _anti = (0 > anti) ? -1 : anti;
//   if (!list.empty())
//     {
//       for (it = list.begin(); it != list.end(); ++it)
// 	{
// 	  tp = *it;
// 	  if (0 <= std::get<0>(tp) && 0 <= std::get<1>(tp))
// 	    {
// 	      if (std::get<0>(tp) > std::get<1>(tp))
// 		tl.push_back(std::make_pair(std::get<1>(tp), std::get<0>(tp)));
// 	      else
// 		tl.push_back(tp);
// 	    }
// 	}
//       _list = tl;
//     }
// }

Block::Block(std::list<std::pair<int, int> > list, int anti)
{
  std::list<std::pair<int, int> >		tl;
  std::list<std::pair<int, int> >::iterator	it;
  std::pair<int, int>				tp;

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
      _list = tl;
    }
}

Block::Block(std::list<std::pair<int, int> > list, std::pair<int, int> anti_pair, int anti)
{
  std::list<std::pair<int, int> >		tl;
  std::list<std::pair<int, int> >::iterator	it;
  std::pair<int, int>				tp;
  std::pair<int, int>				ta;

  _anti = (0 > anti) ? -1 : anti;
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
	      if (std::get<0>(ta) < std::get<1>(tp) && std::get<1>(ta) > std::get<0>(tp))
		{
		  if (std::get<0>(ta) > std::get<0>(tp))
		    tl.push_back(std::make_pair(std::get<0>(tp), std::get<0>(ta)));
		  if (std::get<1>(ta) < std::get<1>(tp))
		    tl.push_back(std::make_pair(std::get<1>(ta), std::get<1>(tp)));
		}
	      else
		tl.push_back(tp);
	    }
	}
      _list = tl;
    }
}

Block::Block(std::list<std::pair<int, int> > list, std::list<std::pair<int, int> > alist, int anti)
{
  std::list<std::pair<int, int> >		tl;
  std::list<std::pair<int, int> >::iterator	it;
  std::pair<int, int>				ta;
  std::pair<int, int>				tp;
  bool						flag = false;

  _anti = (0 > anti) ? -1 : anti;
  if (!list.empty())
    {
      for (it = list.begin(); it != list.end(); ++it)
	{
	  if (!alist.empty() && flag == false)
	    {
	      ta = alist.front();
	      ta = (std::get<0>(ta) > std::get<1>(ta)) ? std::make_pair(std::get<1>(ta), std::get<0>(ta)) : ta;
	      alist.pop_front();
	      flag = true;
	      it = list.begin();
	    }
	  tp = *it;
	  if (0 <= std::get<0>(tp) && 0 <= std::get<1>(tp))
	    {
	      tp = (std::get<0>(tp) > std::get<1>(tp)) ? std::make_pair(std::get<1>(tp), std::get<0>(tp)) : tp;
	      if (false != flag && std::get<0>(ta) < std::get<1>(tp) && std::get<1>(ta) > std::get<0>(tp))
		{
		  it = list.erase(it);
		  it = list.begin();
		  if (std::get<0>(ta) > std::get<0>(tp))
		    tl.push_back(std::make_pair(std::get<0>(tp), std::get<0>(ta)));
		  if (std::get<1>(ta) < std::get<1>(tp))
		    tl.push_back(std::make_pair(std::get<1>(ta), std::get<1>(tp)));
		  flag = false;
		}
	      else if (false == flag)
		tl.push_back(tp);
	    }
	}
      _list = tl;
    }
}

Block::~Block() {}

int	Block::getAnti() const
{
  return _anti;
}

std::list<std::pair<int, int>>	Block::getList() const
{
  return _list;
}
