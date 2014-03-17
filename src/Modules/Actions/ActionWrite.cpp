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

  std::ifstream dst_file(this->_src_file);
  std::ifstream src_file(this->_dst_file);
  std::ofstream outfile(this->_new_dst_file);
  // char line[256];

  // for ( ; nbline != block.first && dst_file.good() && src_file.good(); ++nbline)
  // {
  //   char tmp_line[256];

  //   dst_file.getline(tmp_line, 256);
  //   outfile.write(tmp_line, 256);
  // }
  utils::FileSystem::write_until(4, dst_file, outfile);
  utils::FileSystem::ifstream_goto(5, dst_file);
  utils::FileSystem::ifstream_goto(4, src_file);
  utils::FileSystem::write_until(5, src_file, outfile);
  std::cout << "dst_file.eof() = " << dst_file.eof() << std::endl;
  utils::FileSystem::write_until(dst_file.eof(), dst_file, outfile);
  // dst_file.getline(line, 256);
  // utils::Console::nlog("line = "+std::string(line));

  // for (size_t cur_line = 5; cur_line < 5 && infile.good() && outfile.good(); ++cur_line)
  // {
  //   infile.getline(line, 256);
  //   outfile.write(line, strlen(line));
  //   if (infile.seekg(infile.tellg() - static_cast<std::streampos>(1)) && infile.get() == '\n')
  //     outfile.write("\n", 1);
  //   Console::nlog("line #"+std::to_string(cur_line)+" = "+line);
  // }


  // if (dst_file.is_open() && src_file.is_open() && outfile.is_open())
  // {
  //   for (unsigned int nbline = 0; dst_file.good() && src_file.good() && outfile.good(); ++nbline)
  //   {
  //     // if (line >= block.first && line <= block.second)
  //     // {
  //     // }
  //     // infile.getline(line, 256);
  //     // outfile.write(line, strlen(line));
  //     // int last_nl = infile.tellg();
  //     // if (infile.seekg(last_nl - 1) && infile.get() == '\n')
  //     //   outfile.write("\n", strlen("\n"));
  //     if (line_in_block(nbline))
  //     {
  //       infile.getline(line, 256)
  //       outfile.write(line, 256);
  //     }
  //     else
  //     {
  //       infile.getline(line, 256);
  //       outfile.write(line, strlen(line));
  //     }
  //   }
  // }
}

ActionWrite::~ActionWrite()
{
}
