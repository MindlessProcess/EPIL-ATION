//
// Parser.hpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/Modules
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:30:29 2014 Lucas Merlette
// Last update Sun Mar  2 15:20:13 2014 Lyoma Guillou
//

#ifndef		EPIL_MODULES_PARSER_HH_
# define	EPIL_MODULES_PARSER_HH_

# include	<list>
# include	<utility>
# include	<iostream>
# include	<fstream>

# include	"BlockList.hpp"

namespace	epil
{
  class		Parser
  {
  public:
    Parser()

  private:    
    std::ifstream	_src;
    std::ofstream	_dst;
    Block		_srcBlock;
    Block		_dstBlock;

    Parser();
    ~Parser();
  };
};

#endif		/* !EPIL_MODULES_PARSER_HH_ */
