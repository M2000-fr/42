#include <unistd.h>

void main(int argc, char **argv)
{
    int i = 1;
    int j =1;

    if(argc > 1)
    {
        while(i <= argc)
        {
            if(argv[i][0] >= 'a' && argv[i][0] <= 'z')
                argv[i][0] -= 32;

            write(1, &argv[i][0], 1);
            while(argv[i][j])
            {
                if(argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                    argv[i][j] += 32;
                if((argv[i][j] >= 'a' && argv[i][j] <= 'z') && (argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t'))
                    argv[i][j] -= 32;
                write(1, &argv[i][j], 1);
                j++;
            }
            write(1, "\n", 1);
            j=1;
            i++;
        }
    }
    else
        write(1, "\n", 1);
}