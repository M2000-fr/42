#include<unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void main(int argc, char **argv)
{
    int i = 0;

    if(argc == 2)
    {
        while(argv[1][i] != '\0')
        {
            if(argv[1][i] == '_' && (argv[1][i + 1] >= 'a' && argv[1][i] <= 'z'))
            {
                i++;
                argv[1][i] -=32;
            }
            ft_putchar(argv[1][i]);
            i++;
        }
    }
    write(1, "\n", 1);

}