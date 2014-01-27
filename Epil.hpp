#include	<iostream>
#include	<fstream>
#include	<string>

class	Epil
{
public:
  Epil();
  Epil(std::string const&);
  ~Epil();
  void	modifySrc();
  void	modifySrc(std::string const&);
  void	modifySrc(Range&);
  void	modifySrc(std::string const&, Range&);
  void	recompileSrc();
  void	recompileSrc(std::string const&);
  void	recompileSrc(std::string const&);
  void	recompileSrc(std::string const&, std::string const&);
  void	relaunchSrc();
private:
  std::ifstream	infile;
};
