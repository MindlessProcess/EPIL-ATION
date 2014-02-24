#ifndef PARSER_HPP_
# define PARSER_HPP_

# include <list>
# include <utility>
# include <iostream>
# include <fstream>

# include "Range.hpp"

namespace	epil
{
  class		Parser
  {
    // Bloc replacement testing!
    // Check overlapping blocs
    // Synthetise blocs
    // Check for bloc numbers

    std::ifstream	_src;
    std::ofstream	_dst;
    Range		_srcRange;
    Range		_dstRange;

  public:
    Parser();
    ~Parser();

  };
};

#endif /* !PARSER_HPP_ */
