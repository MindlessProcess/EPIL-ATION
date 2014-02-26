/**
 * @author Lucas Merlette
 * @created 25/02/2014
 * @description OUTDATED
 * This file represents the main class of Epil using the algorithm Min/Max
 */

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
