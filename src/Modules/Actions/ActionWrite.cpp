#include "ActionWrite.hh"

using namespace epil;

ActionWrite::ActionWrite(std::string const &id)
  : Action(id)
{
}

ActionWrite &ActionWrite::wr_setDst(std::string const &dst_file, epil::BlockList *blockList)
{
  if (!this->_dst_set)
  {
    utils::Console::log("Action <"+this->_id+"> : ");
    std::cout << "Loading file <"+dst_file+">...\t";
    if (utils::FileSystem::isfile(dst_file))
    {
      this->_dst_file	= dst_file;
      this->_dst_block	= blockList;
      std::cout << "OK" << std::endl;
      std::cout << "Lines to modify :" << std::endl;
      std::list<std::pair<int,int>> tmp_list = blockList->getList();
      for (std::list<std::pair<int,int>>::iterator it = tmp_list.begin(); it != tmp_list.end(); ++it)
        {
          std::cout << "std::pair<" << (*it).first << "," << (*it).second << ">" << std::endl;
        }
      this->_dst_set = !this->_dst_set;
    }
    else
      std::cerr << "KO" << std::endl;
  }
  return (*this);
}

ActionWrite &ActionWrite::wr_setSrc(std::string const &src_file, epil::BlockList *blockList)
{
  if (!this->_src_set)
  {
    utils::Console::log("Action <"+this->_id+"> : ");
    std::cout << "Loading file <"+src_file+">...\t";
    if (utils::FileSystem::isfile(src_file))
    {
      this->_src_file	= src_file;
      this->_src_block	= blockList;
      std::cout << "OK" << std::endl;
      std::cout << "Lines to modify :" << std::endl;
      std::list<std::pair<int,int>> tmp_list = blockList->getList();
      for (std::list<std::pair<int,int>>::iterator it = tmp_list.begin(); it != tmp_list.end(); ++it)
        {
          std::cout << "std::pair<" << (*it).first << "," << (*it).second << ">" << std::endl;
        }
      this->_src_set = !this->_src_set;
    }
    else
      std::cerr << "KO" << std::endl;
  }
  return (*this);
}

void ActionWrite::apply()
{
  utils::Console::nlog("In actionWrite <"+this->getId()+"> apply()");
  std::list<std::pair<int, int> > list = this->_dst_block->getList();
  for (std::list<std::pair<int, int> >::iterator it = list.begin(); it != list.end(); ++it)
  {
    utils::Console::log("Block.first: <");
    utils::Console::log((*it).first);
    utils::Console::nlog(">");

    utils::Console::log("Block.second: <");
    utils::Console::log((*it).second);
    utils::Console::nlog(">");
  }

  this->_new_dst_file = "misc/new_file.c";

  std::ifstream dst_infile(this->_dst_file);
  std::ifstream src_infile(this->_src_file);
  std::ofstream outfile(this->_new_dst_file);

  utils::FileSystem::write_until(4, dst_infile, outfile);
  utils::FileSystem::ifstream_goto(5, dst_infile);
  utils::FileSystem::ifstream_goto(4, src_infile);
  utils::FileSystem::write_until(5, src_infile, outfile);
  std::cout << "dst_file.eof() = " << dst_infile.eof() << std::endl;
  utils::FileSystem::write_until(dst_infile.eof(), dst_infile, outfile);
  // dst_file.getline(line, 256);
  // utils::Console::nlog("line = "+std::string(line));

  dst_infile.close();
  src_infile.close();
  outfile.close();
}

ActionWrite::~ActionWrite()
{
}
