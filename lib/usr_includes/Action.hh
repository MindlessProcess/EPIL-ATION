#ifndef EPIL_ACTION_HH_
# define EPIL_ACTION_HH_

# include <iostream>
# include <string>
# include <vector>
# include <fstream>

# include <boost/algorithm/string.hpp>

# include <epil/BlockList.hh>
# include <epil/utils/Console.hpp>
# include <epil/utils/FileSystem.hpp>
# include <epil/utils/StringOperations.hpp>
# include <epil/exceptions/incomplete_action.hpp>

namespace epil
{
  class Action
  {
  public:
    Action(std::string const &id) :_id(id) {}
    virtual ~Action() {}
    std::string const &getId() const;
    void setId(std::string const &);
    virtual void apply() = 0;

  protected:
    std::string _id;
  };

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
    ActionWrite(std::string const &id);
    ~ActionWrite();
    ActionWrite &wr_setDst(std::string const&, epil::BlockList*);
    ActionWrite &wr_setSrc(std::string const&, epil::BlockList*);
    ActionWrite &wr_setElem(filetype::FileType filetype, std::string const&, epil::BlockList*);
    void apply();

  private:
    bool _dst_set;
    bool _src_set;
    std::string _dst_file;
    std::string _src_file;
    std::string _new_dst_file;
    BlockList *_dst_block;
    BlockList *_src_block;
  };

  class ActionCompile : public Action
  {
  public:
    ActionCompile(std::string const &id, std::string const &makeCmd = "make re", std::string const &path = ".");
    ActionCompile(std::string const &id, std::string const &cmd, std::string const &flag, std::string const &obj, std::string const &name = "", std::string const &path = ".");
    ~ActionCompile();
    void        apply();

  private:
    inline bool _isWorkingDir();
    inline bool _isValidPath();
    inline bool _changeDir();
    void _format_path();

    std::string _path;
    std::string _cmd;
  };

  class ActionExec : public Action
  {
  public:
    ActionExec(std::string const &id, std::string const &cmd);
    ~ActionExec();
    void apply();

  private:
    void _init();

    std::string _cmd;
    char **_arg;
  };
};

#endif /* !EPIL__ACTION_HH_ */
