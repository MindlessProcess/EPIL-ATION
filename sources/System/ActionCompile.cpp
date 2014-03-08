//
// ActionCompile.cpp for Epil in /home/seiza/Documents/Git/epil-ation
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Sat Mar  8 14:39:47 2014 Lyoma Guillou
// Last update Sat Mar  8 15:36:39 2014 Lyoma Guillou
//

#include	"Action.hh"
#include	"ActionCompile.hh"

using namespace	epil;

ActionCompile::ActionCompile(std::string const &id, std::string const &makeCmd, std::string const &path) : Action(id), _path(path), _cmd(makeCmd)
{
}

ActionCompile::ActionCompile(std::string const &id, std::string const &cmd, std::string const &flag, std::string const &name, std::string const &obj, std::string const &path) : Action(id), _path(path)
{
  if (!cmd.empty() && !obj.empty())
    {
      this->_cmd = cmd + " -c " + obj;
      if (!name.empty())
	this->_cmd = this->_cmd + " -o " + name;
      if (!flag.empty())
	this->_cmd = this->_cmd + " " + flag;
    }
  else
    {
      if (cmd.empty())
	std::err << "Error: No compiler set" << std::endl;
      if (obj.empty())
	std::err << "Error: No source files set" << std::endl;
    }
}

ActionCompile::ActionCompile() : Action(""), _path("") , _cmd("")
{
}

ActionCompile::~ActionCompile()
{
}

void		ActionCompile::apply()
{
  
  // check path
  // fork and chdir to path
  // compile in path
  // copy binary if not in same path?

  // might fork here for directory purpose
  // maybe?
  // perhaps...
  // just in case
}
