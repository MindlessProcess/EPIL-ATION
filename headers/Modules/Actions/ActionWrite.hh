//
// ActionWrite.hh for Epil in /home/seiza/Documents/Git/epil-ation/headers/System
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Mar  4 14:12:58 2014 Lyoma Guillou
// Last update Tue Mar  4 17:10:04 2014 Lyoma Guillou
//

#ifndef		EPIL_MODULES_ACTIONS_ACTIONWRITE_HH_
# define	EPIL_MODULES_ACTIONS_ACTIONWRITE_HH_

# include   <cstring>
# include   <stdlib.h>

# include   <iostream>
# include   <fstream>
# include   <string>

# include	"Action.hh"
# include	"BlockList.hh"

# include	"FileSystem.hpp"
# include	"Console.hpp"

namespace	epil
{
  class		ActionWrite : public Action
  {
  public:

    // Maybe an empty constructor limits the unpredictable results
    // And it forces the user to setSrc and setDst
    ActionWrite(std::string const &id);
    ~ActionWrite();

    // ActionWrite(std::string src, std::string dst/*, BlockList srcBlock, BlockList dstBlock*/);

    // User sets the needed modifications
    // void setSrc(std::string const &src, BlockList srcBlock);
    // void setDst(std::string const &dst, BlockList dstBlock);

    ActionWrite &wr_setDst(std::string const&, epil::BlockList*); //DST_FILE, BLOCK
    ActionWrite &wr_setSrc(std::string const&, epil::BlockList*); //SRC_FILE, BLOCK
    // void wr_addDstBlockList(epil::BlockList const&);
    // void wr_addSrcBlockList(epil::BlockList const&);
    // void wr_run();

    // ? getSrc() const;
    // ? getDst() const;

    // apply the modifications
    void  apply();

  private:
    bool _dst_set;
    bool _src_set;

    std::string _dst_file;
    std::string _src_file;
    
    std::string _new_dst_file;

    BlockList   *_dst_block;
    BlockList   *_src_block;
    // std::ifstream  _src;
    // std::ofstream  _dst;

  };
};

#endif		/* !EPIL_MODULES_ACTIONS_ACTIONWRITE_HH_ */
