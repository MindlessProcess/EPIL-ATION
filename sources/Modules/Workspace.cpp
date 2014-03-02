#include	"Workspace.hh"
#include	<cstring>
#include	<limits>

Workspace::Workspace()
{
}

void Workspace::set_wd(std::string const &wd)
{
  if (!shave::FileSystem::isdir(realpath(wd.c_str(), NULL)))
    {
      std::cerr << "Error <"+wd+">: No such directory" << std::endl;
      return;
    }
  this->_wd = wd;
}

std::string const &Workspace::get_wd()
{
  return (this->_wd);
}

Workspace::~Workspace()
{
}
