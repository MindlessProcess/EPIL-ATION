void  load_profile(epil::Epil &epil)
{
  epil::Profile *profile = new epil::Profile();
  profile.addAction(MODIFY);
  profile.addAction(RECOMPILE);
  profile.addAction(RELAUNCH);
  profile.setName("SIGSEV_ENCOUNTER");
  epil.createProfile(profile);
}

int main(int ac, char **av)
{
  if (ac != 2)
    return (0);
  std::string str(av[1]);

  epil::Epil *epil = new epil::Epil();
  load_profile(*epil);
  if (str.compare("Hello"))
    epil->loadProfile("SIGSEV_ENCOUNTER");
}