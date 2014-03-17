int	main(int ac, char **av)
{
  int	z = 0;

  printf("z = %d\n", z);
  z = z * (2 * z);
  if (z >= 0)
    write(1, &z, 1);
  else
    printf("z < 0\n");
  exit(EXIT_SUCCESS);
}
