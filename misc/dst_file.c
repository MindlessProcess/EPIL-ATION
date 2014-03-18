int	main(int ac, char **av)
{
  int	z = -3;

  printf("var ");
  printf("z = %d\n", z);
  z = z * (2 * z);
  if (z >= 0)
    write(1, &z, 1);
  else
    printf("z < 0\n");

  int x = 3;
  x -= z;
  if (x == z)
    {
      printf("x = z\n");
    }
  else if (x < z)
    {
      printf("x < z");
    }
  else
    {
      printf("x > z");
    }

  printf("End of program, quit ? No");
  printf("Quiting anyway");
  exit(EXIT_SUCCESS);
}
