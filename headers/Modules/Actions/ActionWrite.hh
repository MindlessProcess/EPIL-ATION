#ifndef	EPIL_MODULES_ACTIONS_ACTIONWRITE_HH_
# define EPIL_MODULES_ACTIONS_ACTIONWRITE_HH_

# include <cstring>
# include <stdlib.h>

# include <iostream>
# include <fstream>
# include <string>
# include <vector>

# include <boost/algorithm/string.hpp>

# include "Action.hh"
# include "BlockList.hh"

# include "StringOperations.hpp"
# include "FileSystem.hpp"
# include "Console.hpp"

#include "incomplete_action.hpp"

namespace epil
{
    namespace filetype
    {
        enum FileType
        {
            DST,
            SRC
        };
    };

  class ActionWrite : public Action
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
    ActionWrite &wr_setElem(filetype::FileType filetype, std::string const&, epil::BlockList*);
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
