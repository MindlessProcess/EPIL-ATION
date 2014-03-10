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
      hair::Console::log("Action <"+this->_id+"> : ");
      std::cout << "Loading file <"+dst_file+">...\t";
      if (shave::FileSystem::isfile(dst_file))
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
      hair::Console::log("Action <"+this->_id+"> : ");
      std::cout << "Loading file <"+src_file+">...\t";
      if (shave::FileSystem::isfile(src_file))
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
  hair::Console::nlog("In actionWrite <"+this->getId()+"> apply()");
}

ActionWrite::~ActionWrite()
{
}
