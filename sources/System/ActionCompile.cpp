//
// ActionCompile.cpp for Epil in /home/seiza/Documents/Git/epil-ation
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Sat Mar  8 14:39:47 2014 Lyoma Guillou
// Last update Sat Mar  8 17:25:27 2014 Lyoma Guillou
//

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/wait.h>
#include	<sys/types.h>

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
      // Warn the user?
      // else
      // 	std::cout << "Warning: outfile will be 'a.out'" << std::endl;
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

void		ActionCompile::apply()
{
  // can fork here
  pid_t		pid;

  if (0 > (pid = fork()))
    std::cerr << "Fork error" << std::endl;
  if (0 == pid)
    {
      if (0 != this->_path.compare("."))
	{
	  std::cout << _path << std::endl;
	  if (0 > access(_path.c_str(), F_OK))
	    {
	      std::cerr << "Path is non existant" << std::endl;
	      return;
	    }
	  if (0 > chdir(_path.c_str()))
	    {
	      std::cerr << "Chdir error" << std::endl;
	      return;
	    }
	  system(_cmd.c_str());
	}
    }
  else
    {
      wait(0);
      return;
    }
}
