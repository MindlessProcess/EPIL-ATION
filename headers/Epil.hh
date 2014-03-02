/**
 * @author Lucas Merlette
 * @created 25/02/2014
 * @description
 * This file represents the main class of Epil ...
 */

#ifndef		EPIL_EPIL_HH_
# define	EPIL_EPIL_HH_

# include	<unistd.h>
# include	<sys/stat.h>
# include	<sys/types.h>

# include	<list>
# include	<string>
# include	<iostream>

# include	"Block.hh"
# include	"Profile.hh"

namespace	epil
{
  class		Epil
  {
  public:
    Epil();
    ~Epil();

    void loadProfile(Profile*);
    void useProfile(std::string const&);

    void wr_setDst(std::string const&, epil::Block const&); //DST_FILE, BLOCK
    void wr_setSrc(std::string const&, epil::Block const&); //SRC_FILE, BLOCK
    void wr_addDstBlock(epil::Block const&);
    void wr_addSrcBlock(epil::Block const&);
    void wr_run();

    inline bool	_isfile(std::string const&);

  private:
    std::string _dst_file;
    std::string _src_file;

    Block _dst_block;
    Block _src_block;

    std::list<Profile*> _profileList;
  };
};

#endif		/* !EPIL_EPIL_HH_ */
