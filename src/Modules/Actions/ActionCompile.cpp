//
// ActionCompile.cpp for Epil in /home/seiza/Documents/Git/epil-ation
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Sat Mar  8 14:39:47 2014 Lyoma Guillou
// Last update Tue Mar 25 12:07:40 2014 Lyoma Guillou
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

ActionCompile::ActionCompile(std::string const &id, std::string const &cmd, std::string const &flag, std::string const &obj, std::string const &name, std::string const &path) : Action(id), _path(path)
{
  if (!cmd.empty() && !obj.empty())
    {
      this->_cmd = cmd + " " + obj;
      if (!name.empty())
	this->_cmd = this->_cmd + " -o " + name;
      if (!flag.empty())
	this->_cmd = this->_cmd + " " + flag;
    }
  else
    {
      if (cmd.empty())
	throw exceptions::incomplete_action("Error: No compiler set");
      if (obj.empty())
	throw exceptions::incomplete_action("Error: No source files set");
    }
}

ActionCompile::~ActionCompile()
{
}

inline bool	ActionCompile::_isWorkingDir()
{
  if (0 == this->_path.compare(".") || 0 == this->_path.compare(getenv("PWD")))
    return true;
  return false;
}

inline bool	ActionCompile::_isValidPath()
{
  if (0 == access(this->_path.c_str(), F_OK))
    return true;
  throw exceptions::incomplete_action("Error: Access() could not find the file");
  return false;
}

inline bool	ActionCompile::_changeDir()
{
  if (0 == chdir(this->_path.c_str()))
    return true;
  throw exceptions::incomplete_action("Error: Chdir() could not open directory");
  return false;
}

void		ActionCompile::_format_path()
{
  unsigned	pos;

  if (std::string::npos != this->_path.find("~"))
    {
      pos = this->_path.find("~");
      this->_path = std::string(strcat(getenv("HOME"), this->_path.substr(pos + 1).c_str()));
    }
}

void		ActionCompile::apply()
{
  pid_t		pid;

  pid = fork();
  if (0 > pid)
    throw exceptions::incomplete_action("Fork error");
  if (0 == pid)
    {
      this->_format_path();
      if (!_isWorkingDir())
	if (!_isValidPath() || !_changeDir())
	  exit(EXIT_FAILURE);
      std::cout << "Compiling: " << this->_cmd << std::endl;
      system(this->_cmd.c_str());
      exit(EXIT_SUCCESS);
    }
  else
    wait(0);
}
