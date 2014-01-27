#include	<unistd.h>
#include	<iostream>
#include	<string>
#include	<iomanip>

int main(int ac, char **av)
{
  pid_t	slave;
  std::string	buffer;

  std::cin >> buffer;
  if (!buffer.compare("EPIL invoke"))
    {
      if ((slave = fork()) == -1)
	return (0);
      else if (slave == 0)
	{
	  std::cout << "You entered EPIL invokation" << std::endl;
	  //Child process
	}
    }
  else
    {
      std::cout << "Buffer given: " << buffer << std::endl;
    }
}
