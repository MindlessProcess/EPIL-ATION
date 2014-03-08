//
// ActionCompile.cpp for Epil in /home/seiza/Documents/Git/epil-ation
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Sat Mar  8 14:39:47 2014 Lyoma Guillou
// Last update Sat Mar  8 18:51:56 2014 Lyoma Guillou
//

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/wait.h>
#include	<sys/types.h>

#include	<string>
#include	<iostream>

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
	std::cerr << "Error: No compiler set" << std::endl;
      if (obj.empty())
	std::cerr << "Error: No source files set" << std::endl;
    }
}

ActionCompile::ActionCompile() : Action(""), _path("") , _cmd("")
{
}

ActionCompile::~ActionCompile()
{
}

void		ActionCompile::_format_path()
{
  char		*path;
  unsigned	pos;

  pos = this->_path.find("~");
  this->_path = std::string(strcat(getenv("HOME"), this->_path.substr(pos + 1).c_str()));
}

void		ActionCompile::apply()
{
  pid_t		pid;

  pid = fork();
  if (0 > pid)
    std::cerr << "Fork error" << std::endl;
  if (0 == pid)
    {
      if (this->_path[0] == '~')
	this->_format_path();
      if (0 != this->_path.compare("."))
	{
	  if (0 > access(_path.c_str(), F_OK) && 0 > chdir(_path.c_str()))
	    {
	      std::cerr << "Error: Path is probably non existant" << std::endl;
	      exit(EXIT_FAILURE);
	    }
	  system(_cmd.c_str());
	  exit(EXIT_SUCCESS);
	}
    }
  else
    wait(0);
}
