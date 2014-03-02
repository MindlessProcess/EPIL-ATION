//
// Block.hpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/Modules
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:31:33 2014 Lucas Merlette
// Last update Sun Mar  2 13:44:03 2014 Lyoma Guillou
//

#ifndef		EPIL_MODULES_BLOCKS_HH_
# define	EPIL_MODULES_BLOCKS_HH_

# include	<list>
# include	<tuple>
# include	<utility>
# include	<iostream>

namespace	epil
{
  class		BlockList
  {
    int					_anti;
    std::list<std::pair<int, int> >	_list;

  public:
    BlockList(int anti = -1);
    BlockList(std::pair<int, int> pair, int anti = -1);
    BlockList(std::pair<int, int> pair, std::pair<int, int> anti_pair, int anti = -1);
    BlockList(std::list<std::pair<int, int> > list, int anti = -1);
    BlockList(std::list<std::pair<int, int> > list, std::pair<int, int> anti_pair, int anti = -1);
    BlockList(std::list<std::pair<int, int> > list, std::list<std::pair<int, int> > alist, int anti = -1);
    ~BlockList();

    int						getAnti() const;
    std::list<std::pair<int, int> >		getList() const;
  };
};

#endif		/* !EPIL_MODULES_BLOCKS_HH_ */
