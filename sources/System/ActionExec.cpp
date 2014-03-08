//
// ActionExec.cpp for Epil in /home/seiza/Documents/Git/epil-ation
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Mar  4 15:40:08 2014 Lyoma Guillou
// Last update Sat Mar  8 14:23:07 2014 Lyoma Guillou
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

ActionExec::ActionExec() : Action(""), _cmd(""), _arg(NULL)
{
}

ActionExec::ActionExec(std::string const &id, std::string const &cmd, std::string const &opt) : Action(id), _cmd(cmd + " " + opt), _arg(NULL)
{
  // parse cmd and opt
  // must create an array of char *
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

ActionExec::~ActionExec()
{
  for (int i = 0; this->_arg[i]; ++i)
    delete[] this->_arg[i];
  delete this->_arg;
}

void		ActionExec::apply()
{
  execvp(this->_arg[0], this->_arg);
}

// fork needed?

/*
void		ActionExec::apply()
{
  pid_t		pid;

  pid = fork();
  if (0 > pid)
    {
      std::cerr << "Fork Error" << std::endl;
      return;
    }
  if (0 == pid)
    {
      // child

      // get the parent process to kill
      pid_t	parent = getppid();

      // changing process group ?
      sleep(3);
      if (0 > setpgid(getpid(), getpid()))
	std::cerr << "setpgid error" << std::endl;
      kill(parent, SIGINT);
      while (true)
	{
	  sleep(1);
	  std::cout << "child here" << std::endl;
	}
    }
  else
    {
      // parent
      
      // detach child here
      // assing child to pgid
      while (true)
	{
	  sleep(1);
	  std::cout << "parent here" << std::endl;
	  // loop to wait on child to kill the parent
	}
    }
}
*/
