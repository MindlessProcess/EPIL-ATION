int	main(int ac, char **av)
{
  int	z = 0;

  printf("var z = <%d>\n", z);
  z = z + (2 * z);
  if (z >= 0)
    write(1, &z, 1);
  else
    printf("z < 0\n");
  printf("End of main\n");

  int x = 3;
  x += z;
  if (x >= z)
    {
      printf("x >= z\n");
    }
  else
    {
      printf("x < z");
    }

  printf("End of program, quit ? Yes");
  printf("Quiting the program...");
  exit(EXIT_SUCCESS);
}
