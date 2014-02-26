//
// Parser.hpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/Modules
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:30:29 2014 Lucas Merlette
// Last update Mon Feb 24 23:31:24 2014 Lucas Merlette
//

#ifndef		EPIL_MODULES_PARSER_HH_
# define	EPIL_MODULES_PARSER_HH_

# include	<list>
# include	<utility>
# include	<iostream>
# include	<fstream>

# include	"Block.hpp"

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
    Block		_srcBlock;
    Block		_dstBlock;

  public:
    Parser();
    ~Parser();

  };
};

#endif		/* !EPIL_MODULES_PARSER_HH_ */
