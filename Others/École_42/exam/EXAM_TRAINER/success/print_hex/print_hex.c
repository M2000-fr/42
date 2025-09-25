#include <unistd.h>

unsigned int ft_atoi(char *str)
{
    unsigned int i = 0;
    unsigned int res = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = 10 * res + (str[i] - '0');
        i++;
    }
    return (res);
}

void    ft_putnbr_hexa(unsigned int nbr)
{
    char *c = "0123456789abcdef";
    if (nbr >= 16)
        ft_putnbr_hexa(nbr / 16);
    nbr %= 16;
    write(1, &c[nbr % 16], 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
        ft_putnbr_hexa(ft_atoi(av[1]));
    write(1, "\n", 1);
    return (0);
}