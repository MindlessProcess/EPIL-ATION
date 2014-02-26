//
// Epil.cpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/sources
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Feb 24 23:39:24 2014 Lucas Merlette
// Last update Tue Feb 25 02:04:07 2014 Lucas Merlette
//

#include	"Epil.hh"

using namespace	epil;

Epil::Epil()
{
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
  for (std::list<Profile*>::iterator it = this->_profileList.begin();
    it != this->_profileList.end(); ++it)
  {
    if (id.compare((*it)->getId()))
    {
      std::cout << "Profile found" << std::endl;
    }
  }
}

void	Epil::wr_setDst(std::string const &dst_file, Block const &block)
{
  std::cout << "Loading file <"+dst_file+">...\t";
  if (this->_isfile(dst_file))
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
    }
  else
    {
      std::cerr << "FAIL" << std::endl;
      return;
    }
}

void	Epil::wr_setSrc(std::string const &src_file, Block const &block)
{
  std::cout << "Loading file <"+src_file+">...\t";
  if (this->_isfile(src_file))
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
    }
  else
    {
      std::cerr << "FAIL" << std::endl;
      //throw std::exception();
      return;
    }
}

inline bool	Epil::_isfile(std::string const &name)
{
  struct stat buffer;
  return (stat(name.c_str(), &buffer) == 0);
}

Epil::~Epil()
{
}
