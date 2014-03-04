//
// ActionWrite.hh for Epil in /home/seiza/Documents/Git/epil-ation/headers/System
// 
// Made by Lyoma Guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Mar  4 14:12:58 2014 Lyoma Guillou
// Last update Tue Mar  4 15:41:44 2014 Lyoma Guillou
//

#ifndef		EPIL_SYSTEM_ACTIONWRITE_HH_
# define	EPIL_SYSTEM_ACTIONWRITE_HH_

# include	<iostream>
# include	<fstream>

# include	"Action.hh"
//
// Needed for setSrc() and setDst()
//
# include	"BlockList.hh"

namespace	epil
{
  class		ActionWrite : public Action
  {
  public:

    // Maybe an empty constructor limits the unpredictable results
    // And it forces the user to setSrc and setDst
    ActionWrite();

    // ActionWrite(std::string src, std::string dst/*, BlockList srcBlock, BlockList dstBlock*/);

    // User sets the needed modifications
    void	setSrc(std::string const &src, BlockList srcBlock);
    void	setDst(std::string const &dst, BlockList dstBlock);

    // ? getSrc() const;
    // ? getDst() const;

    // apply the modifications
    void	apply();

  private:
    std::ifstream	_src;
    std::ofstream	_dst;
    // BlockList		_srcBlock;
    // BlockList		_dstBlock;

    ~ActionWrite();
  };
};

#endif		/* !EPIL_SYSTEM_ACTIONWRITE_HH_ */
