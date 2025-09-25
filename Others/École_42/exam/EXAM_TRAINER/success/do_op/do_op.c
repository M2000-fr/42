#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int i;
    int j;

    if (ac == 4)
    {
        i = atoi(av[1]);
        j = atoi(av[3]);
        if (av[2][0] == '+')
            i = i + j;
        if (av[2][0] == '-')
            i = i - j;
        if (av[2][0] == '*')
            i = i * j;
        if (av[2][0] == '/')
            i = i / j;
        if (av[2][0] == '%')
            i = i % j;
        printf("%d", i);
    }
    printf("\n");
    return (0);
}