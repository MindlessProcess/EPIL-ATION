#include "ActionWrite.hh"

using namespace epil;

ActionWrite::ActionWrite(std::string const &id)
  : Action(id)
{
}

ActionWrite &ActionWrite::wr_setElem(filetype::FileType filetype, std::string const &filename, epil::BlockList *blockList)
{
  utils::Console::nlog("====In wr_setElem()====");
  if (!(filetype == filetype::DST ? this->_dst_set : this->_src_set))
  {
    utils::Console::log("Loading file <"+filename+">...\t");
    if (utils::FileSystem::isfile(filename))
    {
      if (filetype == filetype::DST)
      {
        this->_dst_file = filename;
        this->_dst_block  = blockList;
        this->_dst_set = !this->_dst_set;
      }
      else
      {
        this->_src_file = filename;
        this->_src_block  = blockList;
        this->_src_set = !this->_src_set;
      }
      utils::Console::nlog("OK");
      utils::Console::nlog("Lines to modify :");
      std::list<std::pair<int,int>> tmp_list = blockList->getList();
      for (std::list<std::pair<int,int>>::iterator it = tmp_list.begin(); it != tmp_list.end(); ++it)
        {
          utils::Console::nlog("std::pair<"+std::to_string((*it).first)+","+std::to_string((*it).second)+">");
        }
    }
    else
      utils::Console::nlog(std::cerr, "KO");
  }
  utils::Console::nlog("====Out of wr_setElem()====");

  return (*this);
}

void ActionWrite::apply()
{
  if (!this->_dst_set) {
      throw exceptions::incomplete_action("ActionWrite dst specifier is not set");
    }
  else if (!this->_src_set) {
      throw exceptions::incomplete_action("ActionWrite src specifier is not set");
    }

  utils::Console::nlog("In actionWrite <"+this->getId()+"> apply()");
  std::list<std::pair<int, int> > dst_list = this->_dst_block->getList();
  std::list<std::pair<int, int> > src_list = this->_src_block->getList();

  std::list<std::pair<int, int> >::iterator dst_it = dst_list.begin();
  std::list<std::pair<int, int> >::iterator src_it = src_list.begin();

  this->_new_dst_file = "misc/new_file.txt";

  std::ifstream dst_infile(this->_dst_file);
  std::ifstream src_infile(this->_src_file);
  std::ofstream outfile(this->_new_dst_file);

  std::streampos dst_cur_line = 0;
  std::streampos src_cur_line = 0;

  while (dst_it != dst_list.end() && src_it != src_list.end())
  {
    utils::Console::log("Block dst/src = <");
    utils::Console::log(std::to_string((*dst_it).first)+","+std::to_string((*dst_it).second));
    utils::Console::log("> / <");
    utils::Console::log(std::to_string((*src_it).first)+","+std::to_string((*src_it).second));
    utils::Console::nlog(">");

    dst_cur_line += utils::FileSystem::write_until((*dst_it).first - dst_cur_line, dst_infile, outfile);
    utils::Console::nlog("DST_CUR_LINE = "+std::to_string(dst_cur_line));

    dst_cur_line += utils::FileSystem::ifstream_goto((*dst_it).second + 1 - dst_cur_line, dst_infile);
    utils::Console::nlog("DST_CUR_LINE = "+std::to_string(dst_cur_line));

    src_cur_line += utils::FileSystem::ifstream_goto((*src_it).first - src_cur_line, src_infile);
    utils::Console::nlog("SRC_CUR_LINE = "+std::to_string(src_cur_line));

    src_cur_line += utils::FileSystem::write_until((*src_it).second + 1 - src_cur_line, src_infile, outfile);
    utils::Console::nlog("SRC_CUR_LINE = "+std::to_string(src_cur_line));

    ++dst_it;
    ++src_it;
  }
  dst_cur_line += utils::FileSystem::write_until(dst_cur_line, dst_infile, outfile);

  dst_infile.close();
  src_infile.close();
  outfile.close();

  //very dirty
  std::string rename_cmd("mv " + this->_new_dst_file + " " + this->_dst_file);
  std::hash<std::string> str_hash;
  std::vector<std::string> file_vector;
  boost::split(file_vector, this->_dst_file, boost::algorithm::is_any_of("/"));
  utils::FileSystem::add_extension(file_vector[file_vector.size() - 1], + std::to_string(str_hash(this->_dst_file)));
  std::string save_cmd("mv " + this->_dst_file + " " + utils::StringOperations::containerToString(file_vector, "/"));
  for (std::vector<std::string>::iterator it = file_vector.begin(); it != file_vector.end(); ++it)
    {
      std::cout << "file_vector= " << *it << std::endl;
    }
  // rename_command += this->_new_dst_file + " " + this->_dst_file;
  std::cout << "SAVE_CMD: " << save_cmd << std::endl;
  std::cout << "RENAME_CMD: " << rename_cmd << std::endl;
  
  system(save_cmd.c_str());
  system(rename_cmd.c_str());
}

ActionWrite::~ActionWrite()
{
}
