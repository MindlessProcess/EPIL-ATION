#include <ActionWrite.hh>

using namespace epil;

ActionWrite::ActionWrite(std::string const &id)
  : Action(id)
{
}

ActionWrite &ActionWrite::wr_setElem(filetype::FileType filetype, std::string const &filename, epil::BlockList *blockList)
{
  if (!(filetype == filetype::DST ? this->_dst_set : this->_src_set))
  {
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
    }
  }

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
    dst_cur_line += utils::FileSystem::write_until((*dst_it).first - dst_cur_line, dst_infile, outfile);
    dst_cur_line += utils::FileSystem::ifstream_goto((*dst_it).second + 1 - dst_cur_line, dst_infile);
    src_cur_line += utils::FileSystem::ifstream_goto((*src_it).first - src_cur_line, src_infile);
    src_cur_line += utils::FileSystem::write_until((*src_it).second + 1 - src_cur_line, src_infile, outfile);
    ++dst_it;
    ++src_it;
  }
  dst_cur_line += utils::FileSystem::write_until(dst_cur_line, dst_infile, outfile);
  dst_infile.close();
  src_infile.close();
  outfile.close();
  std::string rename_cmd("mv " + this->_new_dst_file + " " + this->_dst_file);
  std::hash<std::string> str_hash;
  std::vector<std::string> file_vector;
  boost::split(file_vector, this->_dst_file, boost::algorithm::is_any_of("/"));
  utils::FileSystem::add_extension(file_vector[file_vector.size() - 1], "_" + std::to_string(str_hash(this->_dst_file)));
  std::string save_cmd("mv " + this->_dst_file + " " + utils::StringOperations::containerToString(file_vector, "/"));

  /* very dirty */
  system(save_cmd.c_str());
  system(rename_cmd.c_str());
}

ActionWrite::~ActionWrite()
{
}
