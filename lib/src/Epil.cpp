#include <epil/Epil.hh>

using namespace	epil;

Epil::Epil()
  : _dst_set(false), _src_set(false)
{
}

bool	Epil::loadProfile(Profile *profile)
{
  if (!profile->isComplete())
    return (false);
  this->_profileList.push_back(profile);
  return (true);
}

void	Epil::useProfile(std::string const &id)
{
  for (std::list<Profile*>::iterator it = this->_profileList.begin();
       it != this->_profileList.end(); ++it)
    {
      if (!id.compare((*it)->getId()))
	{
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
