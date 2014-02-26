//
// Epil.hh for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:33:19 2014 Lucas Merlette
// Last update Tue Feb 25 00:36:54 2014 Lucas Merlette
//

#ifndef		EPIL_EPIL_HH_
# define	EPIL_EPIL_HH_

# include	<list>
# include	<string>
# include	<iostream>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<unistd.h>

# include	"Profile.hh"
# include	"Block.hh"

namespace	epil
{
  class		Epil
  {
  public:
    Epil();
    ~Epil();

    void	loadProfile(Profile*);
    void	useProfile(std::string const&);

    void	wr_setDst(std::string const&, epil::Block const&); //wr_setDst(DST_FILE, BLOCK);
    void	wr_setSrc(std::string const&, epil::Block const&); //wr_setSrc(SRC_FILE, BLOCK);

    inline bool	_isfile(std::string const&);

  private:
    std::list<Profile*>	_profileList;
    std::string		_dst_file;
    std::string		_src_file;
    Block		_dst_block;
    Block		_src_block;
  };
};

#endif		/* !EPIL_EPIL_HH_ */
