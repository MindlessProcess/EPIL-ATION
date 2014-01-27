int main(int ac, char **av)
{
    pid_t   slave;
    char    *buffer;

    if ((slave = fork()) == -1)
    {
        return (EXIT_FAILURE);
    }

    if (slave == 0)
    {
        // slave side
    }
    else if (slave)
    {
        
        // parent side
    }
}