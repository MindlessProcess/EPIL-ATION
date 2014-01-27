#include	"System.hpp"

System::System()
{
  std::cout << "===================" << std::endl;
  std::cout << "In System Ctor" << std::endl;
  std::cout << "System successfully created" << std::endl;
  std::cout << "===================" << std::endl;
  Action *action = new Action<MODIFY>();
}

System::~System()
{
  std::cout << "===================" << std::endl;
  std::cout << "In System Dtor" << std::endl;
  for (std::list<Action*>::iterator it = this->_actionList.begin();
       it != this->_actionList.end(); ++it)
    delete it->second;
  this->_currentWindow = NULL;
  delete this->_window;
  this->_window = NULL;
  std::cout << "System successfully cleared" << std::endl;
  std::cout << "===================" << std::endl;
}
