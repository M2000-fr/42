#include<unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}


int isword(char *str)
{
    int i =0;

    while(str[i] != '\0')
    {
        if(str[i] != ' ' || str[i] != '\t')
            return(1);
        i++;
    }
    return(0);
}

int main(int argc, char **argv)
{
    int i = 0;

    if(argc == 2)
    {
        if(isword(argv[1]) == 0)
        {
            write(1, "\n", 1);
            return(0);
        }

        while(argv[1][i] == ' ' || argv[1][i] == '\t')
        {
            i++;
        }
        
        while(argv[1][i] != '\0')
        {
            while((argv[1][i] == ' ' || argv[1][i] == '\t') && (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\t'))
            {
                i++;
            }
            if((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i + 1] != '\0')
            {
                write(1, "   ", 3);
            }
            else if((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i + 1] == '\0')
            {
                break;
            }
            else
                ft_putchar(argv[1][i] );

            i++;
        }
    }
    write(1, "\n", 1);

}