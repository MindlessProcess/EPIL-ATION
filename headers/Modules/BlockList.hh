#ifndef		EPIL_MODULES_BLOCKLIST_HH_
# define	EPIL_MODULES_BLOCKLIST_HH_

# include	<list>
# include	<tuple>
# include	<utility>
# include	<iostream>

namespace	epil
{
  class		BlockList
  {
  public:
    BlockList();
    BlockList(std::pair<int, int> pair);
    BlockList(std::pair<int, int> pair, std::pair<int, int> anti_pair);
    BlockList(std::list<std::pair<int, int> > list);
    BlockList(std::list<std::pair<int, int> > list, std::pair<int, int> anti_pair);
    BlockList(std::list<std::pair<int, int> > list, std::list<std::pair<int, int> > alist);
    ~BlockList();

    std::list<std::pair<int, int> >		getList() const;

  private:
    std::list<std::pair<int, int> >	_list;

    void				_merge_list();
    void				_sort_list();
  };  
};

#endif		/* !EPIL_MODULES_BLOCKLIST_HH_ */
