//
// ActionExec.cpp for Epil in /home/seiza/Documents/Git/epil-ation
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Mar  4 15:40:08 2014 Lyoma Guillou
// Last update Mon Mar 24 16:05:05 2014 Lyoma Guillou
//

#include	<string.h>
#include	<unistd.h>
#include	<signal.h>
#include	<sys/wait.h>
#include	<sys/types.h>

#include	<string>
#include	<sstream>
#include	<iostream>

#include	"Action.hh"
#include	"ActionExec.hh"

using namespace	epil;

ActionExec::ActionExec(std::string const &id, std::string const &cmd) : Action(id), _cmd(cmd), _arg(NULL)
{
  this->_init();
}

ActionExec::~ActionExec()
{
  for (int i = 0; this->_arg[i]; ++i)
    delete[] this->_arg[i];
  delete this->_arg;
}

void		ActionExec::_init()
{
  std::stringstream	ss;
  std::string		str;
  char			*tmp;
  unsigned int		i = 0;

  ss.flush();
  ss << this->_cmd;
  while (ss.good())
    {
      ss >> str;
      ++i;
    }
  ss.str(std::string());
  ss.clear();
  ss << this->_cmd;
  str.erase();
  this->_arg = new char * [i + 1];
  for (i = 0; ss.good(); ++i)
    {
      ss >> str;
      tmp = new char [str.length() + 1];
      tmp = strcpy(tmp, str.c_str());
      this->_arg[i] = tmp;
    }
  this->_arg[i] = NULL;
}

// Unforked version for implementation purpose

// void		ActionExec::apply()
// {
//   if (0 > (execvp(this->_arg[0], this->_arg)))
//     std::cerr << "Error: Child process could not execute" << std::endl;
// }

void		ActionExec::apply()
{
  pid_t		pid;

  pid = fork();
  if (0 > pid)
    {
      throw exceptions::incomplete_action("Fork Error");
      return;
    }
  if (0 == pid && 0 > (execvp(this->_arg[0], this->_arg)))
    throw exceptions::incomplete_action("Error: Child process could not execute");
  else
    wait(0);
}
