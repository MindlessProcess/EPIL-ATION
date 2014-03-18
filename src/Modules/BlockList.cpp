//
// Block.cpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/sources/Modules
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:39:40 2014 Lucas Merlette
// Last update Tue Mar 18 12:00:24 2014 Lyoma Guillou
//

#include	"BlockList.hh"

using namespace	epil;

static inline bool	pos_pair(std::pair<int, int> pair)
{
  return (0 <= std::get<0>(pair) && 0 <= std::get<1>(pair));
}

static inline bool	dsc_pair(std::pair<int, int> pair)
{
  return (std::get<0>(pair) > std::get<1>(pair));
}

static inline std::pair<int, int>	swap_pair(std::pair<int, int> pair)
{
  return (std::make_pair(std::get<1>(pair), std::get<0>(pair)));
}

BlockList::BlockList(int anti)
{
  this->_anti = (0 > anti) ? -1 : anti;
}

BlockList::BlockList(std::pair<int, int> pair, int anti)
{
  this->_anti = (0 > anti) ? -1 : anti;
  if (pos_pair(pair))
    {
      if (dsc_pair(pair))
	this->_list.push_back(swap_pair(pair));
      else
	this->_list.push_back(pair);
    }
}

static inline bool	asc_bound(std::pair<int, int> p1, std::pair<int, int> p2)
{
  return (std::get<1>(p2) < std::get<1>(p1));
}

static inline bool	dsc_bound(std::pair<int, int> p1, std::pair<int, int> p2)
{
  return (std::get<0>(p2) > std::get<0>(p1));
}

static inline std::pair<int, int>	low_bound(std::pair<int, int> p1, std::pair<int, int> p2)
{
  return (std::make_pair(std::get<0>(p1), std::get<0>(p2) - 1));
}

static inline std::pair<int, int>	high_bound(std::pair<int, int> p1, std::pair<int, int> p2)
{
  return (std::make_pair(std::get<1>(p2) + 1, std::get<1>(p1)));
}

BlockList::BlockList(std::pair<int, int> pair, std::pair<int, int> anti_pair, int anti)
{
  this->_anti = (0 > anti) ? -1 : anti;
  if (pos_pair(pair) && pos_pair(anti_pair))
    {
      std::pair<int, int>	tp;
      std::pair<int, int>	ta;

      tp = (dsc_pair(pair)) ? swap_pair(pair) : pair;
      ta = (dsc_pair(anti_pair)) ? swap_pair(anti_pair) : anti_pair;
      if (std::get<0>(ta) < std::get<1>(tp) && std::get<1>(ta) > std::get<0>(tp))
      	{
	  if (dsc_bound(tp, ta))
	    this->_list.push_back(low_bound(tp, ta));
	  if (asc_bound(tp, ta))
	    this->_list.push_back(high_bound(tp, ta));
	}
      else
	_list.push_back(tp);
    }
  this->_sort_list();
}

BlockList::BlockList(std::list<std::pair<int, int> > list, int anti)
{
  std::list<std::pair<int, int> >		tl;
  std::list<std::pair<int, int> >::iterator	it;
  std::pair<int, int>				tp;

  this->_anti = (0 > anti) ? -1 : anti;
  if (!list.empty())
    {
      for (it = list.begin(); it != list.end(); ++it)
	{
	  tp = *it;
	  if (pos_pair(tp))
	    {
	      if (dsc_pair(tp))
		tl.push_back(swap_pair(tp));
	      else
		tl.push_back(tp);
	    }
	}
      this->_list = tl;
    }
  this->_sort_list();
}

BlockList::BlockList(std::list<std::pair<int, int> > list, std::pair<int, int> anti_pair, int anti)
{
  std::list<std::pair<int, int> >		tl;
  std::list<std::pair<int, int> >::iterator	it;
  std::pair<int, int>				tp;
  std::pair<int, int>				ta;

  this->_anti = (0 > anti) ? -1 : anti;
  if (!list.empty())
    {
      ta = std::make_pair(-1, -1);
      if (pos_pair(anti_pair))
	ta = (dsc_pair(anti_pair)) ? swap_pair(anti_pair) : anti_pair;
      for (it = list.begin(); it != list.end(); ++it)
	{
	  tp = *it;
	  if (pos_pair(tp))
	    {
	      tp = (dsc_pair(tp)) ? swap_pair(tp) : tp;
	      if (std::get<0>(ta) < std::get<1>(tp) && std::get<1>(ta) > std::get<0>(tp))
		{
		  if (dsc_bound(tp, ta))
		    tl.push_back(low_bound(tp, ta));
		  if (asc_bound(tp, ta))
		    tl.push_back(high_bound(tp, ta));
		}
	      else
		tl.push_back(tp);
	    }
	}
      this->_list = tl;
    }
  this->_sort_list();
}

BlockList::BlockList(std::list<std::pair<int, int> > list, std::list<std::pair<int, int> > alist, int anti)
{
  std::list<std::pair<int, int> >		tl;
  std::list<std::pair<int, int> >::iterator	it;
  std::pair<int, int>				ta;
  std::pair<int, int>				tp;
  bool						flag = false;

  this->_anti = (0 > anti) ? -1 : anti;
  if (!list.empty())
    {
      for (it = list.begin(); it != list.end(); ++it)
	{
	  if (!alist.empty() && flag == false)
	    {
	      ta = alist.front();
	      ta = (dsc_pair(ta)) ? swap_pair(ta) : ta;
	      alist.pop_front();
	      flag = true;
	      it = list.begin();
	    }
	  tp = *it;
	  if (pos_pair(tp))
	    {
	      tp = (dsc_pair(tp)) ? swap_pair(tp) : tp;
	      if (false != flag && std::get<0>(ta) < std::get<1>(tp) && std::get<1>(ta) > std::get<0>(tp))
		{
		  it = list.erase(it);
		  it = list.begin();
		  if (dsc_bound(tp, ta))
		    tl.push_back(low_bound(tp, ta));
		  if (asc_bound(tp, ta))
		    tl.push_back(high_bound(tp, ta));
		  flag = false;
		}
	      else if (false == flag)
		tl.push_back(tp);
	    }
	}
      this->_list = tl;
    }
  this->_sort_list();
}

BlockList::~BlockList() {}

int	BlockList::getAnti() const
{
  return this->_anti;
}

std::list<std::pair<int, int> >	BlockList::getList() const
{
  return this->_list;
}

void	BlockList::_merge_list()
{
  std::list<std::pair<int, int> >::iterator	it;
  std::list<std::pair<int, int> >::iterator	nx;
  bool						flag;

  for (it = this->_list.begin(); it != this->_list.end(); ++it)
    {
      nx = it;
      if (it != this->_list.end())
	++nx;
      if (true == flag)
	{
	  it = this->_list.begin();
	  flag = false;
	}
      if (std::get<1>(*it) > std::get<0>(*nx))
	{
	  *it = std::make_pair(std::get<0>(*it), std::get<1>(*nx));
	  it = this->_list.erase(nx);
	  flag = true;
	}
    }
}

void	BlockList::_sort_list()
{
  this->_list.sort();
  this->_merge_list();
}
