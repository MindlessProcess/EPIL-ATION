#ifndef EPIL_EPIL_HH_
# define EPIL_EPIL_HH_

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>

# include <list>
# include <string>
# include <iostream>

# include <epil/BlockList.hh>
# include <epil/Profile.hh>

# include <epil/utils/FileSystem.hpp>
# include <epil/utils/Console.hpp>

namespace epil
{
  class Epil
  {
  public:
    Epil();
    ~Epil();
    bool loadProfile(Profile*);
    void useProfile(std::string const&);
    void wr_setDst(std::string const&, epil::BlockList const&); //DST_FILE, BLOCK
    void wr_setSrc(std::string const&, epil::BlockList const&); //SRC_FILE, BLOCK
    void wr_addDstBlockList(epil::BlockList const&);
    void wr_addSrcBlockList(epil::BlockList const&);
    void wr_run();
    inline std::string _writeToFile();
    inline bool _isfile(std::string const&);

  private:
    bool _dst_set;
    bool _src_set;
    std::string _dst_file;
    std::string _src_file;
    BlockList _dst_block;
    BlockList _src_block;
    std::list<Profile*> _profileList;
  };
};

#endif /* !EPIL_EPIL_HH_ */
