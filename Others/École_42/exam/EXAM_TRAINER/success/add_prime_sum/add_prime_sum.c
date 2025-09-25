#include <unistd.h>

int ft_atoi(char *str)
{
    int res = 0;
    while(*str)
        res = res * 10 + *str++ - '0';
    return(res);
}

void printnum(int n)
{
    char c;

    if(n > 9)
    {
        printnum(n / 10);
        c = n % 10 + '0';
        write(1, &c, 1);
    }
    else
    {
        c = n + '0';
        write(1, &c, 1);
    }
}

int isprime(int num)
{
    int i = 2;

    while(i * i <= num)
    {
        if(num % i == 0)
            return(0);
        i++;
    }
    return(1);
}

int main(int argc, char **argv)
{
    if(argc == 2 && argv[1][0] != '-')
    {
        int num = ft_atoi(argv[1]);
        int i = 2;
        int sum = 0;

        if(num <= 0)
        {
            write(1, "0\n", 2);
            return(0);
        }
        if(num > 0)
        {
            while(i <= num)
            {
                if(isprime(i) == 1)
                    sum += i;
                i++;
            }
            printnum(sum);
            write(1, "\n", 1);
        }
    }
    else
        write(1, "0\n", 2);
}