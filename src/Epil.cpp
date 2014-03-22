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
      if (!id.compare((*it)->getId()))
	{
	  utils::Console::nlog("Profile found = "+(*it)->getId());
	  try
	    {
	      (*it)->apply();
	    }
	  catch (exceptions::incomplete_action const &e)
	    {
	      utils::Console::nlog(std::cerr, e.what());
	    }
	}
    }
}

Epil::~Epil()
{
}
