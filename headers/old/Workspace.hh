//
// Workspace.hh for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/Modules
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Sun Mar  2 15:13:37 2014 Lucas Merlette
// Last update Sun Mar  2 18:06:32 2014 Lucas Merlette
//

#ifndef  EPIL_MODULES_WORKSPACE_HH_
# define EPIL_MODULES_WORKSPACE_HH_

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>

# include <string>
# include <iostream>

# include "FileSystem.hpp"

class Workspace
{
public:
  Workspace();
  ~Workspace();

  void	set_wd(std::string const&);
  std::string const& get_wd();

  inline bool _isdir(std::string const&);
private:
  std::string	_wd;
};

#endif   /* !_EPIL_MODULES_WORKSPACE_HH_ */
