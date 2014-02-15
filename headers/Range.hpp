#ifndef RANGE_HPP_
# define RANGE_HPP_

# include <utility>


namespace	epil
{

  class		Range
  {
    std::size_t						_anti;
    std::list<std::pair<std::size_t, std::size_t> >	_list;

  public:
    Range(std::size_t);
    Range(std::pair<std::size_t, std::size_t>);
    Range(std::pair<std::size_t, std::size_t>, std::size_t);
    Range(std::pair<std::size_t, std::size_t>, std::pair<std::size_t, std::size_t>);
    Range(std::list<std::pair<std::size_t, std::size_t> >);
    Range(std::list<std::pair<std::size_t, std::size_t> >, std::size_t);
    Range(std::list<std::pair<std::size_t, std::size_t> >, std::pair<std::size_t, std::size_t>);
    Range(std::list<std::pair<std::size_t, std::size_t> >, std::list<std::pair<std::size_t, std::size_t> >);
    ~Range();
  
  };

};

#endif /* !RANGE_HPP_ */
