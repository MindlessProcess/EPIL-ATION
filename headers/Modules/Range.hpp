#ifndef RANGE_HPP_
# define RANGE_HPP_

# include <list>
# include <utility>

namespace	epil
{

  class		Range
  {
    int					_anti;
    std::list<std::pair<int, int> >	_list;

  public:
    Range(int anti = -1);
    Range(std::pair<int, int> pair, int anti = -1);
    Range(std::pair<int, int> pair, std::pair<int, int> anti_pair, int anti = -1);
    Range(std::list<std::pair<int, int> > list, int anti = -1);
    Range(std::list<std::pair<int, int> > list, std::pair<int, int> anti_pair, int anti = -1);
    Range(std::list<std::pair<int, int> > list, std::list<std::pair<int, int> > alist, int anti = -1);
    ~Range();

    int						getAnti() const;
    std::list<std::pair<int, int> >		getList() const;
  };

};

#endif /* !RANGE_HPP_ */
