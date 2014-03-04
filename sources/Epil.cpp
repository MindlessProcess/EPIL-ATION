//
// Epil.cpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Sun Mar  2 17:09:36 2014 Lucas Merlette
// Last update Sun Mar  2 17:59:16 2014 Lucas Merlette
//

#include	"Epil.hh"

using namespace	epil;

Epil::Epil()
  : _dst_set(false), _src_set(false)
{
}

void	Epil::setWorkspace(std::string const &workspace_path)
{
  (void)workspace_path;
  if (this->_workspace == NULL)
    {
      this->_workspace = new Workspace();
      this->_workspace->set_wd(get_current_dir_name());
    }
}

void	Epil::loadProfile(Profile *profile)
{
  if (profile->isComplete())
    this->_profileList.push_back(profile);
  else
    std::cerr << "Profile incomplete" << std::endl;
    // throw new std::exception("Fatal error: profile incomplete");
}

void	Epil::useProfile(std::string const &id)
{
  std::cout << "========In Epil::useProfile()============" << std::endl;
  std::cout << "Profile needed = " << id << std::endl;
  for (std::list<Profile*>::iterator it = this->_profileList.begin();
    it != this->_profileList.end(); ++it)
  {
    std::cout << "Profile ID = " << (*it)->getId() << std::endl;
    if (!id.compare((*it)->getId()))
    {
      std::cout << "Profile found = " << (*it)->getId() << std::endl;
    }
  }
  std::cout << "========Out of Epil::useProfile()========" << std::endl;
}

void	Epil::wr_setDst(std::string const &dst_file, BlockList const &block)
{
  if (!this->_dst_set)
    {
      std::cout << "Loading file <"+dst_file+">...\t";
      if (shave::FileSystem::isfile(dst_file))
	{
	  this->_dst_file	= dst_file;
	  this->_dst_block	= block;
	  std::cout << "OK" << std::endl;
	  std::cout << "Lines to modify :" << std::endl;
	  std::list<std::pair<int,int>> tmp_list = block.getList();
	  for (std::list<std::pair<int,int>>::iterator it = tmp_list.begin(); it != tmp_list.end(); ++it)
	    {
	      std::cout << "std::pair<" << (*it).first << "," << (*it).second << ">" << std::endl;
	    }
	  this->_dst_set = !this->_dst_set;
	}
      else
	std::cerr << "KO" << std::endl;
    }
}

void	Epil::wr_setSrc(std::string const &src_file, BlockList const &block)
{
  if (!this->_src_set)
    {
      std::cout << "Loading file <"+src_file+">...\t";
      if (shave::FileSystem::isfile(src_file))
	{
	  this->_src_file	= src_file;
	  this->_src_block	= block;
	  std::cout << "OK" << std::endl;
	  std::cout << "Lines for modification :" << std::endl;
	  std::list<std::pair<int,int>> tmp_list = block.getList();
	  for (std::list<std::pair<int,int>>::iterator it = tmp_list.begin(); it != tmp_list.end(); ++it)
	    {
	      std::cout << "std::pair<" << (*it).first << "," << (*it).second << ">" << std::endl;
	    }
	  this->_src_set = !this->_src_set;
	}
      else
	std::cerr << "KO" << std::endl;
    }
}

void	Epil::wr_addDstBlockList(BlockList const &dst_block)
{
  (void)dst_block;
  // this->_dst_block.addBlockList(dst_block);
}

void	Epil::wr_addSrcBlockList(BlockList const &src_block)
{
  (void)src_block;
  // this->_src_block.addBlockList(src_block);
}

void	Epil::wr_run()
{
  if (!this->_dst_set || !this->_src_set)
    {
      std::cerr << "Error: Can't run, dst or src block init not complete" << std::endl;
    }
  std::cout << "Writing from file <"+this->_src_file+"> to file <"+this->_dst_file+">...\t";
  std::cout << this->_writeToFile();
  std::cout << std::endl;
}

inline std::string	Epil::_writeToFile()
{
  return ("OK");
}

inline bool	Epil::_isfile(std::string const &name)
{
  struct stat buffer;
  return (stat(name.c_str(), &buffer) == 0);
}

Epil::~Epil()
{
}
