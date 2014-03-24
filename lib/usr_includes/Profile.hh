#ifndef EPIL_PROFILE_HH_
# define EPIL_PROFILE_HH_

# include <iostream>
# include <string>
# include <list>

# include <epil/Action.hh>
# include <epil/utils/Console.hpp>

namespace epil
{
  class Profile
  {
  public:
    Profile();
    Profile(std::string const &id);
    ~Profile();
    void setId(std::string const &id);
    std::string const &getId();
    bool isComplete();
    Profile &setAction(Action*);
    template <typename T>
    Action *setAction(std::string const &id)
    {
      this->_actionList.push_back(new T(id));
      return (this->_actionList.back());
    }
    std::list<Action*> &getActionList();
    void changeActionOrder(std::string const&, std::string const&);
    void revertActionOrder();
    void apply();

  private:
    std::string	_id;
    std::list<Action*> _actionList;
  };
};

#endif /* !EPIL_PROFILE_HH_ */
