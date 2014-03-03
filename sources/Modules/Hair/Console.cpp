//
// Console.cpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Mon Mar  3 10:32:55 2014 Lucas Merlette
// Last update Mon Mar  3 11:41:47 2014 Lucas Merlette
//

#include	"Console.hh"

Console::Console()
{
}

template <typename T>
static inline void Console::log(T v_type)
{
  std::cout << v_type << std::endl;
}

template <>
static inline void Console::log<T&>(T &v_type)
{
  std::cout << v_type << std::endl;
}

template <>
static inline void Console::log<T*>(T *v_type)
{
  std::cout << v_type << std::endl;
}

Console::~Console()
{
}
