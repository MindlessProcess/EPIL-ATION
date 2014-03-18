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
    BlockList(int anti = -1);
    BlockList(std::pair<int, int> pair, int anti = -1);
    BlockList(std::pair<int, int> pair, std::pair<int, int> anti_pair, int anti = -1);
    BlockList(std::list<std::pair<int, int> > list, int anti = -1);
    BlockList(std::list<std::pair<int, int> > list, std::pair<int, int> anti_pair, int anti = -1);
    BlockList(std::list<std::pair<int, int> > list, std::list<std::pair<int, int> > alist, int anti = -1);
    ~BlockList();

    int						getAnti() const;
    std::list<std::pair<int, int> >		getList() const;

  private:
    int					_anti;
    std::list<std::pair<int, int> >	_list;

    //    void				_merge_list();
    void				_sort_list();
  };  
};

#endif		/* !EPIL_MODULES_BLOCKLIST_HH_ */
