#include <unistd.h>

int main(int ac, char **av)
{
    int i;

    i = 0;
    int result = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            if(av[1][i] >= 'a' && av[1][i] <= 'z')
                result = av[1][i] - 96;
            else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                result = av[1][i] - 64;
            while (result > 1)
            {
                write(1, &av[1][i], 1);
                result--;
            }
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}