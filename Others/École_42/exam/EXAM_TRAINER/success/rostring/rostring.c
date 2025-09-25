#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int start = 0;
    int end = 0;
    int nospace = 0;

    if(argc >= 2)
    {
        while(argv[1][i] != '\0')
        {
            if(argv[1][i] == ' ' || argv[1][i] == '\t')
                nospace = 1;
            i++;
        }
        i = 0;
        if(nospace == 0)
        {
            while(argv[1][i] != '\0')
            {
                write(1, &argv[1][i], 1);
                i++;
            }
            write(1, "\n", 1);
            return(0);
        }
        while(argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        start = i;
        while(argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        end = i;
        while(argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while(argv[1][i] != '\0')
        {
            if((argv[1][i] == ' ' || argv[1][i] == '\t') && (argv[1][i + 1] == ' ' || argv[1][i+1] == '\t'))
                i++;
            else
            {
                write(1, &argv[1][i], 1);
                i++;
            }
        }
        if(argv[1][i-1] != ' ' && argv[1][i-1] != '\t')
            write(1, " ", 1);
        while(start < end)
        {
            write(1, &argv[1][start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
    return(0);
}