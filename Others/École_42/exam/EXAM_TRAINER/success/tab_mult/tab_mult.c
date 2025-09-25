#include <unistd.h>

void ft_putnbr(int n)
{
    char c;

    if(n >= 10)
    {
        ft_putnbr(n / 10);
        c = n % 10 + '0';
    }
    else
        c = n + '0';
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int ret = 0;

    while(str[i] != '\0')
    {
        ret = ret * 10 + str[i] -'0';
        i++;
    }
    return(ret);
}

int main(int argc, char **argv)
{
    int i = 1;
    if(argc ==2)
    {
        if(argv[1][0] == '\0')
        {
            write(1, "\n", 1);
            return(0);
        
        }
        int arg = ft_atoi(argv[1]);
        while(i < 10)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(arg);
            write(1, " = ", 3);
            ft_putnbr( i * arg);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}