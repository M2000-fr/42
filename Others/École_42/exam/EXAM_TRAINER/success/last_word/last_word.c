#include <unistd.h>

void ft_putchar(char chr)
{
    write(1, &chr, 1);
       
}

int main(int argc, char **argv)
{
    int i = 0;
    int word = 0;
    int last = 0;

    if(argc == 2 && argv[1][0] != '\0')
    {
        while(argv[1][i] != '\0')
        {
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z' || argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                word++;
            i++;
        }
        if(word == 0)
        {
            write(1, "\n", 1);
            return(0);
        }
        ///////////////////////////////
        i = 0;
        while(argv[1][i] != '\0')
        {
            if((argv[1][i + 1] >= 'a' && argv[1][i+1] <= 'z' || argv[1][i+1] >= 'A' && argv[1][i+1] <= 'Z') && (argv[1][i] == ' ' || argv[1][i] == '\t'))
                last = i;
            i++;
        }
        if(last !=0)
            last ++;
        while(argv[1][last] != '\0' && argv[1][last] != ' ' && argv[1][last] != '\t')
        {
            ft_putchar(argv[1][last]);
            last++;
        }
    }
    write(1, "\n", 1);
    return(0);
}