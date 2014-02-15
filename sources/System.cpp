#include	"System.hpp"

System::System()
{
  std::cout << "===================" << std::endl;
  std::cout << "In System Ctor" << std::endl;
  std::cout << "System successfully created" << std::endl;
  std::cout << "===================" << std::endl;
  Action *action = new Action<MODIFY>();
}

void	setAction(Action action) throw()
{
  if (action)
    this->_actionList.push_back(action);
  else
    throw new std::exception("Error: empty Action given");
}

void	setActionList(std::list<Action*> actionList)
{
  if (this->_actionList.size())
    this->_tempAL = this->_actionList;
  this->_actionList = actionList;
}

Action	&getAction() const
{
}

std::list<Action*>	&getActionList() const
{
}

/*
** reWrite functions
*/
void	reWrite(std::string &destFile, std::string &sourceFile)
{
}
void	reWrite(std::string &destFile, Range, std::string &sourceFile, Range, int, int = -1)
{
}
void	reWrite(std::string &destFile, std::string&, Range, int = -1)
{
}
void	reWrite(std::string &destFile, std::string&, std::list<int>, int = -1)
{
}
void	reWrite(std::string &destFile, std::string&, std::list<Range>, int = -1)
{
}

void	reCompile()
{
}

void	reExecute()
{
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
