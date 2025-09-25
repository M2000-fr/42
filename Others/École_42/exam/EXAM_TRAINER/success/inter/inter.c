#include <unistd.h>

int inter(char c, char *av, int size)
{
    int i;

    i = 0;
    while (av[i] && (i < size || size == -1))
    {
        if (av[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 3)
    {
        while (av[1][i])
        {
            if (!inter(av[1][i], av[1], i) && inter(av[1][i], av[2], -1))
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}