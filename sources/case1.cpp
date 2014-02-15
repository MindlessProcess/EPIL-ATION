int main(int ac, char **av)
{
  if (ac != 2)
    return (0);
  std::string str(av[1]);

  if (str.compare("Hello"))
  {
    epil::Epil  *epil = new epil::Epil();
    reWrite();
    reCompile();
    reExec();
  }
}