int	main(int ac, char **av)
{
  int	i = 0;

  printf("i = %d\n", i);
  i = i + 1;
  if (i == 1)
    write(1, &i, 1);
  else
    printf("i != 1\n");
  exit(EXIT_SUCCESS);
}
