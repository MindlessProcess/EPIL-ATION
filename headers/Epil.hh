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

 # include	"BlockList.hh"
# include	"Profile.hh"
# include	"Workspace.hh"
# include	"Console.hh"

# include	"FileSystem.hpp"

namespace	epil
{
  class		Epil
  {
  public:
    Epil();
    ~Epil();

    void setWorkspace(std::string const &workspace_path = 0);
    Workspace *getWorkspace();

    /**
     * Profile methods
     */
    void loadProfile(Profile*);
    void useProfile(std::string const&);

    void wr_setDst(std::string const&, epil::BlockList const&); //DST_FILE, BLOCK
    void wr_setSrc(std::string const&, epil::BlockList const&); //SRC_FILE, BLOCK
    void wr_addDstBlockList(epil::BlockList const&);
    void wr_addSrcBlockList(epil::BlockList const&);
    void wr_run();

    /**
     * Inline methods
     */
    inline std::string	_writeToFile();
    inline bool		_isfile(std::string const&);

  private:
    bool _dst_set;
    bool _src_set;

    std::string _dst_file;
    std::string _src_file;

    BlockList _dst_block;
    BlockList _src_block;

    Workspace *_workspace;

    std::list<Profile*> _profileList;
  };
};

#endif		/* !EPIL_EPIL_HH_ */
