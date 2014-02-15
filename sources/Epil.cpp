#include	"Epil.hpp"
#include	<exception>

Epil::Epil()
{
}

void  Epil::loadProfile(Profile *profile)
{
  if (profile->isComplete())
    this->_profileList.push_back(profile);
  else
    std::cerr << "Profile incomplete" << std::endl;
    // throw new std::exception("Fatal error: profile incomplete");
}

void  Epil::useProfile(std::string const &id)
{
  for (std::list<Profile*>::iterator it = this->_profileList.begin();
    it != this->_profileList.end(); ++it)
  {
    if (id.compare((*it)->getId()))
    {
      std::cout << "Profile found" << std::endl;
    }
  }
}

Epil::~Epil()
{
}
